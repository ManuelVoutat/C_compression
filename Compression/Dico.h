#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint64_t valeur_t; //valeur attribuée (binaire)

typedef short int caractere_t; //valeur caractère (ASCII)


typedef struct _noeud noeud;
struct _noeud {
	valeur_t valeur;
	caractere_t caractere;
	struct _noeud *frere;
	struct _noeud *fils;
};

typedef noeud * dictionnaire;

void init_dico(dictionnaire dico);

void ajout_dico(char * sequence, dictionnaire dico, int code_sequence);

valeur_t recherche_dico(char * sequence, dictionnaire dico);

void afficher(dictionnaire dico);