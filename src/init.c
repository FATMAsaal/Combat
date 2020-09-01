/*init.c*/
#include "init.h"

/* déclaration des tableaux de chaines de caractères statiques */
char* Type[] = {"FRUIT","LEGUME"};
char* Fruits[] = {"BANANE","KIWI","POIRE","POMME","ANANAS","DURIAN"};
char* Legumes[] = {"HARICOT","FENOUIL","POIREAU","AUBERGINE","COURGETTE","CAROTTE"};
char* Armes[] = {"EPLUCHEUR_LASER","MANDOLINE_SONIQUE","COUPERET","HACHOIR_NEURONIQUE","MIXEUR_BLASTER"};
char* Protections[]= {"CASQUE_EGOUTTOIR","CASQUE_ENTONNOIR","WOKLIER","TABLIER_ARMURE"};
char* Soins[] = {"HUMUS_NEUTRONIQUE","COMPOST_PROTONIQUE","ENGRAIS_IONIQUE"};



/*
 * Fonction qui permet de retourner un tableau de champions "FRUIT" initialisés avec leurs compteurs .
 *
 * @param : void
 * @return : Champion* (un tableau de Champion - type déclaré dans le fichier init.h)
 *
 */

Champion* initFruits(){
	int i;
	Champion* campF = malloc(6*sizeof(Champion));
	for(i=0;i<6;i++){
		campF[i].type = Type[0];
    campF[i].variete = Fruits[i];
	}
	campF[0].force = 10; campF[0].resistance = 10; campF[0].PV_max = 40; campF[0].PV_restant = 40; campF[0].cout_CE = 5; campF[0].nbDuels = 0; campF[0].boolGagner = -1;
  campF[1].force = 12; campF[1].resistance = 15; campF[1].PV_max = 40; campF[1].PV_restant = 40; campF[1].cout_CE = 7; campF[1].nbDuels = 0; campF[1].boolGagner = -1;
  campF[2].force = 15; campF[2].resistance = 20; campF[2].PV_max = 60; campF[2].PV_restant = 60; campF[2].cout_CE = 10; campF[2].nbDuels = 0; campF[2].boolGagner = -1;
  campF[3].force = 20; campF[3].resistance = 20; campF[3].PV_max = 60; campF[3].PV_restant = 60; campF[3].cout_CE = 15; campF[3].nbDuels = 0; campF[3].boolGagner = -1;
  campF[4].force = 20; campF[4].resistance = 25; campF[4].PV_max = 80; campF[4].PV_restant = 80; campF[4].cout_CE = 20; campF[4].nbDuels = 0; campF[4].boolGagner = -1;
  campF[5].force = 25; campF[5].resistance = 25; campF[5].PV_max = 80; campF[5].PV_restant = 80; campF[5].cout_CE = 25; campF[5].nbDuels = 0; campF[5].boolGagner = -1;
	return campF;
}


/*
 * Fonction qui permet de retourner un tableau de champions "LEGUME" initialisés avec leurs compteurs .
 *
 * @param : void
 * @return : Champion* (un tableau de Champion - type déclaré dans le fichier init.h)
 *
 */

Champion* initLegumes() {
  int i;
	Champion* campL=malloc(6*sizeof(Champion));
	for(i=0;i<6;i++){
    campL[i].type = Type[1];
    campL[i].variete = Legumes[i];
  }

  campL[0].force = 10; campL[0].resistance = 10; campL[0].PV_max = 40; campL[0].PV_restant = 40; campL[0].cout_CE = 5; campL[0].nbDuels = 0; campL[0].boolGagner = -1;
  campL[1].force = 12; campL[1].resistance = 15; campL[1].PV_max = 40; campL[1].PV_restant = 40; campL[1].cout_CE = 7; campL[1].nbDuels = 0; campL[1].boolGagner = -1;
  campL[2].force = 15; campL[2].resistance = 20; campL[2].PV_max = 60; campL[2].PV_restant = 60; campL[2].cout_CE = 10; campL[2].nbDuels = 0; campL[2].boolGagner = -1;
  campL[3].force = 20; campL[3].resistance = 20; campL[3].PV_max = 60; campL[3].PV_restant = 60; campL[3].cout_CE = 15; campL[3].nbDuels = 0; campL[3].boolGagner = -1;
  campL[4].force = 20; campL[4].resistance = 25; campL[4].PV_max = 80; campL[4].PV_restant = 80; campL[4].cout_CE = 20; campL[4].nbDuels = 0; campL[4].boolGagner = -1;
  campL[5].force = 25; campL[5].resistance = 25; campL[5].PV_max = 80; campL[5].PV_restant = 80; campL[5].cout_CE = 25; campL[5].nbDuels = 0; campL[5].boolGagner = -1;
	return campL;
}


/*
 * Fonction qui permet de retourner un tableau d'armes initialisés avec leurs compteurs .
 *
 * @param : Arme* (un tableau de Arme - type déclaré dans le fichier init.h)
 * @return : Arme* (tableau de Arme - modifié)
 *
 */

void initArmes(Arme* tabArmes) {
  int i;
	for(i=0;i<5;i++){
    tabArmes[i].nom = Armes[i];
  }

	tabArmes[0].cout_CE = 2; tabArmes[0].cout_CA = 1;  tabArmes[0].portee = 2;  tabArmes[0].degats[0] = 1; tabArmes[0].degats[1] = 2;
  tabArmes[1].cout_CE = 5;  tabArmes[1].cout_CA = 3;  tabArmes[1].portee = 3; tabArmes[1].degats[0] = 1; tabArmes[1].degats[1] = 3;
  tabArmes[2].cout_CE = 10; tabArmes[2].cout_CA = 5;  tabArmes[2].portee = 5; tabArmes[2].degats[0] = 2; tabArmes[2].degats[1] = 6;
  tabArmes[3].cout_CE = 20; tabArmes[3].cout_CA = 7;  tabArmes[3].portee = 7; tabArmes[3].degats[0] = 4; tabArmes[3].degats[1] = 9;
  tabArmes[4].cout_CE = 30; tabArmes[4].cout_CA = 10; tabArmes[4].portee = 11;tabArmes[4].degats[0] = 7; tabArmes[4].degats[1] = 12;
}


/*
 * Fonction qui permet de retourner un tableau de protections initialisés avec leurs compteurs .
 *
 * @param : Protection* (un tableau de Protection - type déclaré dans le fichier init.h)
 * @return : Protection* (tableau de Protection - modifié)
 *
 */

void initProtections(Protection* tabProtects) {
  int i;
	for(i=0;i<4;i++){
    tabProtects[i].nom = Protections[i];
  }

	 tabProtects[0].cout_CE = 1;  tabProtects[0].cout_CA = 2; tabProtects[0].portabilite = 25;
   tabProtects[1].cout_CE = 3;  tabProtects[0].cout_CA = 4; tabProtects[0].portabilite = 40;
   tabProtects[2].cout_CE = 5;  tabProtects[0].cout_CA = 6; tabProtects[0].portabilite = 60;
   tabProtects[3].cout_CE = 10; tabProtects[0].cout_CA = 8; tabProtects[0].portabilite = 80;
}


/*
 * Fonction qui permet de retourner un tableau de soins initialisés avec leurs compteurs .
 *
 * @param : Soin* (un tableau de Soin - type déclaré dans le fichier init.h)
 * @return : Soin* (tableau deSoin - modifié)
 *
 */

void initSoins(Soin* tabSoins) {
  int i;
	for(i=0;i<3;i++){
    tabSoins[i].nom = Soins[i];
  }
	tabSoins[0].cout_CE = 1; tabSoins[0].cout_CA = 5;  tabSoins[0].volume = 4; tabSoins[0].effet[0] = 2; tabSoins[0].effet[1] = 4;
  tabSoins[1].cout_CE = 5; tabSoins[1].cout_CA = 10; tabSoins[1].volume = 3; tabSoins[1].effet[0] = 5; tabSoins[1].effet[1] = 8;
  tabSoins[2].cout_CE = 7; tabSoins[2].cout_CA = 15; tabSoins[2].volume = 2; tabSoins[2].effet[0] = 8; tabSoins[2].effet[1] = 12;
}


/*
 * Fonction qui permet de retourner un camp de legumes initialisé avec ses compteurs et sa liste de membres.
 *
 * @param : void
 * @return : Camp* (pointeur de Camp - type déclaré dans le fichier init.h)
 *
 */

Camp* CampLegumes () {
	Camp* c = malloc(sizeof(Camp));
	c->type = Type[1];
	c->membres = initLegumes();
	c->nb_membres = nbMembres;
	c->CE = CE_camp;
	c->CA = CA_camp;
	return c;
}


/*
 * Fonction qui permet de retourner un camp de fruits initialisé avec ses compteurs et sa liste de membres.
 *
 * @param : void
 * @return : Camp* (pointeur de Camp - type déclaré dans le fichier init.h)
 *
 */

Camp* CampFruits () {
	Camp* c=malloc(sizeof(Camp));
	c->type = Type[0];
	c->membres = initFruits();
	c->nb_membres = nbMembres;
	c->CE = CE_camp;
	c->CA = CA_camp;
	return c;
}
