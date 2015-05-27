/*Fichier entrée/sortie*/


#include "Entree_Sortie.h"


//Ouvrir/Fermer fichier
FILE* fichier = NULL;

int openFile ()
{
	char* name;



	printf("Quel fichier binaire voulez vous compresser ?\n");
	scanf ("%s", name);
	fichier = fopen (name, "rb");

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
	int i,decimal;

	for(i=0; i<8; i++)
	{
		caractere = fgetc(fichier);
		if (caractere == EOF)			//Dans le cas ou on est à EOF,nus retournons 256
			return 256;
		decimal = caractere * 2^(7-i) + decimal;

	}

	return decimal;
}









