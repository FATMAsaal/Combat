/*deroulement.h*/
#ifndef __DEROULEMENT_H__
#define __DEROULEMENT_H__

#include "strategie.h"

/*déclaration des constantes de couleurs pour les prompts*/
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

/* Prototype de la fonction promptChampion(Duel d, Camp *Camp_Legumes, Camp *Camp_Fruits) */
void promptChampion(Duel d, Camp *Camp_Legumes, Camp *Camp_Fruits);
/* Prototype de la fonction promptMove(Duel d) */
void promptMove(Duel d);
/* Prototype de la fonction promptChoix(Duel d) */
void promptChoix(Duel d);
/* Prototype de la fonction promptWeapon(Duel d) */
void promptWeapon(Duel d);
/* Prototype de la fonction promptProtection(Duel d) */
void promptProtection(Duel d);
/* Prototype de la fonction promptCare(Duel d) */
void promptCare(Duel d);
/* Prototype de la fonction menuPrincipal() */
void menuPrincipal();
/* Prototype de la fonction menuDuels() */
void menuDuels();
/* Prototype de la fonction menuCamps() */
void menuCamps();
/* Prototype de la fonction menuChampions() */
void menuChampions();
/* Prototype de la fonction menuEquipements() */
void menuEquipements();
/* Prototype de la fonction menuCommandes() */
void menuCommandes();
/* Prototype de la fonction menucommandesStrat() */
void menucommandesStrat();
/* Prototype de la fonction deroulement(Duel*d, Camp* Legumes, Camp* Fruits,char** plateau) */
void deroulement(Duel*d, Camp* Legumes, Camp* Fruits,char** plateau);
/* Prototype de la fonction stratDeroulement(Duel *d, Camp* Legumes, Camp* Fruits, char** plateau) */
void stratDeroulement(Duel *d, Camp* Legumes, Camp* Fruits, char** plateau);
/* Prototype de la fonction finJeu(Duel d, Camp* Legumes, Camp* Fruits) */
void finJeu(Duel d, Camp* Legumes, Camp* Fruits);
/* Prototype de la fonction Jeu() */
void Jeu();


#endif
