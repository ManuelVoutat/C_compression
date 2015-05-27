/*Fichier entrée/sortie*/

#include <stdio.h>
#include "Entree_Sortie.h"


//Ouvrir/Fermer fichier


void openFile ()
{
	string FILE;

	printf("Quel fichier binaire voulez vous compresser ?\n");
	scanf ("%s", FILE);
	fopen (FILE, rb);
}


//Lire et passer char 