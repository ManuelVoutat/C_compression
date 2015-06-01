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

uint32_t int_to_uint32(int n){
	
	return n;
}

int uint32_to_int(uint32_t n){
	
	return n;
}

uint32_t rempli_un_32b(uint32_t sequence_a_add, uint32_t _32b, int * nbr_bit_code, int taille_bit, FILE* fichier_out){
	uint32_t sequence_coupe = 0;
	uint32_t sequence_a_add_temp = sequence_a_add;
	//printf("%#X\n",sequence_a_add);
	int decalage = ((32-*nbr_bit_code)-taille_bit);
	if(decalage<0){
		sequence_coupe = sequence_a_add >> (taille_bit-(32-*nbr_bit_code));
		//printf("sequence_coupe : %#X\n",sequence_coupe);
		_32b = _32b | sequence_coupe;
		//printf("Voici le uint32_t que l'on code : %#X\n",_32b);
		fprintf(fichier_out, "%x",_32b);
		_32b = 0;
		sequence_a_add = sequence_a_add << ((32-*nbr_bit_code)-taille_bit);
		_32b = _32b | sequence_a_add;
		
		*nbr_bit_code = (taille_bit -(32-*nbr_bit_code));
		
	}
	else{
		sequence_a_add = sequence_a_add << ((32-*nbr_bit_code)-taille_bit);
		_32b = _32b | sequence_a_add;
		
		*nbr_bit_code += taille_bit;
	}
	
	if(256 == uint32_to_int(sequence_a_add_temp)){
	//printf("Voici le uint32_t que l'on code : %#X\n",_32b);
	fprintf(fichier_out, "%x",_32b);
	}
	

	return _32b;
}

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




void Compression(FILE* fichier_in, FILE* fichier_out){


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

	//variable pour le codage des sequences en bits
	uint32_t _32b = 0;
	int nbr_bit_code=0;
	int taille_bit = 9;	
	int augmente_taille = 511;
	init_dico(dico);
	initialise_tab_temp(tableau_temporaire);

	caractere_a_compresser = readChar(fichier_in);

	while (caractere_a_compresser != 256)
	{


		insere_dans_tab_temp(caractere_a_compresser, tableau_temporaire);
		sequence = concatene_caracteres_de_tab_temp(tableau_temporaire, &taille_sequence);
		//printf("%s\n",sequence );

		if(!est_dans_dico(sequence, taille_sequence, dico))//Si la sequence n'estpas dans le dico
		{

			//printf("ajout de la séquence dans le dico\n");
			ajout_dico(sequence, taille_sequence, dico, code_seq);
			code_seq++;

		
			caractere_save = exclusion_du_dernier_element(tableau_temporaire);
			taille_sequence = taille_sequence - 1; //La taille de la séquence a perdu un élément
			sequence = concatene_caracteres_de_tab_temp(tableau_temporaire, &taille_sequence);

			//On code en uint_32 dans le fichier de sortie
			code_caractere = caract_to_code(sequence, taille_sequence, dico); //recherche code caractere dans dico
			bit_a_ecrire = int_to_uint32(code_caractere);
			//printf("On code %d dans le fichier\n", code_caractere );

			_32b = rempli_un_32b( bit_a_ecrire, _32b , &nbr_bit_code, taille_bit, fichier_out);
			//printf("le unint_32 à coder : %#X\n",_32b);
			
			if(code_seq == augmente_taille){ // Ce if est utile lorsque l'on passe de 9 à 10 bits.

				bit_a_ecrire = int_to_uint32(258);
				//printf("On code %d dans le fichier\n", 258);
				
				_32b = rempli_un_32b( bit_a_ecrire, _32b, &nbr_bit_code, taille_bit, fichier_out);
				//printf("le unint_32 à coder: %#X\n",_32b);
				taille_bit = ++;
				augmente_taille++;
				augmente_taille = augmente_taille*2;
				augmente_taille--;

			}
			restart(tableau_temporaire, caractere_save);
			caractere_a_compresser = caractere_save;
		}
		
		else
		{
			caractere_a_compresser = readChar(fichier_in);
			if (caractere_a_compresser == 256)
			{
				sequence = concatene_caracteres_de_tab_temp(tableau_temporaire, &taille_sequence);
				code_caractere = caract_to_code (sequence, taille_sequence, dico); //recherche code caractere dans dico
				bit_a_ecrire = int_to_uint32(code_caractere);
				//printf("On code %d dans le fichier\n", code_caractere );
				_32b = rempli_un_32b( bit_a_ecrire, _32b , &nbr_bit_code, taille_bit, fichier_out);
				//printf("le unint_32 à coder : %#X\n",_32b);

			}
		}
	}
	bit_a_ecrire = int_to_uint32(caractere_a_compresser);
	//printf("On code %d dans le fichier\n", caractere_a_compresser );
	_32b = rempli_un_32b( bit_a_ecrire, _32b , &nbr_bit_code, taille_bit, fichier_out);
	//printf("le unint_32 à coder : %#X\n",_32b);


}
