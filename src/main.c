#include "struct.h"
#include "construct.h"
#include "combat.h"

//Fonction main
int main(void){
  int nb_players, mode_jeu = 0, dif = 0, team_md1=0, team_md2 = 0; 
  char buff_1[1000],buff_2[1000];
  Team player_1,player_2,computer;
  Fighter f_buff1, f_buff2;
  srand(time(NULL));
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur\n");  //sélection mode de jeux
    scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) && (mode_jeu != 2));  //test de vérification
  if (mode_jeu==1){ //mode joueur vs machine
    do{
      printf("Choix du mode de difficulte : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n"); //choix mode de difficulté
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 4)); // test de vérification
    if(dif >= 1 && dif <= 3){// équipe faible prédéfinie
      do{
        printf ("Saisissez le nombre de combattants souhaite \n");
        scanf("%d",&nb_players);
      }while(nb_players<2); // test de vérification
      player_1= construct_team(nb_players);
      printf ("tessst\n");
      computer = construct_team(nb_players);
      printf ("tessst\n");
      team_md1 = rand()%3 + 1;
      if(team_md1 == 1){
        printf("Le joueur va jouer contre l'equipe predefinie 1 contenant  Miroveed, Nallmar, Daera, Lorel\n");
        //construction 1ère équipe prédéfinie
        computer.f[0]=construct_fighter("Miroveed");
        computer.f[1]=construct_fighter("Nallmar");
        computer.f[2]=construct_fighter("Daera");
        computer.f[3]=construct_fighter("Lorel");
      }
      else if(team_md1 == 2){
        printf("Le joueur va jouer contre l'equipe predefinie 2 contenant Arel, Tagriel , Iela et Arrion\n");
        //construction 2ème équipe prédéfinie
        computer.f[0]=construct_fighter("Arel");
        computer.f[1]=construct_fighter("Tagriel");
        computer.f[2]=construct_fighter("Iela");
        computer.f[3]=construct_fighter("Arrion");
      }
      if(team_md1== 3){
        printf("Le joueur va jouer contre l'equipe predefinie 3 contenant Deam, Daera, Tagriel et Lorel\n");
        //construction 3ème équipe prédéfinie
        computer.f[0]=construct_fighter("Deam");
        computer.f[1]=construct_fighter("Daera");
        computer.f[2]=construct_fighter("Tagriel");
        computer.f[3]=construct_fighter("Lorel");
      }

      for (int i=0 ; i<nb_players; i++){
        f_buff1.alive=0;
        while (!f_buff1.alive && strcmp(f_buff1.name,computer.f[i].name)==0){
          printf ("saisissez le nom du combattant que vous voulez dans votre equipe :\n");
          scanf("%s",buff_1);
          f_buff1=construct_fighter(buff_1);
        }
        player_1.f[i]=f_buff1; 
      }

      while (player_1.players>0 && computer.players>0){
       combat(player_1, computer, mode_jeu, dif); //lancement procédure Combat avec le mode de difficulté choisi contre la machine
      }
      if (player_1.players==0){
        printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",player_1.name,computer.name);
      } else {
        printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",computer.name,player_1.name);
      }

    }else{ // équipe forte prédéfinie
      do{
        printf ("Saisissez le nombre de combattants souhaite \n");
        scanf("%d",nb_players);
      }while(nb_players<2); // test de vérification
      computer = construct_team(nb_players);
      player_1= construct_team(nb_players);
      team_md2 = rand()%3 + 1;
      if(team_md2 == 1){
        printf("Le joueur va jouer contre l'equipe predefinie 1 contenant Daera, Miroveed, Iela et Arel\n");
        //construction 1ère équipe prédéfinie
        computer.f[0]=construct_fighter("Daera");
        computer.f[1]=construct_fighter("Miroveed");
        computer.f[2]=construct_fighter("Iela");
        computer.f[3]=construct_fighter("Arel");
      }
      if(team_md2 == 2){
        printf("Le joueur va jouer contre l'equipe predefinie 2 contenant Nallmar, Ada, Deam et Lorel\n");
        //construction 2ème équipe prédéfinie
        computer.f[0]=construct_fighter("Nallmar");
        computer.f[1]=construct_fighter("Ada");
        computer.f[2]=construct_fighter("Deam");
        computer.f[3]=construct_fighter("Lorel");
      }
      if(team_md2 == 3){
        printf("Le joueur va jouer contre l'equipe predefinie 3 contenant Tagriel, Nallmar, Arrion et Daera\n");
        //construction 3ème équipe prédéfinie
        computer.f[0]=construct_fighter("Tagriel");
        computer.f[1]=construct_fighter("Nallmar");
        computer.f[2]=construct_fighter("Arrion");
        computer.f[3]=construct_fighter("Daera");
      }
      for (int i=0 ; i<nb_players; i++){
        f_buff1.alive=0;
        while (!f_buff1.alive && strcmp(f_buff1.name,computer.f[i].name)==0){
          printf ("saisissez le nom du combattant que vous voulez dans votre equipe :\n");
          scanf("%s",buff_1);
          f_buff1=construct_fighter(buff_1);
        }
        player_1.f[i]=f_buff1;     
      }
      while (player_1.players>0 && computer.players>0 ){
        combat(player_1, computer, mode_jeu, dif); //lancement procédure combat contre la machine en mode difficile 
      }if (player_1.players==0){
        printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",player_1.name,computer.name);
      } else {
        printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",computer.name,player_1.name);
      }
    }
  }
  else { //mode JOUEUR VS JOUEUR
    do{
      printf ("Saisissez le nombre de combattants souhaite \n");
      scanf("%d",nb_players);
    }while(nb_players<2);// test de vérification
    printf ("EQUIPE 1 : \n");
    player_1 = construct_team(nb_players);
    printf("EQUIPE 2 : \n");
    player_2= construct_team(nb_players);
    for (int i=0; i<nb_players; i++){ // choix des combattants en alternant entre les deux joueurs 
    f_buff2.alive = 0;
    while(!f_buff2.alive){
      printf("Equipe1 saisissez le nom du combattant que vous voulez:\n");
      scanf("%s",buff_1);
      f_buff2= construct_fighter (buff_1);
    }
    player_1.f[i]=f_buff2;
    f_buff2.alive = 0;
    while(!f_buff2.alive){
      do {
        printf("Equipe2 saisissez le nom du combattant que vous voulez:\n");
        scanf("%s",buff_2);
      }while(strcmp(buff_1,buff_2)!=0);
      f_buff2 = construct_fighter(buff_2);
    }
      player_2.f[i]=f_buff2;
    }
    while (player_1.players>0 && player_2.players>0){
      combat(player_1, player_2, mode_jeu, dif);  //0 pour le mode de difficulté puisqu'il n'y en a pas en Joueur vs Joueur
    }if (player_1.players==0){
      printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",player_1.name,player_2.name);
    } else {
      printf ("%s Vous avez perdu..\n%s Vous avez gagne!!\n",player_2.name,player_1.name);
    }
  }
  return 0;
}