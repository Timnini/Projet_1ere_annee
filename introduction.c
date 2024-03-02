#include "introduction.h"
#include "verif.h"
#include "afficher.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  

int nombjoueurs() {
  int nbj;
  // Dans cette fonction on demande le nombre de joueurs
  do {
    printf("enter the number of players (1-4): "); 
    scanf("%d", &nbj);
    empty_buffer();
  } while (nbj <= 0 || nbj > 4); // véirification que la demande est bien conforme
  system("clear"); // on efface la console
  return nbj;
}

int introduction(int nbj, infojoueur *guerrier, infojoueur *ranger,
                 infojoueur *magicien, infojoueur *voleur, FILE *fichier) {
  // Cette fonction énonce les règles du jeu et demande au joueur leur pseudo
  
  printf("Once upon a time in a labyrinth %d adventurers. \n\n", nbj);
  if (nbj >= 1) {
    printf("A warrior 🟥 called...   ");
    scanf("%s", guerrier->pseudo); // on demande au joueur 1 son pseudo
    printf("\n\n"); 
  }
  if (nbj >= 2) {
    printf("A ranger 🟩 called...   ");
    scanf("%s", ranger->pseudo); //on demande au joueur 2 son pseudo
    printf("\n\n");
  }
  if (nbj >= 3) {
    printf("A wizard 🟦 called...  ");
    scanf("%s", magicien->pseudo); //on demande au joueur 3 son pseudo
    printf("\n\n");
  }
  if (nbj == 4) { 
    printf("A robber 🟨 called...   ");
    scanf("%s", voleur->pseudo); //on demande au joueur 4 son pseudo
    printf("\n\n");
  }
// si nbj est égal à 4 alors on passe dans les 4 condition, on crée 4 joueurs.
// si nbj est égal à 3 alors on passe dans 3 conditions 


  // on énonce les règles 
  
  printf("All these adventurers are looking for wealth 🏆 , but each one"
         " is also looking for a specific antique weapon : \n\n");
  if (nbj >= 1) {
    printf(" - the warrior %s looks for the enchanted swords ⚔️ \n\n",
           guerrier->pseudo);
  }
  if (nbj >= 2) {
    printf(" - the ranger %s looking for his sword 🗡️ \n\n", ranger->pseudo);
  }
  if (nbj >= 3) {
    printf(" - the magician %s looking for his grimoire 📓 \n\n ",
           magicien->pseudo);
  }
  if (nbj >= 4) {
    printf("- the thief %s looking for the trolls' magic coins 💰 \n\n",
           voleur->pseudo);
  }
  printf("\n\n");
  printf("  ** Dear adventurers, beware, many monsters "
         "are swarming in this dark labyrinth ** \n\n\n\n");
  printf(
      " The huge Basilisks 🐍️ , which have a look that can change a"
      " adventurer into a stone statue: only the reflection of the shield 🛡️ "
      " can defeat them.\n\n\n");
  printf("- Les Zombies 🧟️ , insensibles à toute arme classique, seul le"
         " feu 🔥 peut en venir a bout. \n\n\n ");
  printf(" Trolls 👾 , great enemies who will only succumb to the blows"
         "devastating axe blows 🪓.\n\n\n");
  
  printf("- Harpies 🦅 , flying monstrosities, they have a weak point against throwing weapons. A bow 🏹 seems to be the solution.\n\n\n\n");
  printf(" ** It turns out that there are also magic items ** \n\n\n\n");
  printf("- The Elf Totem 🗿, which allows you to discover any"
         " card in the dungeon.\n\n\n");
  printf("- The Magic Portal 🌀, which allows you to move anywhere in"
         " the dungeon. \n\n\n\n");
  printf(" ** Game rules ** \n\n\n");
  printf("To progress in the labyrinth the adventurer must choos the right weapon, if he doesn't choose the right weapon he dies, returns to the "
      " if he doesn't choose the right weapon, he dies, returns to the start and all the cards he has found are returned, in "
      "on the other hand, he keeps what he has found (treasure or ancient weapon). \n");
  printf("The winner is the player who has managed to recover his or her weapon "
         "and one of the two hidden treasures. \n\n\n\n");
  int d = 0;
  while (d != 1) {
    printf("Enter 1 to start: ");
    scanf("%d", &d);
    empty_buffer();
  }  // on entre 1 pour commencer
  if (d == 1) {
    system("clear");
    sleep(2);
  }
  return nbj;
}


