/*plateau.c*/
#include "plateau.h"



/*
 * Fonction qui permet de créer un nouveau plateau.
 *
 * @param : void
 * @return : char** (une matrice à deux dimentions de type char)
 *
 */

char** nouveauPlateau(){
  int ligne, colonne;
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  char** plateau =  malloc(w.ws_row/3 * sizeof(char*));
  for(ligne=0; ligne < w.ws_row/3; ligne++){
    plateau[ligne] = malloc(w.ws_col/6 * sizeof(char));
    for(colonne=0; colonne < w.ws_col/6; colonne++) {
      plateau[ligne][colonne] = ' ';
    }
  }
  plateau[0][0]='L';
  plateau[(w.ws_row/3)-1][(w.ws_col/6)-1] = 'F';
  return plateau;
}




/*
 * Fonction qui permet de mettre à jour le lateau du jeu avec les nouveaux emplacmenents des champions.
 *
 * @param : d - Duel* (type déclaré dans init.h)
 *          plateau - char**
 * @return : char** (une matrice à deux dimentions de type char)
 *
 */

void reinitPlateau (Duel *d, char** plateau) {
  int ligne, colonne;
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  for(ligne = 0; ligne < w.ws_row/3; ligne++) {
      for(colonne = 0; colonne <w.ws_col/6; colonne++) {
          if (ligne == d->pos1.x && colonne == d->pos1.y ) {
            plateau[ligne][colonne] = 'L';
          } else if (ligne == d->pos2.x && colonne == d->pos2.y ) {
            plateau[ligne][colonne] = 'F';
          } else {
            plateau[ligne][colonne] = ' ';
        }
      }
    }
}


/*
 * Fonction qui permet d'afficher le plateau de jeu.
 *
 * @param : plateau - char**
 * @return : void
 *
 */

void affichagePlateau(char** plateau){
  int ligne, colonne;
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
    for(ligne = 0; ligne < w.ws_row/3; ligne++) {
        for(colonne = 0; colonne <w.ws_col/6; colonne++) {
          printf("+---");
        }
        printf("+\n");
        for(colonne = 0; colonne <w.ws_col/6; colonne++) {
          printf("| %c ", plateau[ligne][colonne]);
        }
        printf("|\n");
    }
    for(colonne = 0; colonne <w.ws_col/6; colonne++) {
      printf("+---");
    }
    printf("+\n");
}
