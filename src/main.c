#include "struct.h"
#include "combat.h"

int main(void){
  int mode_jeu = 0;
  int dif = 0;
  Team t1,t2;
  srand(time(NULL));
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");
  scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) || (mode_jeu != 2));  //test de vérification
  do{
    printf("Choix du mode de difficulté : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n3 : pour Difficile \n");
    scanf("%d", &dif);
  }while((dif < 1) || (dif > 5));// test de vérification
  combat();