#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int valeur_t; //valeur attribuée (binaire)

typedef int caractere_t; //valeur caractère (ASCII)

typedef struct _noeud noeud;
struct _noeud {
	valeur_t valeur;
	caractere_t caractere;
	struct _noeud *frere;
	struct _noeud *fils;
	struct _noeud *pere;
};

typedef noeud * dictionnaire;

char int_to_char(int n);

int char_to_hexa(char c);

void init_dico(dictionnaire dico);

int recherche_frere(dictionnaire branche, char seq);

void ajout_dico(char * sequence, dictionnaire dico, int code_sequence);

int est_dans_dico(char * sequence, dictionnaire dico);

void parse(char **seq);

valeur_t caract_to_code (char *sequence, dictionnaire dico);

void afficher(dictionnaire dico);
