/*Fichier entrée/sortie*/


#include "Entree_Sortie.h"


//Ouvrir/Fermer fichier
FILE* fichier = NULL;

int openFile (char* name)
{
	
	fichier = fopen (name, "rb"); // "rb" correspond à "read binary"

	if(NULL == fichier) //On part sur un fichier binaire
	{
		printf("Erreur on ne peut pas l'ouvrir\n");
		return 0;
	}
	else
		return 1;
}

int closeFile ()
{
	int succes = 0;

	succes = fclose (fichier);

	if(succes == 0)
	{
		printf("Le fichier n'est pas fermé correctement\n");
		return 0;
	}
	else
		return 1;
}

//Lire et passer char 

int readChar () //On lit un octet (8bit) que l'on convertit en décimal
{
	int caractere;
	int i,decimal=0;

	caractere = fgetc(fichier);
	if (caractere == EOF){	//Dans le cas ou on est à EOF,nus retournons 256
		return 256;
	}

	return caractere;
}










