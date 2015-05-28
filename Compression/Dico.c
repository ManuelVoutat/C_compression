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


//a vérifier que le code appartient au dico
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

int recherche_frere(dictionnaire branche, char seq){
	noeud * current = branche;
	printf("%s\n","****************" );
	if(current != NULL){
		printf("%d\n", (*current).caractere);
		if(seq != (*current).caractere){
			if((*current).frere != NULL){
				recherche_frere((*current).frere, seq);
			}
			else{
				return 0;
			}
		}
		else{
			printf("Le caractere n°%d\n est présent", (*current).caractere);
			return 1;
		}
	}
	return 0;
}


void afficher(dictionnaire dico){
	dictionnaire tmp_frere, tmp_fils;
	int fils;
	
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
	
	printf("\nnumero du fils (ascii, 1ere coordonnée) : \n");
	scanf("%d",&fils);
	while(tmp_fils -> valeur != fils){
		tmp_fils = tmp_fils -> frere;
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
