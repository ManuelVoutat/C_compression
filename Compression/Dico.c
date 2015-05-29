#include <stdio.h>
#include <stdlib.h>
#include "Dico.h"

char int_to_char(int n){return n;}

int char_to_int(char c){return c;}

void init_dico(dictionnaire dico){
	noeud * current = dico;

	int N=74;
	int i;
	for(i=60; i < N ; i++){
		(*current).valeur = i;
		(*current).caractere = i;
		(*current).frere = malloc(sizeof(noeud));
		(*current).fils = NULL;
		current = (*current).frere;
	}
	(*current).valeur = N;
	(*current).caractere = N;
	(*current).frere = NULL;
	(*current).fils = NULL;
}

int recherche_frere(dictionnaire * current, char seq){

	if((*current) != NULL){
		while((*current) != NULL){
			//printf("current caractère : %d\n", (*(*current)).caractere);
			if(seq != (*(*current)).caractere){
				if((*(*current)).frere != NULL){
					(*current) = (*(*current)).frere;
				}
				else{
					return 0;
				}
			}
			else{
				//printf("Le caractere n°%d\n est présent\n", (*(*current)).caractere);
				return  1;
			}
		}
		return 0;
	}
	else{
		return -1;
	}
}

void ajout_dico(char * sequence, int N, dictionnaire dico, int code_sequence){
	noeud * current = dico;
	noeud * pere = current;

	int i=0;
	//tant que la sequence de caractère n'est pas finis
	while(i < N){
		//on avance à la lettre voulue chez les freres
		int resultat_de_recherche = recherche_frere(&current, sequence[i]);
		//si le frere n'est pas présent
		if(resultat_de_recherche != 1){
			//branche de frere vide
			if(resultat_de_recherche == -1){
				current = malloc(sizeof(noeud));
				(*pere).fils = current;
			}
			//branche totalement parcourue et ne contient pas le caratere
			else if(resultat_de_recherche == 0){
				(*current).frere = malloc(sizeof(noeud));
				current = (*current).frere;
			}
			(*current).valeur = code_sequence;
			(*current).caractere = char_to_int(sequence[i]);
			(*current).frere = NULL;
			(*current).fils = NULL;
		}
		else{
			pere = current;
			current = (*current).fils;
		}
		i++;
	}
}

//a vérifier si la chaine de caractere est présente
valeur_t caract_to_code (char *sequence, int N, dictionnaire dico){
	noeud * current = dico;

	if(est_dans_dico(sequence, N, current)){
		int i=0;
		//tant que la sequence de caractère n'est pas finis
		while(i < N){
			//on avance à la lettre voulue chez les freres
			int resultat_de_recherche = recherche_frere(&current, sequence[i]);
			//si le frere n'est pas présent
			if(resultat_de_recherche != 1){
				fprintf(stderr, "La sequence n'est pas presente dans le dictionnaire" );
			}
			else{
				i++;
				if(sequence[i] != '\0'){
					current = (*current).fils;
				}
			}
		}
		return (*current).valeur;
	}else{
		fprintf(stderr, "La sequence n'est pas presente dans le dictionnaire" );
		return -1;
	}
}


void afficher(dictionnaire dico){
	dictionnaire tmp_frere, tmp_fils;
	int frere;
	
	tmp_frere = dico;
	tmp_fils = dico;
	if(tmp_frere == NULL){
		printf("il n'y a pas de fils \n");
		return;
	}
	while(tmp_frere != NULL){
		printf("(%d;%c;%d) ", tmp_frere -> valeur, int_to_char(tmp_frere -> caractere), tmp_frere -> caractere);
		tmp_frere = tmp_frere -> frere;
	}
	
	printf("\nnumero du frere dont on veux les fils (ascii, 1ere coordonnée) : \n");
	scanf("%d",&frere);
	while(tmp_fils -> valeur != frere){
		tmp_fils = tmp_fils -> frere;
		if(tmp_fils == NULL){
			printf("Ce frere n'existe pas \n");
			return;
		}	
	}
	
	afficher(tmp_fils -> fils);
}


int est_dans_dico(char *sequence, int N, dictionnaire dico){
	noeud * current = dico;

	int i=0;
	//tant que la sequence de caractère n'est pas finis
	while(i < N){
		//on avance à la lettre voulue chez les freres
		int resultat_de_recherche = recherche_frere(&current, sequence[i]);
		//si le frere n'est pas présent
		if(resultat_de_recherche != 1){
			return 0;
		}
		else{
			current = (*current).fils;
		}
		i++;
	}
	return 1;	
}