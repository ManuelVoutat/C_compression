#include <stdlib.h>
#include <stdio.h>

#include "Compression.h"
#include "Dico.h"
#include "Entree_Sortie.h"

int main (int argc, char *argv[])
{
	FILE* fichier_a_compresser = openFile(argv[1], "rb");
	FILE* fichier_de_sortie = openFile(argv[2],"wb");
 	Compression(fichier_a_compresser, fichier_de_sortie);
	
	int close = closeFile(fichier_a_compresser);
	int close2 = closeFile(fichier_de_sortie);
	return 0;
}
