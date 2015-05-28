

#include <stdio.h>
#include <stdlib.h>

FILE* fichier;

int openFile (char* name); //openFile() retourne 0 si il y a une erreur dans l'ouverture du fichier.
int closeFile (); //closeFile() retourne 0 si le fichier n'est pas fermé
int readChar (); 
		//On renvoie la valeur en ASCII et 256 pour EOF 
