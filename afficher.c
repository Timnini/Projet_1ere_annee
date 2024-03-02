#include <stdio.h>
#include "afficher.h"  

void afficher(FILE *fichier) {
  // Cette fonction permet d'afficher tout ce qui se trouve dans le fichier texte
 int i;
  int c = 0;
  fichier= fopen("texte.txt","r"); // on ouvre le fichier en lecture
  while(fgetc(fichier)!= EOF){
    c = c+1;
  } // tant que la tête de lecture n'arrive pas à la fin du fichier, on ajoute à 1 à c
  fichier= fopen("texte.txt","r"); // on replace le curseur au début du fichier
  for(i=0;i<c;i++){
    printf("%c",fgetc(fichier));
  }} // on affiche tout les caractères du fichier
