#include "struct.h"
#include "construct.h"
#include "combat.h"

//Fonction main
int main(void){
  int nb_players, mode_jeu = 0, dif = 0, team_md = 0; 
  char buff_1[1000],buff_2[1000];
  Team player_1,player_2,computer;
  srand(time(NULL));
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");  //sélection mode de jeux
    scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) || (mode_jeu != 2));  //test de vérification
  if (mode_jeu==1){ //mode joueur vs machine
    do{
      printf("Choix du mode de difficulté : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n"); //choix mode de difficulté
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 4)); // test de vérification
    if(dif >= 1 && dif <= 3){// équipe machine générée aléatoirement 
        do{
        printf ("Saisissez le nombre de combattants souhaité \n");
        scanf("%d",nb_players);
        }while(nb_players<2);
        computer = construct_team(nb_players);
        player_1= construct_team(nb_players);
        Fighter f_buff;
        for (int i=0 ; i<nb_players; i++){
          f_buff.alive=0;
          while (!f_buff.alive){
          printf ("saisissez le nom du combattant que vous voulez dans votre equipe :\n");
          scanf("%s",buff_1);
          f_buff=construct_fighter(buff_1);
          }
          player_1.f[i]=f_buff;
          f_buff.alive=0;
          while (!f_buff.alive){
            
          }

        }
      }
        Combat(player_1, computer, mode_jeu, dif); //lancement procédure Combat avec le mode de difficulté choisi contre la machine
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
        Combat(player_1, computer, mode_jeu, dif); //lancement procédure combat contre la machine en mode difficile 
    }
  }
  else { //mode Joueur vs Joueur 
    do{
      printf ("Saisissez le nombre de combattants souhaité \n");
      scanf("%d",nb_players);
    }while(nb_players<2);
    player_1 = construct_team(nb_players);
    player_2= construct_team(nb_players);
    Fighter f_buff;
    for (int i=0; i<nb_player; i++){
    f_buff.alive = 0;
    while(!f_buff.alive){
      printf("Equipe1 saisissez le nom du combattant que vous voulez:\n");
      scanf("%s",buff_1);
      f_buff = construct_fighter(buff_1);
    }
    player_1.f[i]=f_buff;
    f_buff.alive = 0;
    while(!f_buff.alive){
      do {
        printf("Equipe2 saisissez le nom du combattant que vous voulez:\n");
        scanf("%s",buff_2);
      }while(strcmp(buff_1,buff_2)!=0);
      f_buff = construct_fighter(buff_2);
    }
      player_2.f[i]=f_buff;
    }
    Combat(player_1,player_2,mode_jeu,0);  //0 pour le mode de difficulté puisqu'il n'y en a pas en Joueur vs Joueur
  }
}