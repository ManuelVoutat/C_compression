#include <stdlib.h>
#include <stdio.h>

#include "Compression.h"
#include "Dico.h"
#include "Entree_Sortie.h"

int main (int argc, char *argv[])
{
	FILE* fichier_a_compresser = openFile(argv[1]);
 	Compression(fichier_a_compresser);
	
	int close = closeFile(fichier_a_compresser);
	return 0;
}
