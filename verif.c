#include "verif.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>






void empty_buffer(){
  // Cette fonction permet de vérifier que l'utilisateur entre bien un chiffre
  while(getchar() != '\n');
}
