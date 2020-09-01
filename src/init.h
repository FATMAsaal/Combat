/*init.h*/
#ifndef __INIT_H__
#define __INIT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dirent.h>
#include <ctype.h>
/*#include <SDL/SDL.h>*/   /*bibliothèque pour le timer*/
#include <sys/types.h>
#include <sys/ioctl.h>


#define CE_camp 1000
#define CA_camp 50

#define nbMembres 6
#define nbArmes 5
#define nbProtections 4
#define nbSoins 3




/* Prototype de la structure permettant de définir un arme */
typedef struct _arme {
	char* nom;
	int cout_CE;
	int cout_CA;
	int degats[2];
	int portee;
} Arme;



/* Prototype de la structure permettant de définir une protection*/
typedef struct _protection {
	char* nom;
	int bool; /*indique si la protection est "activée" ou pas*/
	int cout_CE;
	int cout_CA;
	int portabilite;
} Protection;


/* Prototype de la structure permettant de définir un soin*/
typedef struct _soin {
	char* nom;
	int cout_CE;
	int cout_CA;
	int volume;
	int effet[2]; /*ça prend deux entiers pour former un intervalle*/
} Soin;

/* Prototype de la structure permettant de définir un champion */
typedef struct _champion {
	char* type;
	char* variete;
	int force;
	int resistance;
	int PV_max;
	int PV_restant;
	int cout_CE;
	int nbDuels;
	int boolGagner; /*-1 état initial, 0 s'il perd et 1 s'il gagne*/
	Arme arme;
	Protection protection;
	Soin soin;
} Champion;


/* Prototype de la structure permettant de définir un camp */
typedef struct _camp {
	char* type;
	Champion* membres;
	int nb_membres;
	int CE;
	int CA;
} Camp;

/* Prototype de la structure permettant de définir la position d'un champion sur le plateau*/
typedef struct _pos {
	int x;
	int y;
} Position;

/* Prototype de la structure permettant de définir un duel entre deux champions */
typedef struct _duel {
	Champion c1;
	Position pos1;
	Champion c2;
	Position pos2;
	int tour;
} Duel;


/* déclaration de tableaux statiques contenant les équipements*/
Arme tabArmes[nbArmes];
Protection tabProtects[nbProtections];
Soin tabSoins[nbSoins];




/* Prototype de la fonction initFruit() */
Champion* initFruit();
/* Prototype de la fonction initLegumes() */
Champion* initLegumes();
/* Prototype de la fonction initProtections(Protection* tabProtects) */
void initProtections(Protection* tabProtects);
/* Prototype de la fonction initArmes(Arme* tabArmes) */
void initArmes(Arme* tabArmes);
/* Prototype de la fonction initSoins(Soin* tabSoins) */
void initSoins(Soin* tabSoins);
/* Prototype de la fonction CampFruits() */
Camp* CampFruits();
/* Prototype de la fonction CampLegumes() */
Camp* CampLegumes();

#endif
