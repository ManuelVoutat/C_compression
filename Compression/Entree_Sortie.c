/*Fichier entrée/sortie*/


#include "Entree_Sortie.h"


//Ouvrir/Fermer fichier
FILE* fichier = NULL;	//A mettre dans openFile

FILE* openFile (char* name)
{
	
	fichier = fopen (name, "rb"); // "rb" correspond à "read binary"

	if(NULL == fichier) //On part sur un fichier binaire
	{
		printf("Erreur on ne peut pas l'ouvrir\n");
		return fichier;
	}
	else
		return fichier;
}

int closeFile (FILE* fichier)
{
	int succes = 0;

	succes = fclose (fichier);

	if(succes != 0)
	{
		printf("Le fichier n'est pas fermé correctement\n");
		return 0;
	}
	else
		return 1;
}

//Lire et passer char 

int readChar (FILE* fichier) //On lit un octet (8bit) que l'on convertit en décimal
{
	int i,decimal=0;

	decimal = fgetc(fichier);
	if (decimal == EOF){	//Dans le cas ou on est à EOF,nous retournons 256
		return 256;
	}
	return decimal;
}


void ecriture_sortie_en_bit(uint32_t bits_a_ecrire)//On écrit 8 bits par 8 bits dans le fichier de sortie
{
	
	//printf("%d ",code_du_dico);


}










