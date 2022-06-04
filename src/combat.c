#include "combat.h"
#include <stdlib.h>
//fonction attaque 
void offensive(Fighter *attacker , Fighter *target){
  
#include "struct.h"

void fight1(){  //procédure de combat d'un Joueur VS Machine
  while(){
    
  }
}




void fight_Machine(){  //procédure de combat d'un Joueur VS Machine
}
void tour attaque
/*
* procédure de combat d'un Joueurs VS un Joueur
* @param t1 1ère équipe
* @param t2 2nd équipe
*/
void fight(Team t1, Team t2){  //procédure de combat d'un Joueurs VS un Joueur
  while((t1.players > 0) && (t2.players > 0)){  
    int *sd;  // tableau speed
    Fighter first_a;
    sd = malloc((t1.players*2)*sizeof(int)); //initialisation du tableau regroupant les vitesses des combattants
    for(int i=0; i < t1.players; i++){  //remplissage avec team 1
        sd[i] = t1.f[i].speed;
    }
    for(int i=0; i < t2.players; i++){  //remplissage avec team 2
        sd[i] = t2.f[i].speed;
    }
    int max_s_index;

    do{
      max_s_index = 0;
      for(int i=0; i < t1.players; i++){
        if(sd[max_s_index] < sd[i]){
          max_s_index = i;
        }
        sd[max_s_index] = -1;
        if(max_s_index < t1.players/2){ //team 1 attaque

        }
        else if(max_s_index > t1.players/2){  //team 2 attaque

          first_a = t1.f[max_s_index];
        }
        else{  //team 2 attaque
          first_a = t2.f[max_s_index - (t2.players/2)];
        }

      }

    }while(max_s_index != -1);
  }
}

void mode_Easy(Team t1){ //mode de jeux facile - aucune tech spé - attaque au hasard

}

void mode_Medium(Team t1){  //mode de jeux moyen - aucune tech spé - attaque celui pv plus faible

}

void mode_Difficult(Team t1){ //mode de jeux difficile - tech spé et cible plus faible allié ou ennemi

}

void mode_4(Team t1){ //mode  de jeux torture

}