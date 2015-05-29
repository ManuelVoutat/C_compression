#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DicoDecompresse.h"

char int_to_char(int n){return n;}

int char_to_int(char c){return c;}

void init_dicodecompress (char * tab){
	int i;
	for(i=0;i<N;i++){
		if(i<255){
			tab[i] = int_to_char(i);
		}else{
			tab[i] = ' ';
		}
	}
}

void affichage_dicodecompress(char * tab){
	int i;
	for (i = 0; i<N; i++){
		printf("%d ",i);
		printf("%c;", tab[i]);
	}
}

void ajout_dicodecompress(){



}

int main(){
	char tab[N];
	init_dicodecompress(tab);
	affichage_dicodecompress(tab);
	return 0;
}

int est_dans_tab(char *tab[N], int N, char *val){
	int trouve = 0;
	int i = 0;
	
	if(strlen(val) > 2){
		i = 255;
	} 
	
	while(i<N){
		if(tab[i] == val){
			return 1;
		}else{
			i++;
		}
		return -1;
	} 
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
