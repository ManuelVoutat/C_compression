#include "Compression.h"




int tableau_temporaire[taille_tab]; //AMELIORATION POSSIBLE : Utiliser une succéssion de pointeur afin d'optimiser la place.

void initialise_tab_temp(){
	int i;
	for(i=0; i<taille_tab ; i++){
		tableau_temporaire[i] = -1;
	}
}



void insere_dans_tab_temp(int caractere){
	int i = 0;
	while(tableau_temporaire[i]>0){
		i++;
	}
	
	tableau_temporaire[i] = caractere;
}

char* concatene_caracteres_de_tab_temp(){
	int i=0;
	char* chaine = NULL;
	while(tableau_temporaire[i]>0){
		chaine += tableau_temporaire[i];
		i++;
	}
}

void ecriture_sortie(int code_du_dico, FILE* fichier_a_compresser){
	int caractere_lu = 0;
	 
	while(caractere_lu != 256){ // car 256 correspond à EOF
		caractere_lu = readChar(fichier_a_compresser);
		printf("%d ", caractere_lu);
	}
}
void restart(){

}


