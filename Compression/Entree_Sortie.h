

#include <stdio.h>
#include <stdlib.h>

FILE* fichier;

bool openFile (); //openFile() retourne false si il 
				  // y a une erreur dans l'ouverture du fichier.
bool closeFile (); //closeFile() retourne false si le fichier n'est pas fermé
int readChar (); //!!!A voir ce qu'on retourne int ou char !!!
				 //On renvoie la valeur en ASCII et 256 pour EOF 