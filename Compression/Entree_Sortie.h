
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

FILE* fichier;	//A mettre dans openFile

FILE* openFile (char* name, char* lecture_ecriture); //openFile() retourne 0 si il y a une erreur dans l'ouverture du fichier.
int closeFile (FILE* fichier); //closeFile() retourne 0 si le fichier n'est pas fermé
int readChar (FILE* fichier); 
		//On renvoie la valeur en ASCII et 256 pour EOF 
void ecriture_sortie_en_bit(uint32_t bits_a_ecrire);
