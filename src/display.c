#include"struct.h"
#include"combat.h"


void disp_align(char chain[]){
  int compt = strlen(chain);
    for(int i = 0; i < compt;i++){
      printf("_");
    }
    printf("\n");
  }    


void display(Team t1, Team t2, Fighter first_a){  //procédure pour afficher l'interface graphique
printf("_[%s]______________________________\n\n", t1.name);   //1ère équipe - adverse
  for(int i=0; i < t1.players;i++){
    if(t1.f[i].health == 0){
      printf("   %s |%s|\n", t1.f[i].name, "mort"); //affiche le nom et mort s'il le combattant n'a plus de pv
    }
    else{
      printf("   %s |%d|\n", t1.f[i].name, i);  // affiche le nom et le numéro s'il le combattant est vivant
    }
    
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
  disp_align(t1.name);  //pour aligner la dernière ligne d'affichage à la 1ère


printf("_[%s]______________________________\n\n", t2.name);   //2nd équipe - joueur
  for(int i=0; i < t2.players;i++){
    if(t2.f[i].name == first_a.name){
      printf("   )>%s<( \n", t2.f[i].name);  // affiche le nom de l'attaquant actuel
    }
    else{
      printf("   %s \n", t2.f[i].name);  // affiche le nom 
    }
    if(t2.f[i].spe_effects == 0){
      printf("   Subit des dégats\n");   
    }
    if(t2.f[i].spe_effects == 1){
      printf("   Reçoit du heal\n");
    }
    if(t2.f[i].spe_effects == 2){
      printf("   Reçoit du boost\n");
    }
    printf("   Vie : %d\n",t2.f[i].health);
    }
  printf("   %s \nTechniques spéciales\n", first_a.name); //affiche le nom du combattant actuel et techniques spéciales
  if(first_a.sp_attack.nmb_tourRecharge != 0){
    printf("   |1| %s durée : %d tour", first_a.sp_attack.nom, first_a.sp_attack.nmb_tourActif);
  }
  else{
    printf("   |-| %s durée : %d tour", first_a.sp_attack.nom, first_a.sp_attack.nmb_tourActif);
  }
  
  printf("_________________________________");
  disp_align(t2.name);  //pour aligner la dernière ligne d'affichage à la 1ère
}