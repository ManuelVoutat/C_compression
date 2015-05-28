

#include <stdio.h>
#include <stdlib.h>
#include "Compression.h"

FILE* fichier;

FILE* openFile (char* name); //openFile() retourne 0 si il y a une erreur dans l'ouverture du fichier.
int closeFile (FILE* fichier); //closeFile() retourne 0 si le fichier n'est pas fermé
int readChar (FILE* fichier); 
		//On renvoie la valeur en ASCII et 256 pour EOF 

