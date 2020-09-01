/*strategie.h*/
#ifndef __STRATEGIE_H__
#define __STRATEGIE_H__


#include "plateau.h"

/* Prototype de la structure permettant de définir une stratégie */
typedef struct _strat {
  FILE* file;
  char* nom;
  int CE;
  int CA;
  int CA_demandes; /*CA achetés au début d'un duel*/
  int ind_arme;
  int ind_protection;
  int ind_soin;
} Strat;

/*déclaration d'un tableau statique comportant toutes les stratégies existantes*/
Strat tabStrat[200];

/*prototype de la fonction nomEquipement(char* nom)*/
char* nomEquipement(char* nom);
/*prototype de la fonction initStrat(FILE* f, char* nom)*/
Strat initStrat(FILE* f, char* nom);
/*prototype de la fonction showStrategies ()*/
void showStrategies ();
/*prototype de la fonction showStrategie (int i)*/
void showStrategie (int i);
/*prototype de la fonction choixEquipement(Strat s, Champion* c, Camp* camp)*/
void choixEquipement(Strat s, Champion* c, Camp* camp);
/*prototype de la fonction combat (Strat s1, Strat s2, Duel* d, Camp* Legumes, Camp* Fruits, char** plateau)*/
void combat (Strat s1, Strat s2, Duel* d, Camp* Legumes, Camp* Fruits, char** plateau);
/*prototype de la fonction fightStrat (Strat s1, Strat s2, Duel* d, Camp* Legumes, Camp* Fruits, char** plateau)*/
void fightStrat (Strat s1, Strat s2, Duel* d, Camp* Legumes, Camp* Fruits, char** plateau);

#endif
