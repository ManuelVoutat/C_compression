#include <stdio.h>

typedef uint64_t valeur_t; //valeur attribuée (binaire)

typedef short int caractere_t; //valeur caractère (ASCII)

typedef struct _noeud noeud;
struct _noeud {
	valeur_t valeur;
	caractere_t caractere;
	struct _noeud *frere;
	struct _noeud *fils;
}

void ajout_dico(string sequence, valeur_t valeur, noeud * racine);
valeur_t recherche_dico(string sequence, noeud * racine);
