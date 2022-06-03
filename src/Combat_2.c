#include "combat.h"
#include "spe_off.h"

//Fonction pour trouver la cible
Fighter* Find_Target(Team t ){
   int  num_target;
   Fighter *target;
    printf ("les combattants  de l'equipe adverse: \n");
    for (int i=1; i<t.players+1; i++){ // affichage de tous les combattants adverses
        printf ("f %d : %s", i, t.f[i].name);
    }
    printf("choisissez le numero du combattant adverse a attaquer : \n"); // choix de la cible
    scanf("%d", num_target);
    target= &t.f[num_target];
    return target;
}
//Fonction attaque
void Offense (Fighter *attacker, Fighter *target){
    int  val, damage;
    val= rand()%15+1;// valeur d'équilibrage
    if (val<target->dodge){
     printf ("esquive!%s",target->name);
    }else {
        damage= attacker->attack-target->defense;
    }
    if (damage>0){
        target->health=target->health-damage;
        printf ("%s a pris %d de degats et il reste %d points de vie \n",target->name,damage,target->health);
    }else {
        printf ("Adversaire trop fort pour lui causer des degats!\n");
    }
}
void Find_Spe_Off(Fighter *attacker, Fighter *target){}

//fonction qui determine l'indice du premier combattant a attaquer
int Tour_Attaque(Team t1, Team t2, int *sd, int nb_players){
  int index_max_sd=0;    // index de la vitesse max dans sd
  for(int i=0; i < nb_players*2; i++){
      if(sd[index_max_sd] > sd[i]){
          index_max_sd= i;
        }
    }
    sd[index_max_sd] = -1;  
    return index_max_sd;
}


void Combat (Team t1, Team t2 , int mode_jeu){
    int *sd=NULL;  // tableau speed
    int nb_players, max, type_offense;  
    Fighter *attacker, *target;
    nb_players=t1.players;
    sd = malloc((nb_players*2)*sizeof(int)); //allocation dynamique d'un tableau contenant les vitesses des combattants
    if (sd==NULL){ // verification
        printf("erreur allocation memoire\n");
        exit(1);
    }

    for(int i=0; i < nb_players; i++){  //remplissage avec les vitesses des players de la team 1
        sd[i] = t1.f[i].speed;
    }

    for(int i=nb_players; i <nb_players*2; i++){  //remplissage avec les vitesses des players de team 2
        sd[i] = t2.f[i].speed;
    }

    max = Tour_Attaque (t1,t2,sd,nb_players);
    if (max<nb_players/2){// c'est l'equipe 1 qui attaque 
        attacker=&t1.f[max];
        printf ("Equipe %s c'est a vous d'attaquer avec le combattant %s\n", t1.name,attacker->name);
        do{
        printf ("Comment voulez-vous attaquer ?\n1 : ne pas attaquer \n2 : Attaquer \n3:Faire une attaque speciale\n");// choix du type de l'attaque
        scanf ("%d",&type_offense);
        }while (type_offense!=1 || type_offense!=2 || type_offense!= 3);
        switch (type_offense){
            case 1 :
                break;
            case 2 : 
               target=Find_Target(t2);
                Offense(attacker, target);// attaque
                break;
            case 3 : 
                if (attacker->sp_attack.spe_type==0){
                    target=Find_Target(t2);
                }else if (attacker->sp_attack.spe_type==1){
                    target=Find_Target(t1);
                }
                spe_Offense (attacker, target);
                break; 
        }
    } else { // c'est l'equipe 2 qui attaque
        attacker=&t2.f[max-nb_players];
        if(mode_jeu==1){ //Joueur VS Machine 

        }else { // joueur VS joueur
        printf ("Equipe %s c'est a vous d'attaquer avec le combattant %s\n ", t2.name, attacker->name);
        do{
            printf ("Comment voulez-vous attaquer ?\n1 : ne pas attaquer \n2 : Attaquer \n3:Faire une attaque speciale\n");// choix du type de l'attaque
            scanf ("%d",&type_offense);
        }while (type_offense!=1 || type_offense!=2 || type_offense!= 3);
        switch (type_offense){
            case 1 : //ne pas attaquer 
                break;
            case 2 : 
               target=Find_Target(t2);
                Offense(attacker, target);// attaque
                break;
            case 3 : //attaque speciale
                if (attacker->sp_attack.spe_type==0){//DAMAGE
                    target=Find_Target(t2);
                }else if (attacker->sp_attack.spe_type==1){//HEAL
                    target=Find_Target(t1);
                }
                spe_Offense (attacker, target);
                break; 
            }
        }
    }
}