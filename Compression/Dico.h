#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*valeur que l'on attribue à un caractère ou une chaine de caractère*/
typedef int valeur_t;

/*valeur du caractere en ASCII*/
typedef int caractere_t;

/*structure du dictionnaire
frere : caractere a coté d'un autre caractere
fils : suite de la chaine de caractere du frere 
*/
typedef struct _noeud noeud;
struct _noeud {
	valeur_t valeur;
	caractere_t caractere;
	struct _noeud *frere;
	struct _noeud *fils;
	struct _noeud *pere;
};

typedef noeud * dictionnaire;

/*permet de convertir un la valeur du caractere en type caractere*/
char int_to_char(int n);

/*permet de convertir un type caractere en sa valeur interger*/
int char_to_hexa(char c);

/*initialise le dictionnaire, met les 255 caracteres de la table ASCII en frere. La valeur attribuée est egale à la valeur du caractere*/
void init_dico(dictionnaire dico);

/*prend une chaine de caractere en argument et modifie la chaine de tel sorte que la chaine est la même sans le premier caractere*/
void parse(char **seq);

/*renvoie la valeur ou le code que l'on a attribué a une chaine de caractere pris en argurment d'après le dictionnaire
attention : vérifier si la chaine existe avant utilisation de la fonction (sinon core dumped)
*/
valeur_t caract_to_code (char *sequence, dictionnaire dico);

/*renvoie 1 si la chaine de caractere est présente dans le dico sinon 0*/
int est_dans_dico(char * sequence, dictionnaire dico);

/*dans une ligne de frere, recherche si le caractere pris en argument est present ou pas*/
int recherche_frere(dictionnaire * current, char seq);

/*ajoute une chaine de caractere pris en argument dans le dictionnaire*/
void ajout_dico(char * sequence, dictionnaire dico, int code_sequence);

/*affiche dictionnaire*/
void afficher(dictionnaire dico);
