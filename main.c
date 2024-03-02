#include "afficher.h"  
#include "deroulement.h"
#include "ecriture.h"
#include "plateau.h"
#include "verif.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void menu(FILE *fichier);

// Le joueur 1 est le guerrier
// Le joueur 2 est le ranger
// Le joueur 3 est le magicien
// Le joueur 4 est le voleur

void jouer1(infojoueur *a, infojoueur *b, infojoueur *s, infojoueur *d, int r,
            int nbj, FILE *fichier) {
  clock_t fin;
  clock_t debut;

  debut = clock();
  // x correspond à la ligne en partant du haut et y correspond à la colonne
  // en partant de la gauche

  // ****************  INFO DU JOUEUR 1 **********************************

  int *xj1 = malloc(sizeof(int)); // position du joueur 1 ( x )
  int *yj1 = malloc(sizeof(int)); // position du joueur 1 ( x )
  int *e1 = malloc(sizeof(int));  // equipement du joueur 1
  int *t1 = malloc(sizeof(int));  // trophée du joueur 1
  int *m1 = malloc(sizeof(int));  // monstres tué par le joueur 1
  int *r1 = malloc(sizeof(int));  // nombre de monstres tué par le joueur 1
  if (xj1 == NULL || yj1 == NULL || e1 == NULL || m1 == NULL || r1 == NULL) {
    printf("Pointer error player 1");
    exit(EXIT_SUCCESS);
  }
  *xj1 = 2; // initialisation de la position du joueur 1 ( x )
  *yj1 = 0; // initialisation de la position du joueur 1 ( y )
  *e1 = 0;  // initialisation de la condition de victoire pour le joueur 1
            // (equipement)
  *t1 =
      0; // initialisation de la condition de victoire pour le joueur 1 (trésor)
  *m1 = 0; // initialisation du nombres de monstres tués du joueur 1
  *r1 = 0; // initialisation du nombres de cartes révélées du joueur 1

  // ***************************************************************************

  // ****************  INFO DU JOUEUR 2 ***************************************

  int *xj2 = malloc(sizeof(int)); // position du joueur
  int *yj2 = malloc(sizeof(int)); // position du joueur
  int *e2 = malloc(sizeof(int));  // equipement du joueurs
  int *t2 = malloc(sizeof(int));  // trophée du joueurs
  int *m2 = malloc(sizeof(int));  // nombre de monstres tué par le joueur
  int *r2 = malloc(sizeof(int));  // nombre de carte retournée par le joueur
  if (xj2 == NULL || yj2 == NULL || e2 == NULL || m2 == NULL || r2 == NULL) {
    printf("Pointer error player 1");
    exit(EXIT_SUCCESS);
  } // vérification des pointeurs

  *xj2 = 0; // initialisation de la position du joueur
  *yj2 = 4; // initialisation de la position du joueur
  *e2 = 0;  // initialisation de la condition de victoire pour le joueur
            // (equipement)
  *t2 = 0; // initialisation de la condition de victoire pour le joueur (trésor)
  *m2 = 0; // initialisation du nombres de monstres tués du joueur
  *r2 = 0; // initialisation du nombres de cartes révélées du joueur

  //***********************************************************************

  // ****************  INFO DU JOUEUR 3 ***************************************

  int *xj3 = malloc(sizeof(int)); // position du joueur
  int *yj3 = malloc(sizeof(int)); // position du joueur
  int *e3 = malloc(sizeof(int));  // equipement du joueurs
  int *t3 = malloc(sizeof(int));  // trophée du joueurs
  int *m3 = malloc(sizeof(int));  // nombre de monstres tué par le joueur
  int *r3 = malloc(sizeof(int));  // nombre de carte retournée par le joueur
  if (xj3 == NULL || yj3 == NULL || e3 == NULL || m3 == NULL || r3 == NULL) {
    printf("Pointer error player 1");
    exit(EXIT_SUCCESS);
  }         // vérification des pointeurs
  *xj3 = 4; // initialisation de la position du joueur 3
  *yj3 = 6; // initialisation de la position du joueur 3
  *e3 = 0;  // initialisation de la condition de victoire pour le joueur
            // (equipement)
  *t3 = 0; // initialisation de la condition de victoire pour le joueur (trésor)
  *m3 = 0; // initialisation du nombres de monstres tués du joueur
  *r3 = 0; // initialisation du nombres de cartes révélées du joueur

  // ****************  INFO DU JOUEUR 4 ***************************************

  int *xj4 = malloc(sizeof(int)); // position du joueur 4
  int *yj4 = malloc(sizeof(int)); // position du joueur 4
  int *e4 = malloc(sizeof(int));  // equipement du joueurs
  int *t4 = malloc(sizeof(int));  // trophée du joueurs
  int *m4 = malloc(sizeof(int));  // nombre de monstres tué par le joueur
  int *r4 = malloc(sizeof(int));  // nombre de carte retournée par le joueur
  if (xj4 == NULL || yj4 == NULL || e4 == NULL || m4 == NULL || r4 == NULL) {
    printf("Pointer error player 1");
    exit(EXIT_SUCCESS);
  }         // vérification des pointeurs
  *xj4 = 6; // initialisation de la position du joueur 4
  *yj4 = 2; // initialisation de la position du joueur 4
  *e4 = 0;  // initialisation de la condition de victoire pour le joueur
            // (equipement)
  *t4 = 0; // initialisation de la condition de victoire pour le joueur (trésor)
  *m4 = 0; // initialisation du nombres de monstres tués du joueur
  *r4 = 0; // initialisation du nombres de cartes révélées du joueur

  //*************************************************************************

  int choix; // variable qui va récupérer le déplacement désiré du joueur
  int stop;
  int c; // variable qui va permettre de savoir si le joueur peut avancer ou si
         // il meurt
  int cha; // variable qui va récupérer le choix de l'arme du joueur
  int *xr = malloc(sizeof(int)); // pointeur qui va garder en mémoire la
                                 // position x de la carte retourné
  int *yr = malloc(sizeof(int)); // pointeur qui va garder en mémoire la
                                 // position y de la carte retourné
  if (xr == NULL || yr == NULL) {
    printf("error pointers, position card returned");
    exit(EXIT_SUCCESS);
  } // vérification des pointeurs

  char **tableau = (char **)malloc(
      BOARD_SIZE * sizeof(char *)); // création du premier tableau 2D
  char **cartes = (char **)malloc(
      BOARD_SIZE * sizeof(char *)); // création du deuxième tableau 2D

  createTableau(tableau); // on remplit **tableau pour créer le plateau de base
                          // (celui qui va contenir les #)

  printf("loading, please wait ... \n\n");

  srand(time(NULL));    // initialisation du rand()
  createcartes(cartes); // on remplit **cartes avec tous les monstres,
                        // équipements, trésors et objets magiques
  sleep(1);

  // le déroulement du jeux

  if (r == 0) {
    nbj = nombjoueurs();
    introduction(nbj, a, b, s, d, fichier);
  } // condition qui sert au premier lancement du jeux

  while (1) {
    // **************** JOUEUR 1 ***************************************
    c = 1;
    if (nbj >= 1) {
      while (c == 1 ||
             c == 2) { // Si c = 1 ou c = 2 cela veut dire que le joueur à
                       // avancer dans le tour précédent ce qui lui permet donc
                       // de pouvoir rejouer d'où cette boucle while.
        printf("-------------------------------------------------------------");
        printf("    %s           %s           %s         %s", a->pseudo,
               b->pseudo, s->pseudo, d->pseudo);
        printf("-------------------------------------------------------------");
        printf("       ** %s your turn to play ** \n\n", a->pseudo);
        sleep(1);
        printTableau(tableau);
        sleep(1);
        stop = 1;
        if(*xj1 != 2 && *yj1 != 0 ){
        stop = bloque(xj1, yj1, tableau);}
        if (stop == 0) {
          printf(" vous êtes bloqué dans le labyrinth");
          sleep(1);
          c = 0;
        } else {
          cha = choisir_arme();
          choix = position(xj1, yj1, tableau);

          revelation(tableau, cartes, xj1, yj1, choix, xr, yr, r1);
          sleep(1);
          c = condition(tableau, cartes, cha, choix, xj1, yj1, xr, yr, m1, e1,
                        t1, 1);
        }
        // condition pour savoir si on peut avancer ou pas
        sleep(1);

        // c = 2 signifie que le joueur à révélé la case du portail magique on
        // utilise donc les fonctions suivantes pour gérer ce cas. La première
        // fonction permet au joueur d'avancer sur le portail, la deuxième
        // permet le changement de case du portail puis la dernière et la au cas
        // où le joueur tombe sur son équipement ou sur un trésor

        if (c == 1 || c == 2) { // Si c =1 c'est que le joueur peut avancer dans
                                // la direction qu'il choisi.

          changement(tableau, cartes, xj1, yj1,
                     choix); // on échange la case du joueur par la case où il
                             // doit aller.
          if (c == 2) {
            changementprotail(tableau, cartes, xj1, yj1);
          }
          sleep(1);
          cvictoire(cartes, 1, xj1, yj1, e1,
                    t1); // récupération si besoins de l'équipement du joueur ou
                         // d'un trésor.

          if (*e1 == 1 && *t1 == 1) {
            printf(" %s you won !",
                   a->pseudo); // on affiche le joueur qui à gagné
            printTableau(
                cartes); // on révèle les tableaux cartes ( celui des montres )
            ecriture(a, b, s, d, m1, m2, m3, m4, r1, r2, r3, r4, t1, t2, t3, t4,
                     e1, e2, e3, e4, 1,
                     fichier);     // on écrit toutes les données de
                                   // la partie dans un fichier
            clock_t fin = clock(); // on stop le "chrono de la partie"
            double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("The program was executed in %f seconds.\n",
                   tempsExecution * 100000); // on calcule et affiche le temps
                                             // de jeu en seconde.
            int rm;
            printf("[1] replay \n\n");
            printf("[2] main menu ");
            do {
              printf(" enter your choice : ");
              scanf("%d", &rm);
              empty_buffer();
            } while (rm < 1 ||
                     rm > 2); // on demande soit de relancer une partie soit de
                              // retourner au menu principal, choix 1 ou 2
            if (rm == 1) {
              jouer1(a, b, s, d, 1, nbj,
                     fichier); // 1 on rentre dans la condition pour rejoueur
            } else if (rm == 2) {
              menu(fichier); // 2 on rentre dans la condition pour retourner au
                             // menu
            }
          } // Cette condition permet de savoir si le joueur à gagné, lorsqu'il
            // a gagné on rentre dans la condition

        } else if (c == 0 && *xj1 == 2 && *yj1 == 0) {
          // condition gérant le cas où le joueur rate son premier tour
          choix = -1;
          retourner(tableau); // permet retourner les cartes dévoilées
          printTableau(tableau);
        } else if (c == 0) {
          // c= 0 lorsque le joueur est mort
          choix = -1;
          changement(
              tableau, cartes, xj1, yj1,
              choix); // permet de remettre le joueur à sa position initiale
          retourner(tableau); // permet de retourner les cartes dévoilées
          printTableau(tableau);
          *xj1 = 2;
          *yj1 = 0; // permet de remettre les pointeurs dans la position initale
                    // du joueur
        }
      }

      // Puis on répète le même schéma pour tout les joueurs en changeant les
      // pointeurs et en changeant dans les fonctions condition et cvictoire un
      // entier qui sera l'entier du numéro du joueur.

      //*****************************************************************************
    }
    system("clear");
    if (nbj >= 2) {
      //***************************JOUEUR
      // 2****************************************

      c = 1;

      while (c == 1 || c == 2) {
        printf("-------------------------------------------------------------");
        printf("    %s           %s           %s         %s", a->pseudo,
               b->pseudo, s->pseudo, d->pseudo);
        printf("-------------------------------------------------------------");
        printf("       ** %s your turn to play ** \n\n", b->pseudo);
        sleep(1);
        printTableau(tableau);
        sleep(1);
         stop = 1;
        if(*xj2 != 0 && *yj2 != 4 ){
        stop = bloque(xj2, yj2, tableau);}
        if (stop == 0) {
          printf(" vous êtes bloqué dans le labyrinth");
          sleep(1);
          c = 0;
        } else {
          cha = choisir_arme();
          choix = position(xj2, yj2, tableau);
          revelation(tableau, cartes, xj2, yj2, choix, xr, yr, r2);
          sleep(1);
          c = condition(tableau, cartes, cha, choix, xj2, yj2, xr, yr, m2, e2,
                        t2, 2);
        }
        // condition pour savoir si on peut avancer ou pas
        sleep(1);

        if (c == 1 || c == 2) {
          changement(tableau, cartes, xj2, yj2, choix);
          sleep(1);
          if (c == 2) {

            changementprotail(tableau, cartes, xj2, yj2);
          }
          cvictoire(cartes, 2, xj2, yj2, e2, t2);
          if (*e2 == 1 && *t2 == 1) {
            printf(" %s you won !", b->pseudo);
            printTableau(cartes);
            ecriture(a, b, s, d, m1, m2, m3, m4, r1, r2, r3, r4, t1, t2, t3, t4,
                     e1, e2, e3, e4, 2, fichier);
            clock_t fin = clock();
            double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("The program was executed in %f seconds.\n",
                   tempsExecution * 100000);
            int rm;
            printf("[1] replay \n\n");
            printf("[2] main menu");
            do {
              printf(" enter your choice : ");
              scanf("%d", &rm);
              empty_buffer();
            } while (rm < 1 || rm > 2);
            if (rm == 1) {
              jouer1(a, b, s, d, 1, nbj, fichier);
            } else if (rm == 2) {
              menu(fichier);
            }
          }
        } else if (c == 0 && *xj2 == 0 && *yj2 == 4) {
          choix = -2;
          retourner(tableau);
          printTableau(tableau);
        } else if (c == 0) {
          choix = -2;
          changement(tableau, cartes, xj2, yj2, choix);
          retourner(tableau);
          printTableau(tableau);
          *xj2 = 0;
          *yj2 = 4;
        }
      }

      //***************************************************************************
    }
    system("clear");

    if (nbj >= 3) {

      //************************** Joueur
      // 3***************************************

      c = 1;
      while (c == 1 || c == 2) {
        printf("-------------------------------------------------------------");
        printf("    %s           %s           %s         %s", a->pseudo,
               b->pseudo, s->pseudo, d->pseudo);
        printf("-------------------------------------------------------------");
        printf("       ** %s your turn to play ** \n\n", s->pseudo);
        sleep(1);
        printTableau(tableau);
        sleep(1);
        stop = 1;
        if( *xj3 != 4 && *yj3 != 6){
        stop = bloque(xj3, yj3, tableau);}
        if (stop == 0) {
          printf(" vous êtes bloqué dans le labyrinth");
          sleep(1);
          c = 0;
        } else {
          cha = choisir_arme();
          choix = position(xj3, yj3, tableau);
          revelation(tableau, cartes, xj3, yj3, choix, xr, yr, r3);
          sleep(1);
          c = condition(tableau, cartes, cha, choix, xj3, yj3, xr, yr, m3, e3,
                        t3, 3);
        }
        // condition pour savoir si on peut avancer ou pas
        sleep(1);

        if (c == 1 || c == 2) {
          changement(tableau, cartes, xj3, yj3, choix);
          sleep(1);
          if (c == 2) {
            changementprotail(tableau, cartes, xj3, yj3);
          }
          cvictoire(cartes, 3, xj3, yj3, e3, t3);
          if (*e3 == 1 && *t3 == 1) {
            printf(" %s you won !", s->pseudo);
            printTableau(cartes);
            ecriture(a, b, s, d, m1, m2, m3, m4, r1, r2, r3, r4, t1, t2, t3, t4,
                     e1, e2, e3, e4, 3, fichier);
            clock_t fin = clock();
            double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("The program was executed in %f seconds.\n",
                   tempsExecution * 100000);
            int rm;
            printf("[1] replay \n\n");
            printf("[2] main menu");
            do {
              printf(" enter your choice : ");
              scanf("%d", &rm);
              empty_buffer();
            } while (rm < 1 || rm > 2);
            if (rm == 1) {
              jouer1(a, b, s, d, 1, nbj, fichier);
            } else if (rm == 2) {
              menu(fichier);
            }
          }
        } else if (c == 0 && *xj3 == 4 && *yj3 == 6) {
          choix = -3;
          retourner(tableau);
          printTableau(tableau);
        } else if (c == 0) {
          choix = -3;
          changement(tableau, cartes, xj3, yj3, choix);
          retourner(tableau);
          printTableau(tableau);
          *xj3 = 4;
          *yj3 = 6;
        }
      }
      //**************************************************************************
    }
    system("clear");

    //************************ JOUEUR 4
    //*****************************************
    if (nbj >= 4) {
      c = 1;
      while (c == 1 || c == 2) {
        printf("-------------------------------------------------------------");
        printf("    %s           %s           %s         %s", a->pseudo,
               b->pseudo, s->pseudo, d->pseudo);
        printf("-------------------------------------------------------------");
        printf("       ** %s your turn to play ** \n\n", d->pseudo);
        sleep(1);
        printTableau(tableau);
        sleep(1);
        stop = 1;
        if(*xj4 != 6 && *yj4 != 2){
        stop = bloque(xj4, yj4, tableau);}
        if (stop == 0) {
          printf(" vous êtes bloqué dans le labyrinth");
          sleep(1);
          c = 0;
        } else {
          cha = choisir_arme();
          choix = position(xj4, yj4, tableau);
          revelation(tableau, cartes, xj4, yj4, choix, xr, yr, r4);
          sleep(1);
          c = condition(tableau, cartes, cha, choix, xj4, yj4, xr, yr, m4, e4,
                        t4, 4);
        }
        // condition pour savoir si on peut avancer ou pas
        sleep(1);

        if (c == 1 || c == 2) {
          changement(tableau, cartes, xj4, yj4, choix);
          sleep(1);
          if (c == 2) {

            changementprotail(tableau, cartes, xj4, yj4);
          }
          cvictoire(cartes, 4, xj4, yj4, e4, t4);
          if (*e4 == 6 && *t4 == 2) {
            printf(" %s you won !", d->pseudo);
            printTableau(cartes);
            ecriture(a, b, s, d, m1, m2, m3, m4, r1, r2, r3, r4, t1, t2, t3, t4,
                     e1, e2, e3, e4, 4, fichier);
            clock_t fin = clock();
            double tempsExecution = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("The program was executed in %f seconds.\n",
                   tempsExecution * 100000);
            int rm;
            printf("[1] replay \n\n");
            printf("[2] main menu");
            do {
              printf(" enter your choice : ");
              scanf("%d", &rm);
              empty_buffer();
            } while (rm < 1 || rm > 2);
            if (rm == 1) {
              jouer1(a, b, s, d, 1, nbj, fichier);
            } else if (rm == 2) {
              menu(fichier);
            }
          }
        } else if (c == 0 && *xj4 == 6 && *yj4 == 2) {
          choix = -4;
          retourner(tableau);
          printTableau(tableau);
        } else if (c == 0) {
          choix = -4;
          changement(tableau, cartes, xj4, yj4, choix);
          retourner(tableau);
          printTableau(tableau);
          *xj4 = 6;
          *yj4 = 2;
        }
      }
    }
  }
}
//***************************************************************************

void menu(FILE *fichier) {

  infojoueur *a = malloc(sizeof(infojoueur));
  infojoueur *b = malloc(sizeof(infojoueur));
  infojoueur *s = malloc(sizeof(infojoueur));
  infojoueur *d = malloc(sizeof(infojoueur));

  if (a == NULL || b == NULL || s == NULL || d == NULL) {
    printf("error, player info pointers\n");
  } // vérification des pointeurs

  if (fichier == NULL) {
    printf("Unable to open the file.\n");
  } // vérification du pointeur fichier

  int r; // variable qui permet de relancer une partie avec les mêmes joueurs
  int m; // choix du mode dans le menu
  do {
    printf("\n\n");
    printf("[1] PLAY \n\n");
    printf("[2] SCORE  \n\n");
    printf("Enter your choice: ");
    scanf("%d", &m); // choix du mode
    empty_buffer();
  } while (m > 2 || m < 1); // vérification du choix
  if (m == 1) {             // si le choix est 1 on fait la fontion jouer1
    printf("\n\n");
    jouer1(a, b, s, d, 0, 0, fichier);
  }
  if (m == 2) { // si le choix est 2 on affiche le score de toutes les parties
                // et on quitte le programme
    afficher(fichier);
    exit(EXIT_SUCCESS);
  }
}

FILE *fichier;

int main() {

  fichier = fopen("texte.txt", "a");
  menu(fichier);
  return 0;
}
