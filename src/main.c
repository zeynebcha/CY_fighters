#include "struct.h"
#include "combat.h"
void disp_align(char chain[], int place){
  int compt = strlenght(chain);
  if(place == 0){ //0 correspond à la fin des encadrés
    for(int i = 0; i < compt;i++){
      printf("_");
    }
    printf("\n");
  }    
}

void display(Team t1, Team t2){  //procédure pour afficher l'interface graphique
printf("_[%s]______________________________\n\n", t1.name);   //1ère équipe - adverse
  for(int i=0; i < t1.players){
  printf("   %s |1|\n", t1.f[i].name);
  if(t1.f[i]->spe_effects == 0){
    printf("   Subit des dégats\n");   
  }
  if(t1.f[i]->spe_effects == 1){
    printf("   Reçoit du heal\n");
  }
  if(t1.f[i]->spe_effects == 2){
    printf("   Reçoit du boost\n");
  }
  printf("   Vie : %d\n",t1.f[i].health);
  }
printf("_________________________________");
}

int main(void){
  int mode_jeu = 0;
  int dif = 0;
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");
  scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) || (mode_jeu != 2));  //test de vérification

  if(mode_jeu == 1){  //pour lancer le 1er mode : Joueur VS Machine
    do{
      printf("Choix du mode de difficulté : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n5 : pour Torture \n");
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 5));
    combat1();
  }
    
  else{  //pour lancer le 2nd mode : Joueur VS Joueur 
    combat2();
  }
}
