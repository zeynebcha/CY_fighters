#include "struct.h"
#include "construct.h"
#include "combat.h"

//Fonction main
int main(void){
  int mode_jeu = 0; //variable pour défnir le mode de jeux
  int dif = 0;  //variable pour définir le mode de difficulté en Joueur VS Machine
  int team_md = 0;  //variable pour sélectionner une équipe prédéfini en difficulté difficile contre la machine 
  Team t1,t2;
  srand(time(NULL));
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");  //sélection mode de jeux
  scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) || (mode_jeu != 2));  //test de vérification
  if (mode_jeu==1){ //mode joueur vs machine
    Team computer;
    do{
      printf("Choix du mode de difficulté : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n"); //choix mode de difficulté
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 4)); // test de vérification
    if(dif >= 1 && dif <= 3){
        // équipe machine généré aléatoirement 
        Combat(t1, computer, 1, dif); //lancement procédure Combat avec le mode de difficulté choisi contre la machine
    }
    else{
        // équipe prédéfinie
        team_md = rand()%3 + 1;
        if(team_md == 1){
          printf("Le joueur va jouer contre l'équipe prédéfinie 1 contenant Daera, Miroveed, Iela et Arel\n");
          //construction 1ère équipe prédéfinie
        }
        if(team_md == 2){
          printf("Le joueur va jouer contre l'équipe prédéfinie 2 contenant Nallmar, Ada, Deam et Lorel\n");
          //construction 2ème équipe prédéfinie
        }
        if(team_md == 3){
          printf("Le joueur va jouer contre l'équipe prédéfinie 3 contenant Tagriel, Nallmar, Arrion et Daera\n");
          //construction 3ème équipe prédéfinie
        }
        Combat(t1, computer, 1, dif); //lancement procédure combat contre la machine en mode difficile 
    }
  }
  else{ //mode Joueur vs Joueur 
    
    Combat(t1,t2,1,0);  //0 pour le mode de difficulté puisqu'il n'y en a pas en Joueur vs Joueur
  }
}