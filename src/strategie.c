/*strategie.c*/
#include "strategie.h"

/*
 * Fonction qui permet de transformer le nom de l'équipement en majuscules et remplace les tirets par des tiret_bas.
 *
 * @param : nom - char*
 * @return : char* (la chaine modifiée)
 */
char* nomEquipement(char* nom) {
  char* res = malloc(sizeof(char)*strlen(nom));
  while (*(nom++)) {
    if (*nom == '_') {
      *res = '-';
    } else {
      *res = tolower(*nom);
    }
  }
  return res;
}


/*
 * Fonction qui permet d'initialiser une stratégie et ses attributs.
 *
 * @param : f - FILE*
 *          nom - char*
 * @return : Strat (type déclaré dans le fichier strategie.h)
 */

Strat initStrat(FILE* f, char* nom) {
  Strat s;
  s.file = f;
  s.nom = nom;
  s.CE = 0;
  s.CA = 0;
  char* ligneFichier = malloc(sizeof(char)*50);
  char* sep = " \t\n";
  char* mot;
  int i;
  while (fgets(ligneFichier,50,f)){
    mot = strtok(ligneFichier,sep);
    while (mot != NULL) {
      if(!strcmp(mot,"choose")){
        mot = strtok(NULL,sep);
        if (!strcmp(mot,"weapon")) {
          mot = strtok(NULL,sep);
          for(i=0;i<nbArmes;i++){
            if(!strcmp(tabArmes[i].nom,mot)){
                s.ind_arme = i;
                s.CE += tabArmes[i].cout_CE;
                break;
            }
          }
        }
      } else if (!strcmp(mot,"protection")) {
        mot = strtok(NULL,sep);
        for(i=0;i<nbProtections;i++){
          if(!strcmp(tabProtects[i].nom,mot)){
              s.ind_protection = i;
              s.CE += tabProtects[i].cout_CE;
              break;
          }
        }
      }  else if (!strcmp(mot,"care")) {
        mot = strtok(NULL,sep);
        for(i=0;i<nbSoins;i++){
          if(!strcmp(tabSoins[i].nom,mot)){
              s.ind_soin = i;
              s.CE += tabSoins[i].cout_CE;
              break;
          }
        }
      }  else if (!strcmp(mot,"add")) {
        mot = strtok(NULL,sep);
        if (!strcmp(mot,"action")) {
          mot = strtok(NULL,sep);
          s.CE += atoi(mot);
          s.CA_demandes = atoi(mot);
        }
      } else if (!strcmp(mot,"use")) {
        mot = strtok(NULL,sep);
        if (!strcmp(mot,"weapon")) {
          s.CA += tabArmes[s.ind_arme].cout_CA;
        } else if (!strcmp(mot,"protection")) {
          s.CA += tabProtects[s.ind_protection].cout_CA;
        } else if (!strcmp(mot,"care")) {
          s.CA += tabSoins[s.ind_soin].cout_CA;
        }
      } else if (!strcmp(mot,"move")) {
        mot = strtok(NULL,sep);
        if (!strcmp(mot,"forward")) {
          mot = strtok(NULL,sep);
          s.CA += atoi(mot);
        } else if (!strcmp(mot,"backward")) {
          mot = strtok(NULL,sep);
          s.CA += 2*atoi(mot);
        }
      }
    }
  }
  free(ligneFichier);
  return s;
}

/*
 * Fonction qui permet d'initialiser les structures de stratégies existantes dans le dossier source, les enregistrer dans un tableau statique, et les afficher.
 *
 * @param : void
 * @return : void
 */

void showStrategies () {
    int i=1;
    DIR *rep;
    rep = opendir("./strategies");
    struct dirent *lecture;
    while ((lecture = readdir(rep))) {
      char* nomStrategie = malloc(sizeof(char)*50);
      char* nomFichier = lecture->d_name;
      if (!strcmp(nomFichier+(strlen(nomFichier)-6),".strat")) {
        FILE* f = fopen(lecture->d_name, "r");
        fgets(nomStrategie,50,f);
        printf("%d- %s\n", i, nomStrategie);
        tabStrat[i] = initStrat(f,nomStrategie);
        fclose(f);
        i++;
      }
      free(nomStrategie);
    }
    closedir(rep);
}



/*
 * Fonction qui permet d'afficher les détails d'une stratégie donnée.
 *
 * @param : i - int
 * @return : void
 */

void showStrategie (int i) {
  int cpt=0;
  DIR *rep;
  rep = opendir("./strategies");
  struct dirent *lecture;
  while ((lecture = readdir(rep))) {
    char* nomStrategie = malloc(50*sizeof(char));
    char* nomFichier = lecture->d_name;
    if (strcmp(nomFichier+(strlen(nomFichier)-6),".strat") == 0) {
      cpt++;
      if (cpt == i) {
        FILE* f = fopen(lecture->d_name, "r");
        fgets(nomStrategie,50,f);
        printf("%d- %s\n\n", cpt, nomStrategie);
        printf("Equipements utilisés :\n");
        printf("\n\tArme : ");
        showWeapon(tabStrat[cpt].ind_arme);
        printf("\n\tProtection : ");
        showProtection(tabStrat[cpt].ind_protection);
        printf("\n\tSoin : ");
        showCare(i);
        printf("Crédits d'Action supplémetaires : ");
        printf("%d", tabStrat[cpt].CA_demandes);
        printf("\n\nNombre de CE utilisés : %d \n\n", tabStrat[cpt].CE);
        printf("Nombre de CA utilisés : %d \n", tabStrat[cpt].CA);
        fclose(f);
      }
    }

    free(nomStrategie);
  }
  closedir(rep);
}


/*
 * Fonction qui permet d'initialiser les attributes d'un champion donné (équipements).
 *
 * @param : s - Strat (type déclaré dans le fichier strategie.h)
 *          c - Champion* (type déclaré dans le fichier init.h)
 *          camp - Camp* (type déclaré dans le fichier init.h)
 * @return : void
 */
void choixEquipement(Strat s, Champion* c, Camp* camp) {
  char* ligneFichier = malloc(sizeof(char)*50);
  char* sep = " \t\n";
  char* mot;

  while (fgets(ligneFichier,50,s.file)){
    mot = strtok(ligneFichier,sep);
    while (mot != NULL) {
      if(!strcmp(mot,"choose")){
        mot = strtok(NULL,sep);
        if (!strcmp(mot,"weapon")) {
          mot = strtok(NULL,sep);
          choixArme(c,camp,s.ind_arme);
        } else if (!strcmp(mot,"protection")) {
          mot = strtok(NULL,sep);
          choixProtection(c,camp,s.ind_protection);
        } else if (!strcmp(mot,"care")) {
          choixProtection(c,camp,s.ind_soin);
        }
      } else if(!strcmp(mot,"add")){
        mot = strtok(NULL,sep);
        if(!strcmp(mot,"action")){
          mot = strtok(NULL,sep);
          achatCA(camp,atoi(mot));
        }
      }
    }
  }
  free(ligneFichier);
}


/*
 * Fonction qui permet de simuler le combat à l'aide des stratégies passées en paramètes.
 *
 * @param : s1 - Strat (type déclaré dans le fichier strategie.h)
 *          s2 - Strat (type déclaré dans le fichier strategie.h)
 *          d - Duel* (type déclaré dans le fichier init.h)
 *          Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Fruits - Camp* (type déclaré dans le fichier init.h)
 *          char** - plateau
 * @return : void
 */

void combat (Strat s1, Strat s2, Duel* d, Camp* Legumes, Camp* Fruits, char** plateau) {
  char* ligneFichier1 = malloc(sizeof(char)*50);
  char* ligneFichier2 = malloc(sizeof(char)*50);
  char* sep = " \t\n";
  char* mot1;
  char* mot2;
  int cpt_if1 = 0;
  int cpt_if2 = 0;
  int bool_else1 = 0;
  int bool_else2 = 0;
  int v;

  while ((fgets(ligneFichier1,50,s1.file)) && fgets(ligneFichier2,50,s2.file)){
    /*SDL_Delay(3000);*/ /*timer*/
    mot1 = strtok(ligneFichier1,sep);
    mot2 = strtok(ligneFichier2,sep);
    d->tour = 1;
    while (mot1 != NULL)  {
      if((!strcmp(mot1,"move")) && (!bool_else1)){
         mot1=strtok(NULL,sep);
         if(!strcmp(mot1,"backward")){
           mot1=strtok(mot1,sep);
           v = atoi(mot1);
           movebackward(d,Legumes,Fruits,&v);
         } else if(!strcmp(mot1,"forward")){
           mot1=strtok(mot1,sep);
           v = atoi(mot1);
           moveforward(d,Legumes,Fruits,&v);
         }
      } else if ((!strcmp(mot1,"use")) && (!bool_else1)) {
        mot1 = strtok(NULL,sep);
        if (!strcmp(mot1,"weapon")) {
          mot1 = strtok(NULL,sep);
          int i = atoi(mot1);
          useweapon(d,Legumes,Fruits,&i);
        } else if (!strcmp(mot1,"protection")) {
          useprotection(d,Legumes,Fruits);
        } else if (!strcmp(mot1,"care")) {
          mot1 = strtok(NULL,sep);
          int i = atoi(mot1);
          usecare(d,Legumes,Fruits,&i);
        }
      } else if((!strcmp(mot1,"if")) && (!bool_else1)) {
          cpt_if1++;
          mot1 = strtok(NULL,sep);
          if (!strcmp(mot1,"Life")) {
            char* op = strtok(NULL,sep);
            mot1 = strtok(NULL,sep);
            if (mot1[strlen(mot1)-1] == '%') {
              char* mot = realloc(mot1,strlen(mot1)-1);
              v = (int) atoi(mot) * d->c1.PV_max/100;
            } else {
              v = atoi(mot1);
            }
            if (!strcmp(op,"==")) {
              if (d->c1.PV_restant == v) {
                bool_else1 = 0;
                continue;
              } else {
                bool_else1 = 1;
              }
            } else if (!strcmp(op,"!=")) {
              if (d->c1.PV_restant != v) {
                bool_else1 = 0;
                continue;
              } else {
                bool_else1 = 1;
              }
            } else if (!strcmp(op,"<=")) {
              if (d->c1.PV_restant <= v) {
                bool_else1 = 0;
                continue;
              } else {
                bool_else1 = 1;
              }
            } else if (!strcmp(op,">=")) {
              if (d->c1.PV_restant >= v) {
                bool_else1 = 0;
                continue;
              } else {
                bool_else1 = 1;
              }
            } else if (!strcmp(op,"<")) {
              if (d->c1.PV_restant < v) {
                bool_else1 = 0;
                continue;
              } else {
                bool_else1 = 1;
              }
            } else if (!strcmp(op,">")) {
              if (d->c1.PV_restant > v) {
                bool_else1 = 0;
                continue;
              } else {
                bool_else1 = 1;
              }
            }
          } else if (!strcmp(mot1,"enemyLife")) {
              char* op = strtok(NULL,sep);
              mot1 = strtok(NULL,sep);
              if (mot1[strlen(mot1)-1] == '%') {
                char* mot = realloc(mot1,strlen(mot1)-1);
                v = (int) atoi(mot) * d->c2.PV_max/100;
              } else {
                v = atoi(mot1);
              }
              if (!strcmp(op,"==")) {
                if (d->c2.PV_restant == v) {
                  bool_else1 = 0;
                  continue;
                } else {
                  bool_else1 = 1;
                }
              } else if (!strcmp(op,"!=")) {
                if (d->c2.PV_restant != v) {
                  bool_else1 = 0;
                  continue;
                } else {
                  bool_else1 = 1;
                }
              } else if (!strcmp(op,"<=")) {
                if (d->c2.PV_restant <= v) {
                  bool_else1 = 0;
                  continue;
                } else {
                  bool_else1 = 1;
                }
              } else if (!strcmp(op,">=")) {
                if (d->c2.PV_restant >= v) {
                  bool_else1 = 0;
                  continue;
                } else {
                  bool_else1 = 1;
                }
              } else if (!strcmp(op,"<")) {
                if (d->c2.PV_restant < v) {
                  bool_else1 = 0;
                  continue;
                } else {
                  bool_else1 = 1;
                }
              } else if (!strcmp(op,">")) {
                if (d->c2.PV_restant > v) {
                  bool_else1 = 0;
                  continue;
                } else {
                  bool_else1 = 1;
                }
              }
            } else if (!strcmp(mot1,"enemyInScope")) {
              mot1 = strtok(NULL,sep);
              float dist = sqrt(pow((d->pos1.x-d->pos2.x),2) + pow((d->pos1.y-d->pos2.y),2));
              if (dist <= d->c1.arme.portee) {
                bool_else1 = 0;
                continue;
              }
            }
        } else if ((!strcmp(mot1,"else")) && (bool_else1)) {
            bool_else1 = 0;
            continue;
        } else if ((!strcmp(mot1,"endif")) && (!bool_else1)){
            cpt_if1--;
        } else if ((!strcmp(mot1,"end")) && (!bool_else1)) {
            break;
        }

      }
      d->tour = 2;
      while (mot2 != NULL)  {
        if((!strcmp(mot2,"move")) && (!bool_else2)){
           mot2=strtok(NULL,sep);
           if(!strcmp(mot2,"backward")){
             mot2=strtok(mot2,sep);
             v = atoi(mot2);
             movebackward(d,Legumes,Fruits,&v);
           } else if(!strcmp(mot2,"forward")){
             mot2=strtok(mot2,sep);
             v = atoi(mot2);
             moveforward(d,Legumes,Fruits,&v);
           }
        } else if ((!strcmp(mot2,"use")) && (!bool_else2)) {
          mot2 = strtok(NULL,sep);
          if (!strcmp(mot2,"weapon")) {
            mot2 = strtok(NULL,sep);
            int i = atoi(mot2);
            useweapon(d,Legumes,Fruits,&i);
          } else if (!strcmp(mot2,"protection")) {
            useprotection(d,Legumes,Fruits);
          } else if (!strcmp(mot2,"care")) {
            mot2 = strtok(NULL,sep);
            int i = atoi(mot2);
            usecare(d,Legumes,Fruits,&i);
          }
       } else if((!strcmp(mot2,"if")) && (!bool_else2)) {
            cpt_if1++;
            mot2 = strtok(NULL,sep);
            if (!strcmp(mot2,"Life")) {
              char* op = strtok(NULL,sep);
              mot2 = strtok(NULL,sep);
              if (mot2[strlen(mot2)-1] == '%') {
                char* mot = realloc(mot2,strlen(mot2)-1);
                v = (int) atoi(mot) * d->c2.PV_max/100;
              } else {
                v = atoi(mot2);
              }
              if (!strcmp(op,"==")) {
                if (d->c2.PV_restant == v) {
                  bool_else2 = 0;
                  continue;
                } else {
                  bool_else2 = 1;
                }
              } else if (!strcmp(op,"!=")) {
                if (d->c2.PV_restant != v) {
                  bool_else2 = 0;
                  continue;
                } else {
                  bool_else2 = 1;
                }
              } else if (!strcmp(op,"<=")) {
                if (d->c2.PV_restant <= v) {
                  bool_else2 = 0;
                  continue;
                } else {
                  bool_else2 = 1;
                }
              } else if (!strcmp(op,">=")) {
                if (d->c2.PV_restant >= v) {
                  bool_else2 = 0;
                  continue;
                } else {
                  bool_else2 = 1;
                }
              } else if (!strcmp(op,"<")) {
                if (d->c2.PV_restant < v) {
                  bool_else2 = 0;
                  continue;
                } else {
                  bool_else2 = 1;
                }
              } else if (!strcmp(op,">")) {
                if (d->c2.PV_restant > v) {
                  bool_else2 = 0;
                  continue;
                } else {
                  bool_else2 = 1;
                }
              }
            } else if (!strcmp(mot2,"enemyLife")) {
                char* op = strtok(NULL,sep);
                mot2 = strtok(NULL,sep);
                if (mot2[strlen(mot2)-1] == '%') {
                  char* mot = realloc(mot2,strlen(mot2)-1);
                  v = (int) atoi(mot) * d->c1.PV_max/100;
                } else {
                  v = atoi(mot2);
                }
                if (!strcmp(op,"==")) {
                  if (d->c1.PV_restant == v) {
                    bool_else2 = 0;
                    continue;
                  } else {
                    bool_else2 = 1;
                  }
                } else if (!strcmp(op,"!=")) {
                  if (d->c1.PV_restant != v) {
                    bool_else2 = 0;
                    continue;
                  } else {
                    bool_else2 = 1;
                  }
                } else if (!strcmp(op,"<=")) {
                  if (d->c1.PV_restant <= v) {
                    bool_else2 = 0;
                    continue;
                  } else {
                    bool_else2 = 1;
                  }
                } else if (!strcmp(op,">=")) {
                  if (d->c1.PV_restant >= v) {
                    bool_else2 = 0;
                    continue;
                  } else {
                    bool_else2 = 1;
                  }
                } else if (!strcmp(op,"<")) {
                  if (d->c1.PV_restant < v) {
                    bool_else2 = 0;
                    continue;
                  } else {
                    bool_else2 = 1;
                  }
                } else if (!strcmp(op,">")) {
                  if (d->c1.PV_restant > v) {
                    bool_else2 = 0;
                    continue;
                  } else {
                    bool_else2 = 1;
                  }
                }
              } else if (!strcmp(mot2,"enemyInScope")) {
                mot2 = strtok(NULL,sep);
                float dist = sqrt(pow((d->pos1.x-d->pos2.x),2) + pow((d->pos1.y-d->pos2.y),2));
                if (dist <= d->c2.arme.portee) {
                  bool_else2 = 0;
                  continue;
                }
              }
          } else if ((!strcmp(mot2,"else")) && (bool_else2)) {
              bool_else2 = 0;
              continue;
          } else if ((!strcmp(mot2,"endif")) && (!bool_else2)){
              cpt_if2--;
          } else if ((!strcmp(mot2,"end")) && (!bool_else2)) {
              break;
          }
        }
        system("clear");
        reinitPlateau(d,plateau);
        affichagePlateau(plateau);
        show(*d);
      }
end(d,Legumes,Fruits);

free(ligneFichier1);
free(ligneFichier2);
free(mot1);
free(mot2);
}


/*
 * Fonction qui permet de lancer un duel.
 *
 * @param : s1 - Strat (type déclaré dans le fichier strategie.h)
 *          s2 - Strat (type déclaré dans le fichier strategie.h)
 *          d - Duel* (type déclaré dans le fichier init.h)
 *          Legumes - Camp* (type déclaré dans le fichier init.h)
 *          Fruits - Camp* (type déclaré dans le fichier init.h)
 *          char** - plateau
 * @return : void
 */
void fightStrat (Strat s1, Strat s2, Duel* d, Camp* Legumes, Camp* Fruits, char** plateau) {
  choixEquipement(s1,&d->c1,Legumes);
  choixEquipement(s2,&d->c2,Fruits);
  combat(s1,s2,d,Legumes,Fruits,plateau);
}
