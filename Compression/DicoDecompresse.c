#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DicoDecompresse.h"

char int_to_char(int n){return n;}

int char_to_int(char c){return c;}

void init_dicodecompress (char ** tab, int taille){
	int i;
	printf("ok");
	for(i=0;i<taille;i++){
		if(i<255){
			//printf("%s\n",tab[i]);
			*tab[i] = int_to_char(i);
		}else{
			//printf("%s\n",tab[i]);
			*tab[i] = ' ';
		}
	}
}

void affichage_dicodecompress(char * tab[], int taille){
	int i;
	for (i = 0; i<taille; i++){
		if((i != 32) && (*tab[i] != ' ')){
			printf("%d ",i);
			printf("%s;", tab[i]);
		}
	}
}

void ajout_dicodecompress(char * tab[], int taille, char * seq){
	int i=260;
	while(*tab[i] != ' '){
		if(i<taille){
			i++;
		}
		else{
			printf("On realloue de la mémoire au tableau");
		}
	}
	tab[i] = seq;
}

int main(){
	int taille = 500;
	char ** tab = malloc(sizeof(char **));
	init_dicodecompress(tab, taille);
	//affichage_dicodecompress(tab, taille);
	//ajout_dicodecompress(tab, taille, "seq");
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
