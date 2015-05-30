#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 512

char int_to_char(int n){return n;}

int char_to_int(char c){return c;}

void init_dicodecompress ( char* tab[N]){
	int i;
	for(i=0;i<255;i++){
		*tab[i]= int_to_char(i);}
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
