#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DicoDecompresse.h"

char int_to_char(int n){return n;}

char* int_to_string(int n){
	char *tab = (char*) malloc(sizeof(char));
	tab[0]=int_to_char(n);
	return tab;
}

int char_to_int(char c){return c;}

void init_dicodecompress (char * tab[], int taille){
	int i;
	printf("Init");
	for(i=0;i<taille;i++){
		if(i<255){
			tab[i] = int_to_string(i);
		}else{
			tab[i] = " ";
		}
	}
}

void affichage_dicodecompress(char * tab[], int taille){
	int i;
	for (i = 0; i<taille; i++){
		if(strcmp(tab[i]," ")){
			printf("%d %s;", i, tab[i]);
		}
	}
}

int est_dans_dico(char * tab[], int taille, char * seq){
	if(tab[
}

void ajout_dicodecompress(char * tab[], int taille, char * seq){
	int i=260;
	while(strcmp(tab[i]," ")){
		if(i<taille){
			i++;
		}
		else{
			printf("On realloue de la mémoire au tableau");
		}
	}
	tab[i] = seq;
	printf("string : %s\n",tab[i]);
	printf("carac : %c\n",*tab[i]);
}

int main(){
	int taille = 500;
	char * tab[500];
	init_dicodecompress(tab, taille);
	//affichage_dicodecompress(tab, taille);
	ajout_dicodecompress(tab, taille, " Jesuis");
	//affichage_dicodecompress(tab, taille);
	ajout_dicodecompress(tab, taille, " un prout");
	affichage_dicodecompress(tab, taille);
	return 0;
}

/*int est_dans_tab(char * tab, int taille, char * val){
	int i = 0;
	
	if(strlen(val) > 2){
		i = 255;
	} 
	
	while(i<taille){
		if(*tab[i] == val){
			return 1;
		}else{
			i++;
		}
		return -1;
	}
	return 0;
}*/

  
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
