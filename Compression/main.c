#include "Entree_Sortie.h"

int main (int argc, char *argv[]){ // argc permet de connaitre le nombre d'argument apporté après ./main. Si argc=1 alors il n'y a pas d'argument
	int open = openFile(argv[1]);
	int caractere_lu = 0; 
	
	while(caractere_lu != 256){ // car 256 correspond à EOF
		caractere_lu = readChar();
		printf("%d\n", caractere_lu);
		/*
		
		COMPRESSION();
		
		DECOMPRESSION();
		
		
		
		*/
	}
	
	int close = closeFile();
	
	
}
