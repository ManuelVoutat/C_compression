#include "Compression.h"
#include "Entree_Sortie.h"
#include "Dico.h"


void initialise_tab_temp(int* tableau_temporaire){
	int i;
	for(i=0; i < Taille_tab; i++){
		tableau_temporaire[i] = -1;
	}
}
	//afficher(dico);

uint32_t int_to_uint32(int n){return n;}

void insere_dans_tab_temp(int caractere, int* tableau_temporaire){
	int i = 0;
	while(tableau_temporaire[i]>0){
		i++;
	}
	
	tableau_temporaire[i] = caractere;
}

char* concatene_caracteres_de_tab_temp(int tableau_temporaire[], int* taille){
	int n = 0;
	int i;

	while(tableau_temporaire[n]>=0){
		n++;
	}
	char *tableau_concatenation = (char*) calloc(n, sizeof(char)); //Déclaration tableau concatené 
	for (i=0; i<n; i++)
	{
		tableau_concatenation[i] = (char)tableau_temporaire[i];
	}
	*taille = n;
	return tableau_concatenation;
}

int exclusion_du_dernier_element (int* tableau_temporaire)
{
	int i=0;
	int save;
	while(tableau_temporaire[i]>=0){
		i++;
	}
	save = tableau_temporaire[i-1];
	tableau_temporaire[i-1] = -1;
	return save;
}

int restart(int* tableau_temporaire, int caractere_save){	//On réinitialise le tab en sauvegardant la dernière valeur.
	
	initialise_tab_temp(tableau_temporaire);
	//tableau_temporaire[0] = caractere_save;
}

void tampon_ecriture(uint32_t bit_a_ecrire, int taille_code)
{
	printf("%#X\n",bit_a_ecrire);

}



void Compression(FILE* fichier_in){


	int caractere_a_compresser;
	int code_caractere;
	uint32_t bit_a_ecrire;
	dictionnaire dico = malloc(sizeof(dictionnaire));
	int tableau_temporaire[Taille_tab]; //AMELIORATION POSSIBLE : Utiliser une succéssion de pointeur afin d'optimiser la place.
	char* sequence;
	int taille_sequence;
	int caractere_save;
	int code_seq=260;
	int taille_code=9;
	int present_dico;
	int i;


	init_dico(dico);
	initialise_tab_temp(tableau_temporaire);

	caractere_a_compresser = readChar(fichier_in);

	while (caractere_a_compresser != 256)
	{


		insere_dans_tab_temp(caractere_a_compresser, tableau_temporaire);
		sequence = concatene_caracteres_de_tab_temp(tableau_temporaire, &taille_sequence);
		printf("%s\n",sequence );

		if(!est_dans_dico(sequence, taille_sequence, dico))//Si la sequence n'estpas dans le dico
		{

			printf("ajout de la séquence dans le dico\n");
			ajout_dico(sequence, taille_sequence, dico, code_seq);
			code_seq++;
		
			caractere_save = exclusion_du_dernier_element(tableau_temporaire);
			taille_sequence = taille_sequence - 1; //La taille de la séquence a perdu un élément
			sequence = concatene_caracteres_de_tab_temp(tableau_temporaire, &taille_sequence);

			
			code_caractere = caract_to_code(sequence, taille_sequence, dico); //recherche code caractere dans dico
			bit_a_ecrire = int_to_uint32(code_caractere);
			printf("On code %d dans le fichier\n", code_caractere );

			//printf("%#X\n", bit_a_ecrire);
			//tampon_ecriture(bit_a_ecrire, taille_code);

			restart(tableau_temporaire, caractere_save);
			caractere_a_compresser = caractere_save;
		}
		//else if (compression_fini == 1) /*&& tableau_temporaire[0] != -1*/
		//{
			
			//printf("%d\n", caractere_a_compresser);
			//printf("%d\n", compression_fini);
			//caractere_a_compresser = 256;

			//printf("%d\n", tableau_temporaire[0]);
			//printf("%d\n", code_caractere);
		//}
		else
		{
			caractere_a_compresser = readChar(fichier_in);
			if (caractere_a_compresser == 256)
			{
				sequence = concatene_caracteres_de_tab_temp(tableau_temporaire, &taille_sequence);
				code_caractere = caract_to_code (sequence, taille_sequence, dico); //recherche code caractere dans dico
				bit_a_ecrire = int_to_uint32(code_caractere);
				printf("On code %d dans le fichier\n", code_caractere );
			}
		}
	}
	bit_a_ecrire = int_to_uint32(caractere_a_compresser);
	printf("On code %d dans le fichier\n", caractere_a_compresser );

	//ecriture_sortie(bit_a_ecrire); //fonction a modifier
	//afficher(dico);
}