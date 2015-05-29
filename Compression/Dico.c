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
		(*current).pere = NULL;
		current = (*current).frere;
	}
	(*current).valeur = N;
	(*current).caractere = N;
	(*current).frere = NULL;
	(*current).fils = NULL;
	(*current).pere = NULL;

}

int recherche_frere(dictionnaire * current, char seq){

	if((*current) != NULL){
		while((*current) != NULL){
			printf("current caractère : %d\n", (*(*current)).caractere);
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

void ajout_dico(char * sequence, dictionnaire dico, int code_sequence){
	noeud * current = dico;
	noeud * pere = current;

	int i=0;
	//tant que la sequence de caractère n'est pas finis
	while(sequence[i] != '\0'){
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
			(*current).pere = NULL;
		}
		else{
			pere = current;
			current = (*current).fils;
		}
		i++;
	}
}

//a vérifier si la chaine de caractere est présente
valeur_t caract_to_code (char *sequence, dictionnaire dico){
	int N,x;
	dictionnaire temp;
	
	temp = dico;
	N = strlen(sequence);
	x = char_to_int(*sequence);
	
	while( x != temp -> caractere){
		temp = temp -> frere;
	}
	
	if (N==1){
		return temp -> valeur;
	}else{
		parse(&sequence);
		return caract_to_code(sequence, temp -> fils);
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
		printf("%d\n",tmp_fils -> valeur );
		if(tmp_fils == NULL){
			printf("Ce frere n'existe pas \n");
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

int est_dans_dico(char *sequence, dictionnaire dico){
	dictionnaire temp;
	temp = dico;
	
	int x; 
	x = char_to_int(*sequence);
	
	int n;
	n = strlen(sequence);
	
	//si le dico est vide
	if(temp == NULL){return 0;}
	
	//on regarde les frères
	while(x != temp -> valeur){
		temp = temp -> frere;
		if(temp == NULL){return 0;}
	}
	
	if(n == 1){return 1;}
	else {
		parse(&sequence);
		return est_dans_dico(sequence,temp -> fils);
	}		
}
