/*deroulement.c*/
#include "deroulement.h"



/*
 * Fonction qui permet d'afficher le prompt de chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Camp_Fruits - Camp* (type déclaré dans le fichier init.h)
 * @return : void
 */

void promptChampion (Duel d, Camp* Camp_Legumes, Camp* Camp_Fruits) {
  if (d.tour == 1) {
      printf(GRN "%s %d>" RESET, d.c1.variete, Camp_Legumes->CA);
  } else if (d.tour == 2) {
      printf(YEL "%s %d>" RESET, d.c2.variete, Camp_Fruits->CA);
  }
}

/* Fonction qui permet d'afficher le prompt de déplacement pour chaque champion.
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 */

void promptMove (Duel d) {
  if (d.tour == 1) {
      printf(GRN "move>" RESET);
  } else if (d.tour == 2) {
      printf(YEL "move>" RESET);
  }
}


/*
 * Fonction qui permet d'afficher le prompt de choix dans les menus hors duel pour chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void promptChoix (Duel d) {
  if (d.tour == 1) {
      printf(GRN "choix>" RESET);
  } else if (d.tour == 2) {
      printf(YEL "choix>" RESET);
  }
}


/*
 * Fonction qui permet d'afficher le prompt d'utilisation d'arme pour chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void promptWeapon (Duel d) {
  if (d.tour == 1) {
      printf(GRN "useWeapon>" RESET);
  } else if (d.tour == 2) {
      printf(YEL "useWeapon>" RESET);
  }
}


/*
 * Fonction qui permet d'afficher le prompt d'utilisation de protection pour chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void promptProtection (Duel d) {
  if (d.tour == 1) {
      printf(GRN "useProtection>" RESET);
  } else if (d.tour == 2) {
      printf(YEL "useProtection>" RESET);
  }
}


/*
 * Fonction qui permet d'afficher le prompt d'utilisation de soin pour chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void promptCare (Duel d) {
  if (d.tour == 1) {
      printf(GRN "useCare>" RESET);
  } else if (d.tour == 2) {
      printf(YEL "useCare>" RESET);
  }
}


/*
 * Fonction qui permet d'afficher le menu principal du jeu.
 *
 * @param : void
 * @return : void
 *
 */

void menuPrincipal () {
  printf("Bienvenue dans la Guerre des Cultures!!!\n");
  printf("Que voudriez-vous faire?\n");
  printf("a - Commencer un duel.\n");
  printf("b - Afficher les camps.\n");
  printf("c - Afficher les champions.\n");
  printf("d - Afficher les équipements.\n");
  printf("e - Afficher le plateau de jeu.\n");
  printf("q - Quitter.\n");
}


/*
 * Fonction qui permet d'afficher le menu des duels.
 *
 * @param : void
 * @return : void
 *
 */

void menuDuels() {
  printf("Quel type de duel choisissez-vous?\n");
  printf("1 - Duel dynamique.\n");
  printf("2 - Duel avec stratégie.\n");
}



/*
 * Fonction qui permet d'afficher les camps.
 *
 * @param : void
 * @return : void
 *
 */

void menuCamps() {
  printf("1 : Camp des Fruits.\n");
  printf("2 : Camp des Légumes.\n");
}


/*
 * Fonction qui permet d'afficher les champions avec leurs caractéristiques détaillés.
 *
 * @param : Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Fruits - Camp* (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void menuChampions(Camp* Legumes, Camp* Fruits) {
  int n,i;
  menuCamps();
  printf("Choisissez le Camp : ");
  scanf("%d",&i);
  while ((i != 1) && (i != 2)) {
    printf("\nEntrée invalide. Réessayez!\n");
    printf("Votre choix :");
    scanf("%d",&i);
  }
  if (i==1) {
    showFruits(Fruits);
    printf("Afficher les détails sur un fruit? (1 : oui /0 : non)");
    scanf("%d",&n);
    while ((n != 1) && (n != 0)) {
      printf("\nEntrée invalide. Réessayez!\n");
      scanf("%d",&n);
    }
    if (n == 1) {
      printf("Veuillez entrer l'identifiant du fruit : ");
      scanf("%d",&n);
      while ((n < 1) || (n > nbMembres)) {
        printf("\nEntrée invalide. Réessayez!\n");
        scanf("%d",&n);
      }
      showFruit(n-1,Fruits);
    }

  } else if (n == 2) {
    showVegetables(Legumes);
    printf("Afficher les détails sur un légume? (1 : oui /0 : non)");
    scanf("%d",&n);
    if (n == 1) {
      printf("Veuillez entrer l'identifiant du légume : ");
      scanf("%d",&n);
      while ((i < 1) || (i > nbMembres)) {
        printf("\nEntrée invalide. Réessayez!\n");
        scanf("%d",&n);
      }
      showVegetable(n-1,Legumes);
    }
  }
}



/*
 * Fonction qui permet d'afficher les équipements existants avec leurs caractéristiques détaillés.
 *
 * @param : void
 * @return : void
 *
 */
void menuEquipements () {
  int n,i;
  printf("Choisissez le type d'équipement : \n1. Armes\t 2.Protections\t 3.Soins\n");
  scanf("%d",&n);
  while ((n < 1) || (n > 3)) {
    printf("Entrée invalide!");
    scanf("%d",&n);
  }
  if (n == 1) {
    showWeapons();
    printf("Afficher les détails d'une arme? (1 : oui / 0 : non)");
    scanf("%d",&i);
    while ((i != 1) && (i != 0)) {
      printf("\nEntrée invalide. Réessayez!\n");
      scanf("%d",&i);
    }
    if (i == 1) {
      printf("Veuillez entrer l'identifiant de l'arme : ");
      scanf("%d",&i);
      while ((i < 1) || (i > nbArmes)) {
        printf("\nEntrée invalide. Réessayez!\n");
        scanf("%d",&i);
      }
      showWeapon(i-1);
    }
  } else if (n == 2) {
    showProtections();
    printf("Afficher les détails d'une protection? (1 : oui / 0 : non)");
    scanf("%d",&i);
    while ((i != 1) && (i != 0)) {
      printf("\nEntrée invalide. Réessayez!\n");
      scanf("%d",&i);
    }
    if (i == 1) {
      printf("Veuillez entrer l'identifiant de la protection : ");
      scanf("%d\n",&i);
      while ((i < 1) || (i > nbProtections)) {
        printf("\nEntrée invalide. Réessayez!\n");
        scanf("%d",&i);
      }
      showProtection(i-1);
    }

  } else if (n == 3) {
    showCares();
    printf("Afficher les détails d'un soin? (1 : oui / 0 : non)");
    scanf("%d",&i);
    while ((i != 1) && (i != 0)) {
      printf("\nEntrée invalide. Réessayez!\n");
      scanf("%d",&i);
    }
    if (i == 1) {
      printf("Veuillez entrer l'identifiant du soin : ");
      scanf("%d\n",&i );
      while ((i < 1) || (i > nbSoins)) {
        printf("\nEntrée invalide. Réessayez!\n");
        scanf("%d",&i);
      }
      showCare(i-1);
    }
  }
}


/*
 * Fonction qui permet d'afficher les commandes du duel interactif (dynamique).
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 *
 */
 
void menuCommandes () {
  printf("Quelle action voulez vous faire?\n");
  printf("1 - Avancer.\n");
  printf("2 - Reculer.\n");
  printf("3 - Tirer.\n");
  printf("4 - Utiliser un soin.\n");
  printf("5 - Utiliser une protection.\n");
  printf("6 - Arrêter le duel.\n\n");
}



/*
 * Fonction qui permet d'afficher les commandes d'un suel de startégie.
 *
 * @param : void
 * @return : void
 *
 */

void menucommandesStrat() {
  printf("Que voulez-vous faire?\n");
  printf("1 - Lancer un duel.\n");
  printf("2 - Afficher les statégies.\n");
  printf("3 - Afficher la description d'une stratégie.\n");

}



/*
 * Fonction qui permet d'implémenter la boucle du déroulement d'un duel dynamique.
 *
 * @param : d - Duel*
 *          Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Fruits - Camp* (type déclaré dans le fichier init.h)
 *          plateau - char**
 * @return : void
 *
 */

void deroulement (Duel *d, Camp* Legumes, Camp* Fruits, char** plateau) {
  int n,i;
  fight(d,Legumes,Fruits);
  int finDuel = 0;
  d->tour = 1;
  while (!finDuel) {
    menuCommandes();
    promptChampion(*d,Legumes,Fruits);
    scanf("%d",&n);
    while ((n < 1) || (n > 6)) {
      printf("\nValeur non prise en compte!\n");
      promptChampion(*d,Legumes,Fruits);
      scanf("%d",&n);
    }
    if (n == 1) {
        promptMove(*d);
        scanf("%d",&i);
        moveforward(d,Legumes,Fruits,&i);
    } else if (n == 2) {
        promptMove(*d);
        scanf("%d",&i);
        movebackward(d,Legumes,Fruits,&i);
    } else if (n == 3) {
        promptWeapon(*d);
        scanf("%d",&i);
        useweapon(d,Legumes,Fruits,&i);
    } else if (n == 4) {
        promptCare(*d);
        scanf("%d",&i );
        usecare(d,Legumes,Fruits,&i);
    } else if (n == 5) {
        promptProtection(*d);
        useprotection(d,Legumes,Fruits);
    } else if (n == 6) {
        finDuel = 1;
    }
    system("clear");
    reinitPlateau(d,plateau);
    affichagePlateau(plateau);
    show(*d);
    if (d->tour == 1) {
      d->tour = 2;
      printf("Au tour du Fruit. \n");
    } else if (d->tour == 2) {
      d->tour = 1;
      printf("Au tour du Légume. \n");
    }
  }
  if ((Legumes->CA == 0) || (Fruits->CA == 0)) {
    end(d,Legumes,Fruits);
  }
}



/*
 * Fonction qui permet d'implémenter la boucle du déroulement d'un duel de stratégie.
 *
 * @param : d - Duel*
 *          Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Fruits - Camp* (type déclaré dans le fichier init.h)
 *          plateau - char**
 * @return : void
 *
 */

void stratDeroulement(Duel *d, Camp* Legumes, Camp* Fruits, char** plateau) {
  int n,i;
  int finDuel = 0;
  d->tour = 1;
  menucommandesStrat();
  printf("choix> ");
  scanf("%d",&n);
  while ((n < 1) || (n > 3)) {
    printf("\nValeur non prise en compte!\n");
    printf("choix> ");
    scanf("%d",&n);
  }
  while (!finDuel) {
    if (n == 1) {
      showStrategies();
      printf("Choisissez la startégie utilisée par le Légume : ");
      scanf("%d",&i);
      Strat s1 = tabStrat[i-1];
      printf("Choisissez la startégie utilisée par le Fruit : ");
      scanf("%d",&i);
      Strat s2 = tabStrat[i-1];
      fightStrat(s1,s2,d,Legumes,Fruits,plateau);
    } else if (n == 2) {
      showStrategies();
      printf("Veuillez entrer l'identifiant de la stratégie : ");
      scanf("%d",&i);
      showStrategie(i);
    } else if (n == 3) {
      showStrategies();
    }
  }
}


/*
 * Fonction qui permet de détecter la fin du jeu.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 *          Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Fruits - Camp* (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void finJeu (Duel d, Camp* Legumes, Camp* Fruits) {
  int c;
  if (Legumes->CE == 0) {
   printf("Félicitations aux Légumes!!! les Fruits ont perdus.");
   printf("Le champion de ce combat est : %s.\n", d.c1.variete);
 } else if (Fruits->CE == 0) {
   printf("Félicitations aux Fruits!!! les Légumes ont perdus.\n");
   printf("Le champion de ce combat est : %s.\n", d.c2.variete);
 }
 printf("Voulez-vous recommencer? (1 : oui / 0 : non)");
 scanf("%d",&c);
 while (c != 0 && c != 1) {
   printf("\nEntrée invalide. Réessayez!\n");
 }
 if (c == 1) {Jeu();}
 else if (c == 0) {printf("À bientôt!"); exit(1);}
}



/*
 * Fonction qui permet d'implémenter la boucle du déroulement pricipal du jeu.
 *
 * @param : void
 * @return : void
 *
 */

void Jeu() {
  initArmes(tabArmes);
  initProtections(tabProtects);
  initSoins(tabSoins);
  char** plateau = nouveauPlateau();
  Camp* Legumes = CampLegumes();
  Camp* Fruits = CampFruits();
  Duel* duel = malloc(sizeof(Duel));
  int boolFin = 0;
  char choix;

  duel->c1.boolGagner = -1;
  duel->c2.boolGagner = -1;

  while (!boolFin) {
    menuPrincipal();
    printf("choix> ");
    scanf("%c",&choix);
    while ((choix < 'a') || ((choix > 'e') && (choix != 'q'))) {
      printf("\nValeur non prise en compte!\n");
      printf("choix> ");
      scanf("%c",&choix);
    }
    system("clear");
    if (choix == 'a') {
            int chx;
            menuDuels();
            scanf("%d", &chx);
            if (chx == 1) {
              deroulement(duel,Legumes,Fruits,plateau);
            } else if (chx == 2) {
              stratDeroulement(duel,Legumes,Fruits,plateau);
            }
    } else if (choix == 'b') {
            menuCamps();
    } else if (choix == 'c') {
            menuChampions(Legumes,Fruits);
    } else if (choix == 'd') {
            menuEquipements();
    } else if (choix == 'e') {
            affichagePlateau(plateau);
    } else if (choix == 'q') {
            exit(1);
    } else {
            printf("Choix invalide non pris en compte!");
    }
    if ((!Legumes->CE) || (!Fruits->CE)) {
      boolFin = 1;
    }
  }
  finJeu(*duel,Legumes,Fruits);
  free(Legumes->membres);
  free(Fruits->membres);
  free(plateau);
  free(Legumes);
  free(Fruits);
  free(duel);

}
