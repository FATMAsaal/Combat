/* plateau.h*/
#ifndef __PLATEAU_H__
#define __PLATEAU_H__

#include "combat.h"

/* Prototype de la fonction nouveauPlateau() */
char** nouveauPlateau();
/* Prototype de la fonction reinitPlateau(Duel* d, char** plateau) */
void reinitPlateau(Duel* d, char** plateau);
/* Prototype de la fonction affichagePlateau(char** plateau) */
void affichagePlateau(char** plateau);

#endif
