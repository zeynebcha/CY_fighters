#include"struct.h"
#include"combat.h"


void disp_align(char chain[], int place){
  int compt = strlen(chain);
  if(place == 0){ //0 correspond à la fin des encadrés
    for(int i = 0; i < compt;i++){
      printf("_");
    }
    printf("\n");
  }    
}

void display(Team t1, Team t2){  //procédure pour afficher l'interface graphique
printf("_[%s]______________________________\n\n", t1.name);   //1ère équipe - adverse
  for(int i=0; i < t1.players;i++){
  printf("   %s |1|\n", t1.f[i].name);
  if(t1.f[i].spe_effects == 0){
    printf("   Subit des dégats\n");   
  }
  if(t1.f[i].spe_effects == 1){
    printf("   Reçoit du heal\n");
  }
  if(t1.f[i].spe_effects == 2){
    printf("   Reçoit du boost\n");
  }
  printf("   Vie : %d\n",t1.f[i].health);
  }
printf("_________________________________");
}