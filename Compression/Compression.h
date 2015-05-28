#define taille_tab 200
#include <stdio.h>


int tableau_temporaire[200]; //AMELIORATION POSSIBLE : Utiliser une succéssion de pointeur afin d'optimiser la place.

void initialise_tab_temp();

void insere_dans_tab_temp(int caractere);

char* concatene_caracteres_de_tab_temp(); /* permet de concatener les caractères dans le tableau temporaire: exemple: 
							|a|b|c|  -> "abc"   */

void ecriture_sortie(int code_du_dico,FILE* fichier_a_compresser);

void restart(); //Restart() permet de vider le tableau temporaire et de mettre en première position le dernier élement précedent.


