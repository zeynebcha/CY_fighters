#include "struct.h"
#include "combat.h"

int main(void){
  int mode_jeu = 0;
  int dif = 0;
  Team t1, t2;
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");
  scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) || (mode_jeu != 2));  //test de vérification

  if(mode_jeu == 1){  //pour lancer le 1er mode : Joueur VS Machine
    do{
      printf("Choix du mode de difficulté : \n1 : pour Facile \n2 : pour Moyen \n3 : pour Difficile \n4 : pour Torture \n");
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 5));
    combat1();
  }
    
  else{  //pour lancer le 2nd mode : Joueur VS Joueur 
    combat2();
  }
}
