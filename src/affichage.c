/*affichage.c*/
#include "affichage.h"



/*
 * Fonction qui permet d'afficher les membres(variétés) appartenant au camp des fruits.
 *
 * @param : Camp_Fruits - Camp* (pointeur de Camp - type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void showFruits(Camp* Camp_Fruits){
	printf("La liste des fruits: \n");
	int i;
	for(i=0;i<nbMembres;i++){
		printf("%d : %s\n",i+1,Camp_Fruits->membres[i].variete);
	}
}


/*
 * Fonction qui permet d'afficher un membre précis appartenant au camp des fruits à partir de son identifiant passé en argument.
 *     Elle permet aussi d'afficher ses caractéristiques et ses équipements.
 *
 * @param : i - int
 *          Camp_Fruits - Camp* (pointeur de Camp - type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void showFruit(int i, Camp* Camp_Fruits){
	printf("Nom : %s\ntype : %s\nForce : %d\nRésistance : %d\nPV_max : %d\ncout_CE : %d\n",
							Camp_Fruits->membres[i].variete,Camp_Fruits->membres[i].type,Camp_Fruits->membres[i].force,
							Camp_Fruits->membres[i].resistance,Camp_Fruits->membres[i].PV_max,Camp_Fruits->membres[i].cout_CE);
	}


/*
 * Fonction qui permet d'afficher les membres(variétés) appartenant au camp des legumes.
 *
 * @param : Camp_Legumes - Camp* (pointeur de Camp - type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void showVegetables(Camp* Camp_Legumes){
	printf("La liste des légumes: \n");
	int i;
	for(i=0;i<nbMembres;i++){
		printf("%d : %s\n",i+1,Camp_Legumes->membres[i].variete);
	}
}


/*
 * Fonction qui permet d'afficher un membre précis appartenant au camp des légumes à partir de son identifiant passé en argument.
 *     Elle permet aussi d'afficher ses caractéristiques et ses équipements.
 *
 * @param : i - int
 *          Camp_Legumes - Camp* (pointeur de Camp - type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void showVegetable(int i, Camp* Camp_Legumes){
	printf("Nom : %s\ntype : %s\nForce : %d\nRésistance : %d\nPV_max : %d\ncout_CE : %d\n",
						Camp_Legumes->membres[i].variete,Camp_Legumes->membres[i].type,Camp_Legumes->membres[i].force,
						Camp_Legumes->membres[i].resistance,Camp_Legumes->membres[i].PV_max,Camp_Legumes->membres[i].cout_CE);
	}


/*
 * Fonction qui permet d'afficher les armes avec leur identifiants.
 *
 * @param : void
 * @return : void
 *
 */

void showWeapons(){
	printf("La liste des armes: \n");
	int i;
	for(i=0;i<nbArmes;i++){
		printf("%d : %s\n",i+1,tabArmes[i].nom);
	}
}


/*
 * Fonction qui permet d'afficher une arme dont l'dentifiant est passé en argument avec ses caractéristiques.
 *
 * @param : i - int
 * @return : void
 *
 */

void showWeapon(int i){
	printf("Nom : %s\ncout-CE : %d\ncout_CA : %d\nportee : %d\ndégat 1 : %d\ndégat 2 : %d\n",
						tabArmes[i].nom,tabArmes[i].cout_CE,tabArmes[i].cout_CA,tabArmes[i].portee,tabArmes[i].degats[0],tabArmes[i].degats[1]);
}


/*
 * Fonction qui permet d'afficher les protections avec leurs identifiants.
 *
 * @param : void
 * @return : void
 *
 */

void showProtections(){
	printf("La liste des protections: \n");
	int i;
	for(i=0;i<nbProtections;i++){
		printf("%d : %s\n",i+1,tabProtects[i].nom);
	}
}


/*
 * Fonction qui permet d'afficher une protection dont l'dentifiant est passé en argument avec ses caractéristiques.
 *
 * @param : i - int
 * @return : void
 *
 */

void showProtection(int i){
	printf("Nom : %s\ncout_CE : %d\ncout_CA : %d\nportabilite : %d\n",tabProtects[i].nom,tabProtects[i].cout_CE,
					 tabProtects[i].cout_CA,tabProtects[i].portabilite);
}


/*
 * Fonction qui permet d'afficher les soins avec leurs identifiants.
 *
 * @param : void
 * @return : void
 *
 */

void showCares(){
	printf("La liste des Soins: \n");
	int i;
	for(i=0;i<nbSoins;i++){
		printf("%d : %s\n",i+1,tabSoins[i].nom);
	}
}


/*
 * Fonction qui permet d'afficher un soin dont l'dentifiant est passé en argument avec ses caractéristiques.
 *
 * @param : i - int
 * @return : void
 *
 */

void showCare(int i){
	printf("cout_CE : %s\ncout_CA : %d\nvolume : %d\neffet 1 : %d\neffet 2 : %d\n",tabSoins[i].nom,tabSoins[i].cout_CE,
					tabSoins[i].cout_CA,tabSoins[i].effet[0],tabSoins[i].effet[1]);
	}
