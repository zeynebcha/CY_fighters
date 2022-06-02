#include "combat.h"
#include <stdlib.h>

void fight1(){  //procédure de combat d'un Joueur VS Machine
  while(){
    
  }
}

/*
* procédure de combat d'un Joueurs VS un Joueur
* @param t1 1ère équipe
* @param t2 2nd équipe
*/
void fight2(Team t1, Team t2){  //procédure de combat d'un Joueurs VS un Joueur
  while((t1.players > 0) && (t2.players > 0)){  
    int *sd;  // tableau speed


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
      for(int i=0; i < strlen(sd); i++){
        if(sd[max_s_index] < sd[i]){
          max_s_index = i;
        }
        sd[max_s_index] = -1;
        if(max_s_index < strlen(sd)/2){ //team 1 attaque

        }
        else if(max_s_index > strlen(sd)/2){  //team 2 attaque

        }

      }

    }while(max_s_index != -1);
  }
}

void mode_1(Team t1){ //mode de jeux facile - aucune tech spé - attaque au hasard

}

void mode_2(Team t1){  //mode de jeux moyen - aucune tech spé - attaque celui pv plus faible

}

void mode_3(Team t1){ //mode de jeux difficile - tech spé et cible plus faible allié ou ennemi

}

void mode_4(Team t1){ //mode  de jeux torture

}
