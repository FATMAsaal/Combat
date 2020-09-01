/*combat.h*/
#ifndef __COMBAT_H__
#define __COMBAT_H__

#include "affichage.h"


/*definition d'une macro qui permet de "retourner" le max entre deux nombres*/
#define max(a,b) (((a)>=(b))?(a):(b))

/* Prototype de la fonction choixChampion(Champion* c, Camp* camp, int i) */
void choixChampion (Champion* c, Camp* camp, int i);
/* Prototype de la fonction choixArme(Champion* c, Camp* camp, int i) */
void choixArme(Champion* c, Camp* camp, int i);
/* Prototype de la fonction choixProtection (Champion* c, Camp* camp, int i) */
void choixProtection(Champion* c, Camp* camp, int i);
/* Prototype de la fonction choixSoin(Champion* c, Camp* camp, int i) */
void choixSoin(Champion* c, Camp* camp, int i);
/* Prototype de la fonction achatCA(Camp* camp, int nb) */
void achatCA(Camp* camp, int nb);
/* Prototype de la fonction fight(Duel *d, Camp* Camp_Legumes, Camp* Camp_Fruits) */
void fight(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits);
/* Prototype de la fonction show(Duel d) */
void show(Duel d);
/* Prototype de la fonction moveforward(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int *n) */
void moveforward(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int *n);
/* Prototype de la fonction testMoveBackward(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int *n) */
void movebackward(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int *n);
/* Prototype de la fonction tirsArme(Camp* campTrieur, Champion* tireur, Champion* adversaire, int proba, float dist) */
void tirsArme(Camp* campTrieur, Champion* tireur, Champion* adversaire, int proba, float dist);
/* Prototype de la fonction useweapon(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int *n) */
void useweapon(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int *n);
/* Prototype de la fonction seSoigner(Camp* camp, Champion* c, int nb) */
void seSoigner(Camp* camp, Champion* c, int nb);
/* Prototype de la fonction usecare(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int* n) */
void usecare(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int* n);
/* Prototype de la fonction mettreProtection(Champion* c, Camp* camp) */
void mettreProtection(Champion* c, Camp* camp);
/* Prototype de la fonction useprotection(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits) */
void useprotection(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits);
/* Prototype de la fonction end(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits) */
void end(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits);

#endif
