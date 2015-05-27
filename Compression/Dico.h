#include <stdio.h>

typedef uint64_t valeur_t; //valeur attribuée (binaire)

typedef short int caractere_t; //valeur caractère (ASCII)

typedef noeud * dico;


typedef struct _noeud noeud;
struct _noeud {
	valeur_t valeur;
	caractere_t caractere;
	struct _noeud *frere;
	struct _noeud *fils;
};

void init_dico(dico racine);

void ajout_dico(char * sequence, valeur_t valeur, dico racine);

valeur_t recherche_dico(char * sequence, dico racine);
