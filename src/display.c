#include"struct.h"

//procédure pour afficher l'interface graphique
void Display_Team_Info(Team t){  
  printf(" _[%-20.20s]__________________________________________________________\n", t.name );
  printf("|%-81s|\n","");
  for(int i=0; i<t.players; i=i+2){

    if(i < t.players-1){
      printf("|   [%-2.2d] [%-10.10s] %s   [%-2.2d] [%-10.10s] %s\n", i, t.f[i].name, t.f[i].alive ? "ALIVE":"DEAD ", i+1, t.f[i+1].name, t.f[i+1].alive ? "ALIVE":"DEAD ");
      printf("|    %-5.5d/%-5.5d HP            %-5.5d/%-5.5d HP\n", t.f[i].health, t.f[i].max_health, t.f[i+1].health, t.f[i+1].max_health);
      printf("|   spe: %-18.18s   spe: %-18.18s\n", t.f[i].sp_attack.nom, t.f[i].sp_attack.nom);

    }
    else{
      printf("|   [%-2.2d] [%-10.10s] %s\n", i, t.f[i].name, t.f[i].alive ? "ALIVE":"DEAD ");
      printf("|       %-5.5d/%-5.5d HP\n", t.f[i].health, t.f[i].max_health);
      printf("|   spe: %-18.18s\n", t.f[i].sp_attack.nom);
    }
    printf("|%-81s|\n","");
    
  }
  printf("_________________________________________________________________________________\n");
}
