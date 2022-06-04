#ifndef structh
#define structh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Création de la structure Special
typedef struct{  
  char *nom;
 /* char *description;*/
  int spe_type ;//0=DEGAT, 1=HEAL, 2=BOOST
  int valeur;
  int nmb_tourActif;
  int nmb_tourRecharge;
   

}Special;

//Création de la structure Fighter
typedef struct{  
  char name[50];
  char rank ;
  int max_health; // constante
  int health;
  int attack;
  int defense;
  int dodge;
  int speed;
  int alive; //1=vivant ou 0=mort 
  Special sp_attack;
  int spe_effects;
}Fighter;

//Création de la structure Team
typedef struct{  
  int players;
  char name[100];
  Fighter *f;
}Team;
#endif