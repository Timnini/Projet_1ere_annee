// fichier qui regroupe toutes les fonctions du fichier "plateau.c"
// Il est regroupé ici toutes les fonctions qui gère le plateau et ses fonctionnalités
// Fonctions qui gèrent l'affichage du plateau   (plateau.h)

void createTableau(char **tableau);

void printTableau(char **tableau);

void shuffleCards(char **cartes);

void tresor(char **cartes);

char monstres();

void createcartes(char **cartes);

// Fonctionnalités des éléments (plateau.c)

void revelationtotem(char **tableau, char **cartes, int *x, int *y);

void changementprotail(char **tableau, char **cartes, int *x1, int *y1);