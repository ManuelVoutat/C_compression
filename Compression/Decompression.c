#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 512

char int_to_char(int n){return n;}

int char_to_int(char c){return c;}

void init_dicodecompress ( char* tab[N]){
	int i;
	for(i=0;i<255;i++){
		*tab[i]= int_to_char(i);}
}


void Decompression(FILE* fichier_in){


	int caractere_a_decompresser;
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
/*
int main (int argc, char *argv[])
{
FILE * fichier = NULL;
char* T[N];
char* w1;
char w2;
char c
if(argc == 1){
		fichier = stdin;}//Pour arrêter : Ctrl+D
	else{
		fichier = fopen(argv[1],"r");}

	while (!feof(fichier) )// tant qu'on est pas à la fin du fichier 
	{
		c = getchar();
		
	}
	fclose(fichier);
	printf("\n\n");
return 0;
}

*/
