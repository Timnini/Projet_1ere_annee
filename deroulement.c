#include "deroulement.h"
#include "ecriture.h"
#include "plateau.h"
#include "verif.h"
#include <stdio.h>  
#include <stdlib.h>

int choisir_arme() {
  // Cette fonction permet de choisir une arme. Elle retourne un le chiffre corespondant à l'arme en question.
  int choix_arme;
  do {
    printf("       ** Please select a weapon: **\n\n");
    printf("        1 - Torch 🔥       2 - Shield 🛡️\n\n");
    printf("         3 - Axe 🪓         4 - Arch 🏹  \n\n\n");
    printf("Your choice is : ");
    scanf("%d",&choix_arme);
    empty_buffer();
    printf("\n");
  } while (choix_arme < 1 || choix_arme > 4);
  switch (choix_arme) {
  case 1:
    printf("You choose the Torch. 🔥\n");
    break;
  case 2:
    printf("You choose the Shield. 🛡️\n");
    break;
  case 3:
    printf("You choose the Axe. 🪓\n");
    break;
  case 4:
    printf("You choose the Arch. 🏹\n");
    break;
  default:
    printf("Invalid choice.\n");
    break;
  }
  return choix_arme;
}

int bloque(int *x,int *y,char **tableau){
  int b;
  if(*(tableau[(*x)+1] + *y ) != ('#') && *(tableau[*x] + (*y)+1) != ('#') && *(tableau[(*x)-1] + *y) != ('#') && *(tableau[(*x)] + (*y)-1 ) != ('#') ){
     b = 0;
  }else{
    b = 1;
}
  return b;}

int position(int *x, int *y,char **tableau) {
  // Cette fonction permet au joueur de choisir son déplacement, elle change son affichage en fonction de la posibilité de déplacement du joueur
  // retourne le choix du joueur qui est un entier compris entre 1 et 4
  int choix;
  
  if (*x == 2 && *y == 0){
    do {
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("\n\n");
      printf("                [3] right\n\n");
      printf("\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();
    } while (choix != 3);

  }

  
  else if (*x == 0 && *y == 4) {
    do {
      printf("\n\n");
      printf("          ** where do you want to go ? **");
      printf("\n");
      printf("\n\n");
      printf("\n\n");
      printf("        [4] bottom\n\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();
    } while (choix != 4);
  } else if (*x == 4 & *y == 6) {
    do {
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("\n\n");
      printf("[2] left");
      printf("\n\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();
    } while (choix != 2);
  } else if (*x == 6 && *y == 2) {
    do {
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("        [1] high \n\n");
      printf("\n\n");
      printf("\n\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();
    } while (choix != 1);

  } else if (*x == 1 ||*(tableau[(*x)-1] + *y) != ('#') ) {
    if (*y == 1 || (*(tableau[(*x)-1] + *y) != ('#') && *(tableau[(*x)] + (*y)-1 ) != ('#') )) {
      do{
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf(" \n\n");
      printf("                 [3] right\n\n");
      printf("        [4] bottom\n\n");
      printf("enter your choice : ");
          scanf("%d",&choix);
      empty_buffer();}while( choix != 3 && choix !=4);
    }
    else if (*y == 5 ||(*(tableau[*x] + (*y)+1) != ('#') && *(tableau[(*x)-1] + *y) != ('#'))) {
      do{
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("\n\n");
      printf("[2] left\n\n");
      printf("        [4] bottom\n\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();}while(choix !=2 && choix !=4);
    } else {
      do{
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("\n\n");
      printf("[2] left      [3] right\n\n");
      printf("        [4] bottom\n\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();}while(choix !=2 && choix !=3 && choix!=4);
    }
  } else if (*x == 5 ||  *(tableau[(*x)+1] + *y ) != ('#') ) {
    if (*y == 1 || *(tableau[(*x)+1] + *y ) != ('#') && *(tableau[(*x)] + (*y)-1 ) != ('#')) {
      do{
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("        [1] high \n\n");
      printf("                 [3] right\n\n");
      printf("\n\n");
      printf("enter your choice : ");
     scanf("%d",&choix);
      empty_buffer();}while(choix !=1 && choix!=3);
    }
    else if (*y == 5 || *(tableau[(*x)+1] + *y ) != ('#') && *(tableau[*x] + (*y)+1) != ('#')) {
      do{
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("        [1] high \n\n");
      printf("[2] left\n\n");
      printf("\n\n");
      printf("enter your choice : ");
            scanf("%d",&choix);
      empty_buffer();}while(choix!=1 && choix!=2);
    } else {
      do{
      printf("\n\n");
      printf("          ** Where do you want to go ? **");
      printf("\n");
      printf("        [1] high \n\n");
      printf("[2] left      [3] right\n\n");
      printf("\n\n");
      printf("enter your choice : ");
     scanf("%d",&choix);
      empty_buffer();}while(choix!=1 && choix !=2 && choix !=3);
    }

  } else if (*y == 1 ||*(tableau[*x] + (*y)-1 ) != ('#')) {
    do{
    printf("\n\n");
    printf("          ** Where do you want to go ? **");
    printf("\n");
    printf("        [1] high \n\n");
    printf("                 [3] right\n\n");
    printf("        [4] bottom\n\n");
    printf("enter your choice : ");
    scanf("%d",&choix);
      empty_buffer();}while(choix != 1 && choix !=3 && choix !=4);
  } else if (*y == 5 || (*(tableau[*x] + (*y)+1) != ('#') )) {
    do{
    printf("\n\n");
    printf("          ** Where do you want to go ? **");
    printf("\n");
    printf("        [1] high \n\n");
    printf("[2] left      \n\n");
    printf("        [4] bottom\n\n");
    printf("enter your choice : ");
   scanf("%d",&choix);
      empty_buffer();}while(choix !=1 && choix!=2 && choix!=4);
  }

  else {
    do {
      printf("\n");
      printf("        [1] high \n\n");
      printf("[2] left      [3] right\n\n");
      printf("        [4] bottom\n\n");
      printf("enter your choice : ");
      scanf("%d",&choix);
      empty_buffer();
    } while (choix != 1 && choix != 2 && choix != 3 && choix != 4);
  }
  return choix;
}

void revelation(char **tableau, char **cartes, int *x, int *y, int choix, int *xr, int *yr,int *r) {
  // Cette fonction permet de retourner une carte puis dans un second temps
 //en réalité on remplace la case choisi du
  // "tableau avec les faces cachée(**tableau)" par la case du même indice
  // du "tableau face retourné (**cartes
  if (choix == 1) {
    *xr = *x - 1;
    *yr = *y;
  }
  if (choix == 2) {
    *xr = *x;
    *yr = *y - 1;
  }
  if (choix == 3) {
    *yr = *y + 1;
    *xr = *x;
  }
  if (choix == 4) {
    *yr = *y;
    *xr = *x + 1;
  }
 
        *(tableau[*xr] + *yr ) = *(cartes[*xr] + *yr);
  *r = *r +1;
        printTableau(tableau);
      
    
  
}

void retourner(char **tableau) {
  // Cette fonction permet de retourner une carte 
  int i, j;
  for (i = 1; i < 6; i++) {
    for (j = 1; j < 6; j++) {
      if ((*(tableau[i] + j) != ('#')) && (*(tableau[i] + j) != (' '))) {
        *(tableau[i] + j) = ('#');
      }
    }
  }
}

void changement(char **tableau, char **cartes, int *x1, int *y1, int choix) {
  // Cette fonction permet de faire avancer, reculer, monter,descendre le joueur
  // en réalité on échange la case ou il y le logo du joueur par la case où il veut aller. 
  // lorsque la case '#' échangée va vers un bord elle est remplacé par du un caractère (' ')
  // x1 et y1 position départ du joueur, x et y position futur du joueur
  
  int x;
  int y;
  if (choix == 1) {
    x = *x1 - 1;
    y = *y1;
  }
  if (choix == 2) {
    x = *x1;
    y = *y1 - 1;
  }
  if (choix == 3) {
    x = *x1;
    y = *y1 + 1;
  }
  if (choix == 4) {
    x = *x1 + 1;
    y = *y1;
  }
  if (choix == -1) {
    x = 2;
    y = 0;
  } // Cette condition sert a remettre le joueur 1 à sa case initiale
  if (choix == -2) {
    x = 0;
    y = 4;
  }
  if (choix == -3) {
    x = 4;
    y = 6;
  }
  if (choix == -4) {
    x = 6;
    y = 2;
  }

  *(tableau[x] + y) = *(tableau[*x1] + *y1);
  if (*x1 == 0 || *y1 == 0 || *x1 == 6 || *y1 == 6) {
    *(tableau[*x1] + *y1) = (' ');
  } else {
    *(tableau[*x1] + *y1) = *(cartes[*x1] + *y1);
  }
  *x1 = x;
  *y1 = y;
  printTableau(tableau);
}

int condition(char **tableau, char **cartes, int arme, int choix, int *x1,
              int *y1, int *xr, int *yr, int *m, int *e, int *t, int n) {
// Cette fonction permet de regarder si le jouermet de regarder eur 
  int i, j, r;
  r = 0;
  if (arme == 1 && *(cartes[(*xr)] + (*yr)) == ('z')) {
    r = 1;
    *m = *m + 1;
  } else if (arme == 2 && *(cartes[(*xr)] + (*yr)) == ('b')) {
    r = 1;
    *m = *m + 1;
  } else if (arme == 3 && *(cartes[(*xr)] + (*yr)) == ('t')) {
    r = 1;
    *m = *m + 1;
  } else if (arme == 4 && *(cartes[(*xr)] + (*yr)) == ('h')) {
    r = 1;
    *m = *m + 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('j')) {
    r = 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('e')) {
    r = 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('d')) {
    r = 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('g')) {
    r = 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('c')) {
    r = 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('k')) {
    revelationtotem(tableau, cartes, x1, y1);
    r = 1;
  } else if (*(cartes[(*xr)] + (*yr)) == ('p')) {
    r = 2;
  } else {
    r = 0;
  }
  return r;
}

void cvictoire(char **cartes, int n, int *x, int *y, int *e, int *t) {
  if (n == 1) {
    if (*(cartes[*x] + *y) == ('e')) {
      *e = *e + 1;
      printf("you got your magic equipment back ! \n\n");
    } else if (*(cartes[*x] + *y) == ('c')) {
      *t = *t + 1;
      printf("you have recovered a treasure ! \n\n");
    }

  } else if (n == 2) {
    if (*(cartes[*x] + *y) == ('d')) {
      *e = *e + 1;
      printf("you got your magic equipment back ! \n\n");
    }
    if (*(cartes[*x] + *y) == ('c')) {
      *t = *t + 1;
      printf("you have recovered a treasure ! \n\n");
    } // Cela représente le ranger qui doit trouver son sabre ('d') et le
      // trésor
      // ('c')
  } else if (n == 3) {
    if (*(cartes[*x] + *y) == ('g')) {
      *e = *e + 1;
      printf("you got your magic equipment back ! \n\n");
    }
    if (*(cartes[*x] + *y) == ('c')) {
      *t = *t + 1;
      printf("you have recovered a treasure ! \n\n");
    }
  } else if (n == 4) {
    if (*(cartes[*x] + *y) == ('j')) {
      *e = *e + 1;
      printf("you got your magic equipment back ! \n\n");
    }
    if (*(cartes[*x] + *y) == ('c')) {
      *t = *t + 1;
      printf("you have recovered a treasure ! \n\n");
    }
  }
  if (*t == 2) {
    *t = *t - 1;
  }
  if (*e == 2) {
    *e = *e - 1;
  }
}






