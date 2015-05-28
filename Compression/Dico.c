#include <stdio.h>
#include <stdlib.h>
#include "Dico.h"

char hexa_to_char(uint64_t n){return n;}

uint64_t char_to_hexa(char c){return c;}

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

void afficher(dictionnaire dico){
	dictionnaire tmp_frere, tmp_fils;
	short int frere;
	
	tmp_frere = dico;
	tmp_fils = dico;
	if(tmp_frere == NULL){
		printf("il n'y a pas de fists! \n");
		return;
	}
	while(tmp_frere != NULL){
		printf("(%jx;%c;%d) ", tmp_frere -> valeur, hexa_to_char(tmp_frere -> valeur), tmp_frere -> caractere);
		tmp_frere = tmp_frere -> frere;
	}
	
	printf("\nnumero du fils (ascii, 2ième coordonnée) : \n");
	scanf("%hd",&frere);
	while(tmp_fils -> caractere != frere){
		tmp_fils = tmp_fils -> frere;
		if(tmp_fils == NULL){
			printf("Ce fist n'existe pas. Gros nul, tu n'a qu'à relancer la fistinière. \n");
			return;
		}	
	}
	
	afficher(tmp_fils -> fils);
}

void parse(char **seq){
	char *seqf;
	seqf = malloc(sizeof(*seq));
	
	int n,i;
	n = strlen(*seq);

	for(i=0;i<n;i++){	
		*(seqf+i) = *(*seq+i+1);
	}
	*seq = seqf; 
}

int recherche_dico(char *sequence, dictionnaire dico){
	dictionnaire temp;
	temp = dico;
	
	uint64_t x; 
	x = char_to_hexa(*sequence);
	
	int n;
	n = strlen(sequence);
	
	//si le dico est vide
	if(temp == NULL){return -1;}
	
	//on regarde les frères
	while(x != temp -> valeur){
		temp = temp -> frere;
		if(temp == NULL){return -1;}
	}
	
	if(n == 1){return 1;}
	else {
		parse(&sequence);
		return recherche_dico(sequence,temp -> fils);
	}		
}

int main(){
	dictionnaire dico= malloc(sizeof(dictionnaire));
	init_dico(dico);
	afficher(dico);

	char * string = "d";
	ajout_dico(string , dico, 460);
	afficher(dico);
	return 0;
}
