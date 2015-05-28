#include "Entree_Sortie.h"
#include "Compression.h"

int main (int argc, char *argv[]){ // argc permet de connaitre le nombre d'argument apporté après ./main. Si argc=1 alors il n'y a pas d'argument
	FILE* fichier_a_compresser = openFile(argv[1]);

	
	ecriture_sortie(0, fichier_a_compresser);
	
	int close = closeFile(fichier_a_compresser);

	
	
}
