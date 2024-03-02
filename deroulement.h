// fichier header qui regroupe toutes les fonctions de "deroulement.c"
// Ce sont toutes les fonctions qui permettent le déroulement du jeu



int choisir_arme();

int bloque(int *x,int *y,char **tableau);

int position(int *x, int *y,char **tableau);

void revelation(char **tableau, char **cartes, int *x, int *y, int choix,
                int *xr, int *yr,int *r);

void retourner(char **tableau);

void changement(char **tableau, char **cartes, int *x1, int *y1, int choix);

int condition(char **tableau, char **cartes, int arme, int choix, int *x1,int *y1, int *xr, int *yr,int *m,int *e,int *t,int n);

void cvictoire(char **cartes, int n, int *x, int *y, int *e,int *t);


