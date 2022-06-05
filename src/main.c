#include "struct.h"
#include "construct.h"
#include "fight.h"
#include "display.h"

//Fonction main
int main(void){
  int nb_players, mode_jeu = 0, dif = 0, team_md=0; 
  char buff_1[1000],buff_2[1000];
  Team player_1,player_2;
  Fighter f_buff;
  srand(time(NULL));

  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur\n");  //sÃ©lection mode de jeux
    scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) && (mode_jeu != 2));  //test de vÃ©rification


  if (mode_jeu==1){ //mode joueur vs machine

    do{
      printf("Choix du mode de difficulte : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n"); //choix mode de difficultÃ©
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 4)); // test de vÃ©rification

    nb_players = 4;
    player_1= construct_team(nb_players);
    strcpy(player_2.name, "CUMPUTEUR");
    player_2.players = nb_players;
    player_2.f = malloc(4*sizeof(Fighter));
    if (player_2.f==NULL){
      printf ("erreur allocation memoire\n");
      exit(1);
    }

    team_md = rand()%3 + 1;
    if(dif >= 1 && dif <= 3){// Ã©quipe faible prÃ©dÃ©finie
      
      if(team_md == 1){
        printf("Le joueur va jouer contre l'equipe predefinie 1 contenant  Miroveed, Nallmar, Daera, Lorel\n");
        //construction 1Ã¨re Ã©quipe prÃ©dÃ©finie
        player_2.f[0]=construct_fighter("Miroveed");
        player_2.f[1]=construct_fighter("Nallmar");
        player_2.f[2]=construct_fighter("Daera");
        player_2.f[3]=construct_fighter("Lorel");
      }
      else if(team_md == 2){
        printf("Le joueur va jouer contre l'equipe predefinie 2 contenant Arel, Tagriel , Iela et Arrion\n");
        //construction 2Ã¨me Ã©quipe prÃ©dÃ©finie
        player_2.f[0]=construct_fighter("Arel");
        player_2.f[1]=construct_fighter("Tagriel");
        player_2.f[2]=construct_fighter("Iela");
        player_2.f[3]=construct_fighter("Arrion");
      }
      if(team_md== 3){
        printf("Le joueur va jouer contre l'equipe predefinie 3 contenant Deam, Daera, Tagriel et Lorel\n");
        //construction 3Ã¨me Ã©quipe prÃ©dÃ©finie
        player_2.f[0]=construct_fighter("Deam");
        player_2.f[1]=construct_fighter("Daera");
        player_2.f[2]=construct_fighter("Tagriel");
        player_2.f[3]=construct_fighter("Lorel");
      }

    }else{ // Ã©quipe forte prÃ©dÃ©finie

      if(team_md == 1){
        printf("Le joueur va jouer contre l'equipe predefinie 1 contenant Daera, Miroveed, Iela et Arel\n");
        //construction 1Ã¨re Ã©quipe prÃ©dÃ©finie
        player_2.f[0]=construct_fighter("Daera");
        player_2.f[1]=construct_fighter("Miroveed");
        player_2.f[2]=construct_fighter("Iela");
        player_2.f[3]=construct_fighter("Arel");
      }
      if(team_md == 2){
        printf("Le joueur va jouer contre l'equipe predefinie 2 contenant Nallmar, Ada, Deam et Lorel\n");
        //construction 2Ã¨me Ã©quipe prÃ©dÃ©finie
        player_2.f[0]=construct_fighter("Nallmar");
        player_2.f[1]=construct_fighter("Ada");
        player_2.f[2]=construct_fighter("Deam");
        player_2.f[3]=construct_fighter("Lorel");
      }
      if(team_md == 3){
        printf("Le joueur va jouer contre l'equipe predefinie 3 contenant Tagriel, Nallmar, Arrion et Daera\n");
        //construction 3Ã¨me Ã©quipe prÃ©dÃ©finie
        player_2.f[0]=construct_fighter("Tagriel");
        player_2.f[1]=construct_fighter("Nallmar");
        player_2.f[2]=construct_fighter("Arrion");
        player_2.f[3]=construct_fighter("Daera");
      }   
      
    }

    for (int i=0 ; i<nb_players; i++){
        f_buff.alive=0;
        while (!f_buff.alive){
          do {
          printf ("saisissez le nom du combattant que vous voulez dans votre equipe :\n");
          scanf("%s",buff_1);
          }while (strcmp(buff_1,player_2.f[i].name)==0);
          f_buff=construct_fighter(buff_1);
        }
        player_1.f[i]=f_buff;     
    }

  }
  else { //mode JOUEUR VS JOUEUR

    do{
      printf ("Saisissez le nombre de combattants souhaite \n");
      scanf("%d",&nb_players);
    }while(nb_players<2);// test de vÃ©rification

    printf ("EQUIPE 1 : \n");
    player_1 = construct_team(nb_players);
    printf("EQUIPE 2 : \n");
    player_2= construct_team(nb_players);
    printf ("----\n");

    for (int i=0; i<nb_players; i++){ // choix des combattants en alternant entre les deux joueurs 

      f_buff.alive = 0;
      while(!f_buff.alive){
        printf("Equipe1 saisissez le nom du combattant que vous voulez:\n");
        scanf("%s",buff_1);
        f_buff= construct_fighter (buff_1);
      }
      player_1.f[i]=f_buff;

      f_buff.alive = 0;
      while(!f_buff.alive){
        printf("Equipe2 saisissez le nom du combattant que vous voulez:\n");
        scanf("%s",buff_2);
        f_buff = construct_fighter(buff_2);
      }
      player_2.f[i]=f_buff;

    }
    
  }

  Display_Team_Info(player_1);
  Display_Team_Info(player_2);

  while ((Team_Alive(player_1) == 1) && (Team_Alive(player_2) == 1)){
   Fight(&player_1, &player_2, mode_jeu, dif);  //0 pour le mode de difficultÃ© puisqu'il n'y en a pas en Joueur vs Joueur
  }
  
  if (Team_Alive(player_1) == 0){
    printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",player_1.name,player_2.name);
  } else {
    printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",player_2.name,player_1.name);
  }
  return 0;
}
