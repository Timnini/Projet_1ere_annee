#include "plateau.h"
#include "verif.h"  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_SIZE 7

// Ce fichier .c regroupe toutes les fonctions qui gèrent l'affiche du plateau
// et ses fonctionnalités

// AFFICHAGE

void createTableau(char **tableau) {
  // Cette fonction permet de créer le plateau de base du jeu
  int i, j;
  // Allocation de mémoire pour chaque ligne
  for (i = 0; i < BOARD_SIZE; i++) {
    tableau[i] = malloc(BOARD_SIZE * sizeof(char));
  }
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if ((i == 0 && j != 4) || (j == 0 && i != 2) || (i == 6 && j != 2) ||
          (i != 4 && j == 6)) {

        *(tableau[i] + j) = (' ');
      } // Cette condition permet de créer les bords avec les espaces

      else if (i == 0 && j == 4) {
        *(tableau[i] + j) = ('o'); // la lettre du joueur 2
      } else if (j == 0 && i == 2) {
        *(tableau[i] + j) = ('x'); // la lettre du joueur 1

      } else if (i == 6 && j == 2) {
        *(tableau[i] + j) = ('a'); // la lettre du joueur 3
      } else if (i == 4 && j == 6) {
        *(tableau[i] + j) = ('u'); // la lettre du joueur 4

      } // tous ces "else if" permettent de placer les pions des joueurs autour
        // du plateau

      else {
        *(tableau[i] + j) = ('#');
      } // le reste du tableau est donc rempli avec des # qui représentent les
        // cartes retournés
    }
  }
}

void printTableau(char **tableau) {
  // Dans cette fonction on afficher le plateau en remplacant lettres par des emojis
  // on parcourt le tableau et on remplace chaque lettre par un l'emoji qu'elle représente
  printf("\n");
  int i, j;
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (*(tableau[i] + j) == ('o')) {
        printf("🟩"); // o, le joueur 2 (le ranger)
      } else if (*(tableau[i] + j) == ('x')) {
        printf(" 🟥"); // x, le joueur 1 (le guerrier)
      } else if (*(tableau[i] + j) == ('a')) {
        printf("🟨"); // a, le joueur 4 (le voleur)
      } else if (*(tableau[i] + j) == ('u')) {
        printf("🟦"); // u,le joueur 3 (la magicien)
      } else if (*(tableau[i] + j) == ('z')) {
        printf("🧟️️️ "); // z, les zombies
      } else if (*(tableau[i] + j) == ('b')) {
        printf("🐍️️ "); // b, les basilics 
      } else if (*(tableau[i] + j) == ('h')) {
        printf("🦅 "); // h, les harpies
      } else if (*(tableau[i] + j) == ('t')) {
        printf("👾 "); // t, les trolls
      } else if (*(tableau[i] + j) == ('c')) {
        printf("🏆 "); // c, les trésors 
      } else if (*(tableau[i] + j) == ('d')) {
        printf("🗡️ "); // d, la dague du ranger
      } else if (*(tableau[i] + j) == ('e')) {
        printf("⚔️ "); // e, les épées du guerrier
      } else if (*(tableau[i] + j) == ('g')) {
        printf("📓 "); // g , le grimoire du magicien
      } else if (*(tableau[i] + j) == ('j')) {
        printf("💰 "); // j, le sac de sous du voleur
      } else if (*(tableau[i] + j) == ('k')) {
        printf("🗿 "); // k, les totems magiques
      } else if (*(tableau[i] + j) == ('p')) {
        printf("🌀 "); // p, le portail magique
      }

      else {
        printf(" %c ", *(tableau[i] + j)); // si on reconnait aucune lettre, on affiche la case du tableau sans changement
      }
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
}

void shuffleCards(char **cartes) {
  // Cette fonctions permet de mélanger les cartes (monstres,équipements, trésor et objets magiques)
  int i, j, x, y;
  char temp;

  // Shuffle the non-border cards
  for (i = 1; i < BOARD_SIZE - 1; i++) {
    for (j = 1; j < BOARD_SIZE - 1; j++) {
      x = rand() % (BOARD_SIZE - 2) +
          1; // on récupère une coordonnée x aléatoire
      y = rand() % (BOARD_SIZE - 2) + 1;  // on récupère une coordonnée y aléatoire
      temp = cartes[i][j]; 
      cartes[i][j] = cartes[x][y];
      cartes[x][y] = temp; // on échange la carte de coordonnés i/j par la carte de coordonnés x/y
    }
  }
}

void tresor(char **cartes) {
  // Cette fonction permet de mettre dans le jeu  les deux trésors et les différents équipements des joueurs
  int i, j, e;
  e = 0;
  // on parcourt le tableau "cartes" et à chaque fois qu'il y a une case vide, soit ".", on met un équipement et on ajoute 1 à e pour ne pas avoir plusieurs fois le même équipement (petite particularité dans la condition pour pouvoir avoir deux trésors)
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (*(cartes[i] + j) == ('.') && e < 1) {
        *(cartes[i] + j) = ('j'); // pour le sac de sous 
        e = e + 1;
      } else if (*(cartes[i] + j) == ('.') && e < 2) {
        *(cartes[i] + j) = ('e'); // les épées
        e = e + 1;
      } else if (*(cartes[i] + j) == ('.') && e < 3) {
        *(cartes[i] + j) = ('d'); // pour le sabre 
        e = e + 1;
      } else if (*(cartes[i] + j) == ('.') && e < 4) {
        *(cartes[i] + j) = ('g'); // pour le grimoire
        e = e + 1;
      } else if (*(cartes[i] + j) == ('.') && e < 5) {
        *(cartes[i] + j) = ('p'); // pour le portail
        e = e + 1;
      } else if (*(cartes[i] + j) == ('.') && e < 7) {
        *(cartes[i] + j) = ('k'); // pour le totem
        e = e + 1;
      } else if (*(cartes[i] + j) == ('.') && e < 9) {
        *(cartes[i] + j) = ('c');
        e = e + 1;
      }
    }
  }
}

char monstres() {
  // Cette fonction permet d'introduire les différents monstres dans le plateau
  int a;
  a = rand() % 4 + 1; // on utilise un rand() pour que le monstres qui va être placé dans une case soit aléatoire
  if (a == 1) {
    return ('b'); // monstres basilics
  }
  if (a == 2) {
    return ('z'); // monstres zombies
  }
  if (a == 3) {
    return ('t'); // monstres trolls
  }
  if (a == 4) {
    return ('h'); // monstres harpies
  }
  return (' '); // retourne un espace si il y a un problème
}

void createcartes(char **cartes) {
  // Cette fonction permet de créer le plateau du jeu avec tous les monstres à
  // l'interieur, ( on crée l'autre face des cartes) en conservant les bordures
  // et les pions placées.
  int i, j, nmbm, r;
  nmbm = 0;
  r = 0;

  // Allocation de mémoire pour chaque ligne
  for (i = 0; i < BOARD_SIZE; i++) {
    cartes[i] = malloc(BOARD_SIZE * sizeof(char));
  }

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      // on parcout le tableau à l'aide de ces boucles 
      
      if ((i == 0 && j != 4) || (j == 0 && i != 2) || (i == 6 && j != 2) ||
          (i != 4 && j == 6)) {
        *(cartes[i] + j) = (' ');
      } // Cette condition places les bords du plateau
        
      else if (i == 0 && j == 4) {
        *(cartes[i] + j) = ('o');
      } // cette condition places le joueur 2 à sa position initiale
      else if (i == 2 && j == 0) {
        *(cartes[i] + j) = ('x');  //cette condition places le joueur 1 à sa position
      } else if (i == 6 && j == 2) {
        *(cartes[i] + j) = ('a');  //cette condition places le joueur 4 à sa position
      } else if (i == 4 && j == 6) {
        *(cartes[i] + j) = ('u');  //cette condition places le joueur 3 à sa position
      } else {

        if (r < 16) {
          *(cartes[i] + j) = monstres();
          r++; // on place les monstres dans le plateau à l'aide de la fonction "monstres" 
        } else {
          *(cartes[i] + j) = ('.'); 
        }
      }
    }
  }
  tresor(cartes); // on place les trésor et équipements 
  // pour ne pas avoir les monstres, les trésor et les équipements tous à la suite,on utilise la fontion shufflecards
  shuffleCards(cartes); 
}

// FONCTIONNALITES

void revelationtotem(char **tableau, char **cartes, int *x1, int *y1) {
  // Cette fonction permet l'utilisation du totem
  int xt, yt; // variables qui vont prendre le choix de coordonées du joueur
  
  
  printf("choose the coordinates of a box :  \n\n"); 
  do {
    do {
       printf("column number : ");
      scanf("%d", &yt);
      empty_buffer();
    } while (yt <= 0 || yt > 5);    
    do {
       printf("line number : ");
      scanf("%d", &xt);
      empty_buffer(); // Vérifier que c'est un entier pour pas que ça boucle à l'infini quand on a un char.
    } while (xt <= 0 || xt > 5);
  } while (xt == *x1 && yt == *y1); // on choisit les coordonnées que l'on veut,avec une vérification avec empty_buffer (voir fonction) et une seconde vérification au cas où les coordonnées choisies ne sont pas celle du joueur.

  
  if (xt == 5) {
    xt = 1;
  } else if (xt == 4) { // changement de repère (car instinctivemnt on monte en haut dans les ordonné alors qu'on doit descendre avec le  tableau )
    xt = 2;
  } else if (xt == 1) {
    xt = 5;
  } else if (xt == 2) {
    xt = 4;
  }
  *(tableau[xt] + yt) = *(cartes[xt] + yt); // on échange la case '#' par la cartes se trouvant à la même position dans le tableau 'cartes'
  sleep(1);
  printTableau(tableau); // on affiche le tableau actualisé
  sleep(1);
}

void changementprotail(char **tableau, char **cartes, int *x1, int *y1) {
  int xt, yt;
  // fonction du portail magique, elle permet de se déplacer n'importe où sur le plateau du jeu 

  
  printf("choose the coordinates of a box :  \n\n"); 
  do {
    do {
   printf("column number : ");
      scanf("%d", &yt);
      empty_buffer();
    } while (yt <= 0 || yt > 5);
    do {
         printf("line number : ");
      scanf("%d", &xt);
      empty_buffer();
    } while (xt <= 0 || xt > 5);
  } while (xt == *x1 && yt == *y1);// on demande les coordonnées souhaité au joueur en vérifiant qu'elle soit bien valide

  
  if (xt == 5) {
    xt = 1;
  } else if (xt == 4) {
    xt = 2;
  } else if (xt == 1) {
    xt = 5;
  } else if (xt == 2) {
    xt = 4;
  }
  *(tableau[xt] + yt) = *(cartes[xt] + yt); // comme la fonction du totem on échange la case '#' dans le 'tableau' par la case qui correpond dans le tableau 'cartes'
  sleep(1);
  printTableau(tableau); // on affiche le tableau
  sleep(1);
  *(tableau[xt] + yt) = *(tableau[*x1] + *y1); // puis on échange la case où est placé le joueur par la case dont les coordonnées ont été choisie
  *(tableau[*x1] + *y1) = ('p'); // on remet le portail où été placé le joueur
  *x1 = xt; 
  *y1 = yt; // on actualise la position du joueur
  printTableau(tableau);
}
