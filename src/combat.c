/*combat.c*/
#include "combat.h"



/*
 * Fonction qui permet d'affecter au duel un champion choisis dans un camp donné. (fonction utilisée dans la fonction fight)
 *
 * @param : c - Champion* (type déclaré dans le fichier init.h)
 *          camp - Camp* (type déclaré dans le fichier init.h)
 *          i - int
 * @return : void
 *
 */

 void choixChampion (Champion* c, Camp* camp, int i) {
     if (camp->CE >= camp->membres[i-1].cout_CE) {
         *c = camp->membres[i-1];
         camp->CE -= c->cout_CE;
         printf("\nVous avez été débité de %d CE.\n", c->cout_CE);
     } else {
         printf("\nAttention! CE insuffisants! \n");
   }
 }

/*
 * Fonction qui permet d'affecter à un champion une arme choisie. (fonction utilisée dans la fonction fight)
 *
 * @param : c - Champion* (type déclaré dans le fichier init.h)
 *          camp - Camp* (type déclaré dans le fichier init.h)
 *          i - int
 * @return : void
 *
 */
void choixArme (Champion* c, Camp* camp, int i) {
  if (i != -1) {
    if (camp->CE >= tabArmes[i-1].cout_CE){
      c->arme = tabArmes[i-1];
      camp->CE -= tabArmes[i-1].cout_CE;
      printf("\nVous avez été débité de %d CE.\n", tabArmes[i-1].cout_CE);
    } else {
      printf("\nAttention! CE insuffisants!\n");
    }
  } else {
    printf("\nVous n'avez fait aucun choix d'arme.\n");
  }
}


/*
 * Fonction qui permet d'affecter à un champion une protection choisie. (fonction utilisée dans la fonction fight)
 *
 * @param : c - Champion* (type déclaré dans le fichier init.h)
 *          camp - Camp* (type déclaré dans le fichier init.h)
 *          i - int
 * @return : void
 *
 */

void choixProtection (Champion* c, Camp* camp, int i) {

    if (i != -1) {
      if (camp->CE >= tabProtects[i-1].cout_CE){
        c->protection = tabProtects[i-1];
        camp->CE -= tabProtects[i-1].cout_CE;
        printf("\nVous avez été débité de %d CE.\n", tabProtects[i-1].cout_CE);
      } else {
        printf("\nAttention! CE insuffisants!\n");
      }
    } else {
      printf("\nVous n'avez fait aucun chox de protection.\n");
    }
}


/*
 * Fonction qui permet d'affecter à un champion un soin choisi. (fonction utilisée dans la fonction fight)
 *
 * @param : c - Champion* (type déclaré dans le fichier init.h)
 *          camp - Camp* (type déclaré dans le fichier init.h)
 *          i - int
 * @return : void
 *
 */

void choixSoin (Champion* c, Camp* camp, int i) {
    if (i != -1) {
      if (camp->CE >= tabSoins[i-1].cout_CE){
        c->soin = tabSoins[i-1];
        camp->CE -= tabSoins[i-1].cout_CE;
        printf("\nVous avez été débité de %d CE.\n", tabSoins[i-1].cout_CE);
      } else {
        printf("\nAttention! CE insuffisants!\n");
      }
    } else {
      printf("\nVous n'avez fait aucun choix de soin.\n");
    }
}


/*
 * Fonction qui permet de traiter les achats de CA. (fonction utilisée dans la fonction fight)
 *
 * @param : camp - Camp* (type déclaré dans le fichier init.h)
 *          nb - int
 * @return : void
 *
 */

void achatCA (Camp* camp, int nb) {

    if (nb <= camp->CE) {
      camp->CE -= nb;
      printf("\nVous avez été débité de %d CE.\n", nb);
      camp->CA += nb;
      printf("Vous avez obtenu %d CA.\n", nb);
    } else {
      printf("\nAttention! Ce insuffisants!\n");
    }
  }


/*
 * Fonction qui permet d'initilaiser les éléments d'un duel donné en lui attribuant les champions et leurs équipements.
 *
 * @param : d - Duel* (type déclaré dans init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Camp_Fruits - Camp* (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void fight (Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits) {
  int chx, i, nb;

  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  Position p1;
  Position p2;

  p1.x = 0; p1.y = 0;
  p2.x = (w.ws_row/3)-1; p2.y = (w.ws_col/6)-1;
  d->pos1 = p1;
  d->pos2 = p2;

/* Initilisation du légume */
  /*choix champion L*/
  printf("Choix du Légume :\n\n");
  if (d->c1.boolGagner == -1) {
    showVegetables(Camp_Legumes);
    printf("Choisissez un légume :");
    scanf ("%d", &chx);
    while (chx > nbMembres || chx < 1 || !Camp_Legumes->membres[chx].boolGagner) {
      if (!Camp_Legumes->membres[chx].boolGagner) {
        printf("\nVous ne pouvez pas choisir ce légume. Il a déjà perdu. Choisissez un autre. \n");
      } else {
        printf("\nEntrée invalide! Réessayez.\n");
      }
      printf("Votre choix de légume est : ");
      scanf("%d", &chx);
    }
    choixChampion(&d->c1,Camp_Legumes,chx);

  } else {
    d->tour = 1;
    printf("\nVous avez déjà choisi votre champion.\n");
    show(*d);
  }
  printf("\n\n\n");

  /*choix arme du champion L*/
  printf("Choix d'arme :\n\n");
  for (i=0; i<nbArmes; i++) {
    printf("%d : %s - %d CE - %d CA \n", i+1, tabArmes[i].nom, tabArmes[i].cout_CE, tabArmes[i].cout_CA);
  }
  printf("Votre choix d'arme est : ");
  scanf("%d", &chx);
  while (chx > nbArmes || chx < -1 || !chx) {
    printf("\nEntrée invalide! Réessayez.\n");
    printf("Votre choix d'arme est : ");
    scanf("%d", &chx);
  }
  choixArme(&d->c1,Camp_Legumes,chx);
  printf("\n\n\n");

  /*choix protection du champion L*/
  printf("Choix de protection :\n\n");
  if ((d->c1.nbDuels)%2 == 0) {
    for (i=0; i<nbProtections; i++) {
      printf("%d : %s - %d CE - %d CA \n", i+1, tabProtects[i].nom, tabProtects[i].cout_CE, tabProtects[i].cout_CA);
    }
    printf("Votre choix de protection est : ");
    scanf("%d", &chx);
    while (chx > nbProtections || chx < -1 || !chx) {
      printf("\nEntrée invalide! Réessayez.\n");
      printf("Votre choix de protection est : ");
      scanf("%d", &chx);
    }
    choixProtection(&d->c1,Camp_Legumes,chx);
  } else {
    printf("Vous avez déjà une protection.\n");
  }
  printf("\n\n\n");

  /*choix soin du champion L*/
  printf("Choix de soin :\n\n");
    for (i=0; i<nbSoins; i++) {
      printf("%d : %s - %d CE - %d CA \n", i+1, tabSoins[i].nom, tabSoins[i].cout_CE, tabSoins[i].cout_CA);
    }
    printf("Votre choix de soin est : ");
    scanf("%d", &chx);
    while (chx > nbSoins || chx < -1 || !chx) {
      printf("\nEntrée invalide! Réessayez.\n");
      printf("Votre choix de soin est : ");
      scanf("%d", &chx);
    }
  choixSoin(&d->c1,Camp_Legumes,chx);
  printf("\n\n\n");

  /*achat CA pour le champion L*/
  printf("Achat des CA :\n\n");
  printf("Voulez vous achetez des CA? (1 : oui / 0 : non)\n");
  scanf ("%d",&chx);
  if (chx == 1) {
    printf("\nVeuillez entrer le nombre de CA que vous voulez acheter : ");
    scanf("%d",&nb);
    while (nb < 0) {
      printf("\nLe nombre entré est invalide.\n");
      printf("Veuillez entrer le nombre de CA que vous voulez acheter : ");
      scanf("%d",&nb);
    }
    achatCA(Camp_Legumes,nb);

  }
  system("clear");



/*initialisation du fruit*/
  /* choix champion F */
  printf("Choix du Fruit :\n\n");
  if (d->c2.boolGagner == -1) {
    showFruits(Camp_Fruits);
    printf("Choisissez un fruit : ");
    scanf("%d", &chx);
    while (chx > nbMembres || chx < 1 || !Camp_Fruits->membres[chx].boolGagner) {
      if (!Camp_Fruits->membres[chx].boolGagner) {
        printf("\nVous ne pouvez pas choisir ce fruit. Il a déjà perdu. Choisissez un autre. \n");
      } else {
        printf("\nEntrée invalide! Réessayez.\n");
      }
      printf("Votre choix de fruit est : ");
      scanf("%d", &chx);
    }
    choixChampion(&d->c2,Camp_Fruits,chx);
  } else {
    d->tour = 2;
    printf("\nVous avez déjà choisi votre champion.\n");
    show(*d);
  }
  printf("\n\n\n");

  /*choix arme du champion F*/
  printf("Choix d'arme :\n\n");
  for (i=0; i<nbArmes; i++) {
    printf("%d : %s - %d CE - %d CA \n", i+1, tabArmes[i].nom, tabArmes[i].cout_CE, tabArmes[i].cout_CA);
  }
  printf("Votre choix d'arme est : ");
  scanf("%d", &chx);
  while (chx > nbArmes || chx < -1 || !chx) {
    printf("\nEntrée invalide! Réessayez.\n");
    printf("Votre choix d'arme est : ");
    scanf("%d", &chx);
  }
  choixArme(&d->c2,Camp_Fruits,chx);
  printf("\n\n\n");

  /*choix protection du champion L*/
  printf("Choix de protection :\n\n");
  if (d->c2.nbDuels % 2 == 0) {
    for (i=0; i<nbProtections; i++) {
      printf("%d : %s - %d CE - %d CA \n", i+1, tabProtects[i].nom, tabProtects[i].cout_CE, tabProtects[i].cout_CA);
    }
    printf("Votre choix de protection est : ");
    scanf("%d", &chx);
    while (chx > nbProtections || chx < -1 || !chx) {
      printf("\nEntrée invalide! Réessayez.\n");
      printf("Votre choix de protection est : ");
      scanf("%d", &chx);
    }
    choixProtection(&d->c2,Camp_Fruits,chx);
  } else {
    printf("\nVous avez déjà une protection.\n");
  }
  printf("\n\n\n");

  /*choix soin du champion L*/
  printf("Choix de soin :\n\n");
  for (i=0; i<nbSoins; i++) {
    printf("%d : %s - %d CE - %d CA \n", i+1, tabSoins[i].nom, tabSoins[i].cout_CE, tabSoins[i].cout_CA);
  }
  printf("Votre choix de soin est : ");
  scanf("%d", &chx);
  while (chx > nbSoins || chx < -1 || !chx) {
    printf("\nEntrée invalide! Réessayez.\n");
    printf("Votre choix de soin est : ");
    scanf("%d", &chx);
  }
  choixSoin(&d->c2,Camp_Fruits,chx);
  printf("\n\n\n");

  /*achat CA pour le champion F*/
  printf("Achat des CA :\n\n");
  printf("Voulez vous achetez des CA? (1 : oui / 0 : non)\n");
  scanf ("%d",&chx);
  if (chx == 1) {
    printf("\nVeuillez entrer le nombre de CA que vous voulez acheter : ");
    scanf("%d",&nb);
    while (nb < 0) {
      printf("\nLe nombre entré est invalide.\n");
      printf("Veuillez entrer le nombre de CA que vous voulez acheter : ");
      scanf("%d",&nb);
    }
    achatCA(Camp_Fruits,nb);
  }
  system("clear");

}

/*
 * Fonction qui permet d'afficher les champions d'un duel donné et leurs équipements.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 * @return : void
 *
 */

void show (Duel d) {
  if (d.tour == 1) {
    printf("Champion : %s \n\tForce : %d \tResistance : %d \tPV : %d \tSoin : %d \tArme : %d \tProtection : %d \n",
              d.c1.variete,d.c1.force, d.c1.resistance,d.c1.PV_restant,d.c1.soin.cout_CE,d.c1.arme.cout_CE,d.c1.protection.cout_CE);
  } else {
    printf("Champion : %s \n\tForce : %d \tResistance : %d \tPV : %d \tSoin : %d \tArme : %d \tProtection : %d \n",d.c2.variete,d.c2.force, d.c2.resistance,d.c2.PV_restant,d.c2.soin.cout_CE,d.c2.arme.cout_CE,d.c2.protection.cout_CE
  );
  }
}





/*
 * Fonction qui permet de traiter l'avancement de chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fonction init.h)
 *          Camp_Fruits - Camp* (type déclaré dans la fonction init.h)
 *          n - int*
 * @return : void
 *
 */

void moveforward (Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int* n) {
  int c;
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);
  if (n == NULL) {
    *n = 1;
  }

  if (((d->tour == 1) && ((Camp_Legumes->CA - (*n))<0)) || ((d->tour == 2) && ((Camp_Fruits->CA - (*n))<0))){
      printf("Attention vous n'avez pas assez de CA pour vous déplacer vers l'avant!\n");
  } else {
        if (d->tour == 1) {
            printf("Voulez-vous vous déplacer horizontalement (vers la droite : 1) ou verticalement(vers le bas : 2)?\n");
            printf("Votre choix :");
            scanf("%d",&c);
            while ((c != 1) && (c != 2)) {
              printf("\nEntrée invalide. Réessayez!\n");
              printf("Votre choix :");
              scanf("%d",&c);
            }
            if ((c==1) && ((d->pos1.y)+*n < (w.ws_row/3)-1) && ((d->pos1.y)+*n < d->pos2.y)) {
                d->pos1.y += *n;
                Camp_Legumes->CA-= *n ;
                printf("\nVous avez été débité de %d CA.\n", *n);
            } else if ((c==2) && ((d->pos1.x)+*n < (w.ws_col/6)-1) && ((d->pos1.x)+*n < d->pos2.x)) {
                d->pos1.x += *n;
                Camp_Legumes->CA-= *n ;
                printf("\nVous avez été débité de %d CA.\n", *n);
            } else {
              printf("\nVotre déplacement est impossible.\n");
            }


        } else if (d->tour == 2) {
                printf("Voulez-vous vous déplacer horizontalement (vers la gauche : 1) ou verticalement(vers le haut : 2)?\n");
                printf("Votre choix :");
                scanf("%d",&c);
                while ((c != 1) && (c != 2)) {
                  printf("\nEntrée invalide. Réessayez!\n");
                  printf("Votre choix :");
                  scanf("%d",&c);
                }
                if ((c==1) && ((d->pos2.y)-*n > 0) && ((d->pos2.y)-*n > d->pos1.y)) {
                    d->pos2.y -= *n;
                    Camp_Fruits->CA-= *n ;
                    printf("\nVous avez été débité de %d CA.\n", *n);
                } else if ((c==2) && ((d->pos1.x)-*n < (w.ws_col/6)-1) && ((d->pos1.x)-*n < d->pos2.x)) {
                    d->pos2.x -= *n;
                    Camp_Fruits->CA-= *n ;
                    printf("\nVous avez été débité de %d CA.\n", *n);
                } else {
                  printf("\nVotre déplacement est impossible.\n");
                }

        }
    }
}



/*
 * Fonction qui permet de traiter le reculement de chaque champion.
 *
 * @param : d - Duel (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fonction init.h)
 *          Camp_Fruits - Camp* (type déclaré dans la fonction init.h)
 *          n - int*
 * @return : void
 *
 */

void movebackward (Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int* n) {
  int c;
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  if (n == NULL) {
    *n = 1;
  }

  if (((d->tour == 1) && ((Camp_Legumes->CA - 2*(*n))<0)) || ((d->tour == 2) && ((Camp_Fruits->CA - 2*(*n))<0))){
      printf("Attention vous n'avez pas assez de CA pour vous déplacer vers l'arrière!\n");
  } else {
          if (d->tour == 1) {
              printf("Voulez-vous vous déplacer horizontalement (vers la gauche : 1) ou verticalement(vers le haut : 2)?\n");
              printf("Votre choix :");
              scanf("%d",&c);
              while ((c != 1) && (c != 2)) {
                printf("\nEntrée invalide. Réessayez!\n");
                printf("Votre choix :");
                scanf("%d",&c);
              }
              if ((c==1) && ((d->pos1.y)-*n < (w.ws_row/3)-1) && ((d->pos1.y)-*n < d->pos2.y)) {
                  d->pos1.y -= *n;
                  Camp_Legumes->CA-= 2*(*n) ;
                  printf("\nVous avez été débité de %d CA.\n", 2*(*n));
              } else if ((c==2) && ((d->pos1.x)-*n < (w.ws_col/6)-1) && ((d->pos1.x)-*n < d->pos2.x)) {
                  d->pos1.x -= *n;
                  Camp_Legumes->CA-= 2*(*n) ;
                  printf("\nVous avez été débité de %d CA.\n", 2*(*n));
              } else {
                printf("\nVotre déplacement est impossible.\n");
              }


          } else if (d->tour == 2) {
                  printf("Voulez-vous vous déplacer horizontalement (vers la droite : 1) ou verticalement(vers le bas : 2)?\n");
                  printf("Votre choix :");
                  scanf("%d",&c);
                  while ((c != 1) && (c != 2)) {
                    printf("\nEntrée invalide. Réessayez!\n");
                    printf("Votre choix :");
                    scanf("%d",&c);
                  }
                  if ((c==1) && ((d->pos2.y)+*n > 0) && ((d->pos2.y)+*n > d->pos1.y)) {
                      d->pos2.y += *n;
                      Camp_Fruits->CA-= 2*(*n) ;
                      printf("\nVous avez été débité de %d CA.\n", 2*(*n));
                  } else if ((c==2) && ((d->pos1.x)+*n < (w.ws_col/6)-1) && ((d->pos1.x)+*n < d->pos2.x)) {
                      d->pos2.x += *n;
                      Camp_Fruits->CA-= 2*(*n) ;
                      printf("\nVous avez été débité de %d CA.\n", 2*(*n));
                  } else {
                    printf("\nVotre déplacement est impossible.\n");
                  }

          }
      }
  }


/*
 * Fonction qui permet de calculer les dégâts qu'une arme peut causer sur le champion adversaire.
 *      (fontion utilisée pour la fonction useweapon)
 *
 * @param : campTireur - Camp* (type déclaré dans le fichier init.h)
 *          tireur - Champion* (type déclaré dans le fonction init.h)
 *          adversaire - Champion* (type déclaré dans la fonction init.h)
 *          proba - int
 *          dist - float
 * @return : void
 *
 */

void tirsArme (Camp* campTrieur, Champion* tireur, Champion* adversaire, int proba, float dist) {
  int res, fr, deg;
  deg = (rand() % (tireur->arme.degats[1] - tireur->arme.degats[0])) + tireur->arme.degats[0];
  fr = deg*(1+(tireur->force/100));
  res = 1-(adversaire->resistance/100);

  campTrieur->CA -= tireur->arme.cout_CA;
  printf("Vous avez été débité de %d CA.\n", tireur->arme.cout_CA);
  if ((dist <= tireur->arme.portee) && (adversaire->protection.bool) && (proba < adversaire->protection.portabilite)) {
    adversaire->PV_restant = adversaire->PV_restant - deg*fr*res;
    printf("Votre adversaire a été touché! il a été débité de %d points de vie.\n", deg*fr*res);
  }
}





/*
 * Fonction qui permet de traiter l'utilisation de l'arme par chaque champion un nombre de fois donné.
 *
 * @param : d - Duel* (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fonction init.h)
 *          Camp_Fruits - Camp* (type déclaré dans la fonction init.h)
 *          n - int*
 * @return : void
 *
 */

void useweapon (Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int* n) {
  if (n == NULL) {
    *n = 1;
  }
  int i;
  int proba = rand() % 100;
  float distance = sqrt(pow((d->pos1.x-d->pos2.x),2) + pow((d->pos1.y-d->pos2.y),2));

  if (((d->tour == 1) && ((d->c1.arme.cout_CA)*(*n) > Camp_Legumes->CA)) || ((d->tour == 2) && ((d->c2.arme.cout_CA)*(*n) > Camp_Fruits->CA))) {
    printf("Attention vous n'avez pas assez de CA pour utiliser votre arme!\n");
  } else {
    for (i=0; i<*n; i++) {
      if (d->tour == 1){
        tirsArme(Camp_Legumes,&d->c1,&d->c2,proba,distance);
      } else {
        tirsArme(Camp_Fruits,&d->c2,&d->c1,proba,distance);
      }
    }
  }
}


/*
 * Fonction qui permet de calculer les effets du soins sur le champion lors de son utilisation.
 *      (fontion utilisée pour la fonction usecare)
 *
 * @param : camp - Camp* (type déclaré dans le fonction init.h)
 *          c - Champion* (type déclaré dans la fonction init.h)
 *          nb - int
 * @return : void
 *
 */

void seSoigner(Camp* camp, Champion* c, int nb) {
  int i;
  for (i=0; i<nb; i++) {
    camp->CA -= c->soin.cout_CA;
    printf("Vous avez été débité de %d CA.\n", c->soin.cout_CA);
    c->PV_restant += (rand() + c->soin.effet[0]) % c->soin.effet[1];
    printf("Vous avez obtenu %d points de vie .\n", c->soin.cout_CA);
    c->soin.volume -= nb;
    printf("Le volume de votre soin a diminué de %d.\n", nb);
  }
}


/*
 * Fonction qui permet de traiter l'utilisation du soin de chaque champion un nombre de fois donné.
 *
 * @param : d - Duel* (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fonction init.h)
 *          Camp_Fruits - Camp* (type déclaré dans la fonction init.h)
 *          n - int*
 * @return : void
 *
 */

void usecare(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits, int* n) {
  int choix;
  if (n == NULL) {
    *n = 1;
  }
  if (((d->tour == 1) && ((d->c1.soin.cout_CA)*(*n) > Camp_Legumes->CA)) || ((d->tour == 2) && ((d->c2.soin.cout_CA)*(*n) > Camp_Fruits->CA))) {
     printf("Attention vous n'avez pas assez de CA pour utiliser votre soin!\n");}
  else {
    choix = d->tour;
    if (choix == 1) {
              if (d->c1.soin.volume <= *n) {
                seSoigner(Camp_Legumes, &(d->c1), *n);
              } else {
                choix = -1;
              }
      } else if (d->tour == 2) {
              if (d->c2.soin.volume <= *n) {
                seSoigner(Camp_Fruits, &(d->c2), *n);
              } else {
                choix = -1;
              }
      } else if (choix == -1) {
              printf("Attention vous avez dépassé la limite de votre volume de soin pour ce tour!\n");
      }
  }
}


/*
 * Fonction qui permet de tester si le champion peut revêtir sa protection en fonction des CA de son camp.
 *      (fontion utilisée pour la fonction useprotection)
 *
 * @param : c - Champion* (type déclaré dans le fichier init.h)
 *          camp - Camp* (type déclaré dans le fonction init.h)
 * @return : void
 *
 */

void mettreProtection (Champion* c, Camp* camp) {
  if (!c->protection.bool) {
    if (c->protection.cout_CA <= camp->CA) {
        c->protection.bool = 1;
        camp->CA -= c->protection.cout_CA;
        printf("Vous avez été débité de %d CA.\n", c->protection.cout_CA);
    } else {
      printf("CA insuffisants!\n");
    }
  } else {
    printf("Vous vous êtes déjà revêtu d'une protection.\n");
  }
}


/*
 * Fonction qui permet de traiter l'utilisation de la protection de chaque champion.
 *
 * @param : d - Duel* (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fonction init.h)
 *          Camp_Fruits - Camp* (type déclaré dans la fonction init.h)
 * @return : void
 *
 */

void useprotection(Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits) {
  if (d->tour == 1) {
        mettreProtection(&d->c1,Camp_Legumes);
  } else if (d->tour == 2) {
        mettreProtection(&d->c2,Camp_Fruits);
  }
}


/*
 * Fonction qui permet de mettre fin à un duel.
 *
 * @param : d - Duel* (type déclaré dans le fichier init.h)
 *          Camp_Legumes - Camp* (type déclaré dans le fonction init.h)
 *          Camp_Fruits - Camp* (type déclaré dans la fonction init.h)
 * @return : void
 *
 */
void end (Duel* d, Camp* Camp_Legumes, Camp* Camp_Fruits) {
  int i;
  if (d->tour == 1) {
              Camp_Legumes->CE += (5*(max((Camp_Legumes->CE - Camp_Fruits->CE),1)));
              printf("Félicitations! c'est le Légume remporte le duel. Il gagne %d CE.\n", Camp_Legumes->CE);
              printf("Le Fruit sera remplacé pour le prochain duel.\n");
              d->c1.nbDuels++;
              d->c1.boolGagner = 1;
              d->c2.boolGagner = 0;
              for (i=0; i<nbMembres; i++) {
                if (!strcmp(Camp_Legumes->membres[i].variete, d->c1.variete)) {
                  Camp_Legumes->membres[i].boolGagner = 1;
                } else if (!strcmp(Camp_Fruits->membres[i].variete, d->c2.variete)) {
                  Camp_Fruits->membres[i].boolGagner = 0;
                }
              }
  } else if (d->tour == 2) {
              Camp_Fruits->CE += (5*(max((Camp_Fruits->CE - Camp_Legumes->CE),1)));
              printf("Félicitations! c'est le Fruit qui remporte le duel. Il gagne %d CE.\n", Camp_Fruits->CE);
              printf("Le Légume sera remplacé pour le prochain duel.\n");
              d->c2.nbDuels++;
              d->c2.boolGagner = 1;
              d->c1.boolGagner = 0;
              for (i=0; i<nbMembres; i++) {
                if (!strcmp(Camp_Fruits->membres[i].variete, d->c2.variete)) {
                  Camp_Fruits->membres[i].boolGagner = 1;
                } else if (!strcmp(Camp_Legumes->membres[i].variete, d->c1.variete)) {
                  Camp_Legumes->membres[i].boolGagner = 0;
                }
              }
  }
}
