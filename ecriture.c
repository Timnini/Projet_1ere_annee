#include "ecriture.h"
#include <stdlib.h>

  

void ecriture(infojoueur *a, infojoueur *b, infojoueur *c, infojoueur *d,
              int *m1, int *m2, int *m3, int *m4, int *r1, int *r2, int *r3,
              int *r4,int *t1,int *t2,int *t3,int *t4,int *e1,int *e2,int *e3,int *e4,int gagnant, FILE *fichier) {

  int v1,v2,v3,v4;

  v1 = 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;

  switch(gagnant){
    case 1:
    v1 = 1;
    break;
    case 2:
    v2 = 1;
    break;
    case 3:
    v3 = 1;
    break;
    case 4:
    v4= 1;
    break;
  }

  fichier = fopen("texte.txt", "a"); // on ouvre le fichier avec le curseur à la fin du dernier caractère
  fputs("-------------------* Résulats *-------------------------------------------------------\n\n", fichier);
  fprintf(fichier, "pseudo     monsters killed      card    tresor equipment   winner \n\n");
  fprintf(fichier, "   %s              %d            %d        %d     %d        %d\n\n", a->pseudo, *m1, *r1,*t1,*e1,v1); // on affiche toutes les données du joueur 1
  fprintf(fichier, "   %s              %d            %d        %d     %d        %d\n\n", b->pseudo,*m2, *r2,*t2,*e2,v2);  // on affiche toutes les données du joueur 2
  fprintf(fichier, "   %s              %d            %d        %d     %d        %d\n\n", c->pseudo,
          *m3, *r3,*t3,*e3,v3);  // on affiche toutes les données du joueur 3
  
  fprintf(fichier, "   %s              %d            %d        %d    %d        %d\n\n", d->pseudo,*m4, *r4,*t4,*e4,v4);  // on affiche toutes les données du joueur 4
  fprintf(fichier, "---------------------------------------------------------------------------\n\n");
  fclose(fichier); // on ferme le fichier
}
