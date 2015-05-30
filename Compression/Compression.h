#define Taille_tab 200
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>




void initialise_tab_temp(int* tableau_temporaire);

uint32_t int_to_uint32(int n);

void insere_dans_tab_temp(int caractere, int* tableau_temporaire);

char* concatene_caracteres_de_tab_temp(int tableau_temporaire[], int* taille); /* permet de concatener les caractères dans le tableau temporaire: exemple: 
							|a|b|c|  -> "abc"   */

int exclusion_du_dernier_element(int* tableau_temporaire);

int restart(int* tableau_temporaire, int caractere_save); //Restart() permet de vider le tableau temporaire et de mettre en première position le dernier élement précedent. Et on renvoie l'indice de cet élément.

void tampon_ecriture(uint32_t bit_a_ecrire, int taille_code);

void Compression(FILE* fichier_in); //On compresse le fichier (transparent pour utilisateur)
