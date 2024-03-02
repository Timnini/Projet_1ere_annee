#include <stdio.h>
// fichier header qui regroupe toutes les fonctions de "introduction.c"
// Il est regroupé ici toutes les fonctions antérieur au jeu
// Structures et fonctions : introduction et gestion de joueurs (introduction.c)


typedef struct {
  char pseudo[50];
} infojoueur;


int nombjoueurs();

infojoueur saisir_personne();

int introduction(int nbj, infojoueur *guerrier, infojoueur *ranger,
                 infojoueur *magicien, infojoueur *voleur,FILE *fichier);


