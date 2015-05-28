#include <stdio.h>
#include <stdlib.h>
#include "Dico.h"

uint8_t char_to_num(char lettre){
	return lettre + 1;
}

char num_to_char(int nbr){
        return nbr -1;
}



void init_dico(dictionnaire dico){
	noeud * current = dico;

	int i;
	for(i=0; i<100 ; i++){
		(*current).valeur = i;
		(*current).caractere = i;
		(*current).frere = malloc(sizeof(current));
		(*current).fils = NULL;
		current = (*current).frere;
	}
	(*current).frere = NULL;

}
					// ab
void ajout_dico(char * sequence, dictionnaire dico, int code_sequence){
	noeud * current = dico;

	int i=0;
	//tant que la sequence de caractère n'est pas finis
	while(sequence[i] != '\0'){
		//on avance à la lettre voulue chez les freres
		
		while((current != NULL) && ((*current).frere != NULL)){
			if(sequence[i] != (*current).caractere){
				current = (*current).frere;
			}
			else{
				printf("%d\n", (*current).caractere);
				break;
			}
		}
		//Normalement on rentre dans cette condition que lorsque l'on est sur le dernier caractere du mot
		//Ce cas correspond au moment où le frere n'existe pas et où il faut donc le créer
		if(current == NULL){
			current = malloc(sizeof(current));
			(*current).valeur = code_sequence;
			(*current).caractere = i;
			(*current).frere = NULL;
			(*current).fils = NULL;
			//on pourrais mettre un break pour être sûr que ça fonctionne
		}
		printf("%d\n", i);
		current = (*current).fils;
		i++;
	}
}

void affichage(dictionnaire dico){
	noeud * current = dico;

	while((current != NULL)){
		printf("%c;", num_to_char((*current).caractere));
		current = (*current).frere;
	}
	printf("\n");

}




int main(){
	dictionnaire dico= malloc(sizeof(dictionnaire));
	init_dico(dico);
	affichage(dico);

	char * string = "d";
	ajout_dico(string , dico, 460);
	affichage(dico);
	return 0;
}