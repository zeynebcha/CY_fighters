#include "combat.h"
#include "spe_off.h"
#include "display.h"

//Fonction pour trouver la cible
Fighter* Find_Target(Team t ){
   int  num_target;
   Fighter *target;
    printf ("les combattants  de l'equipe adverse: \n");
    for (int i=1; i<t.players+1; i++){ // affichage de tous les combattants adverses
        printf ("f %d : %s", i, t.f[i].name);
    }
    printf("choisissez le numero du combattant adverse a attaquer : \n"); // choix de la cible
    scanf("%d", &num_target);
    target=&t.f[num_target];
    return target;
}

//Fonction pour trouver une cible aleatoirement
Fighter* Find_Target_Noob(Team t){
 int  num_target;
   Fighter *target;
    num_target=rand()%(t.players);//choix aleatoire de l'index de la cible
    target=&t.f[num_target];
    return target;
}

//Fonction pour trouver la cible qui le moins de points de vie
Fighter* Find_Target_Weak(Team t){
    int  num_target=0;
   Fighter *target;
   for (int i=0; i<t.players; i++){
       if (t.f[i].health<t.f[num_target].health){
           num_target=i;
       }
    }
    target=&t.f[num_target];
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

//Fonction qui determine et appelle la bonne attaque speciale de type heal
void Find_Spe_Heal(Fighter *attacker, Fighter *target, Team t_off, Team t_targ){ // t_off=equipe qui attaque et t_targ=equipe qui esquive
    if (strcmp(attacker->sp_attack.nom,"Soin_Intensif")==0){
        do{
        target=Find_Target(t_off);
        }while(target->alive==0);
        Soin_Intensif(attacker, target);
    }else if (strcmp(attacker->sp_attack.nom,"Barriere_Protectrice")==0){
        do{
        target=Find_Target(t_targ);
        }while (target->alive==0);
        Barriere_Protectrice(attacker, target);
    } else if (strcmp(attacker->sp_attack.nom,"Descente_Soignante")==0){
        Descente_Soignante(attacker,t_off);
    }
}

//Fonction qui determine et appelle la bonne attaque speciale de type boost
void Find_Spe_Boost(Fighter *attacker, Fighter *target, Team t_off, Team t_targ){
    if(strcmp(attacker->sp_attack.nom,"Aspiration")==0){
        do{
        target=Find_Target(t_targ);
        }while (target->alive==0);
        Aspiration(attacker, target);
    }else if (strcmp(attacker->sp_attack.nom,"Tempete")==0){
        do {
        target=Find_Target(t_off);
        }while(target->alive==0);
        Tempete(attacker,target);
    }else if (strcmp(attacker->sp_attack.nom,"Boost_Supreme")==0){
        do{
        target=Find_Target(t_off);
        }while (target->alive==0);
        Boost_Supreme(attacker,target);
    }
}

void Find_Spe_Heal_Ai (Fighter *attacker, Fighter *target, Team t_off, Team t_targ){
      if (strcmp(attacker->sp_attack.nom,"Soin_Intensif")==0){
        do{
        target=Find_Target_Weak(t_off);
        }while(target->alive==0);
        Soin_Intensif(attacker, target);
    }else if (strcmp(attacker->sp_attack.nom,"Barriere_Protectrice")==0){
        do{
        target=Find_Target_Weak(t_targ);
        }while (target->alive==0);
        Barriere_Protectrice(attacker, target);
    } else if (strcmp(attacker->sp_attack.nom,"Descente_Soignante")==0){
        Descente_Soignante(attacker,t_off);
    }
}

void Find_Spe_Boost_Ai(Fighter *attacker, Fighter *target, Team t_off, Team t_targ){
if(strcmp(attacker->sp_attack.nom,"Aspiration")==0){
        do{
        target=Find_Target_Weak(t_targ);
        }while (target->alive==0);
        Aspiration(attacker, target);
    }else if (strcmp(attacker->sp_attack.nom,"Tempete")==0){
        do {
        target=Find_Target_Weak(t_off);
        }while(target->alive==0);
        Tempete(attacker,target);
    }else if (strcmp(attacker->sp_attack.nom,"Boost_Supreme")==0){
        do{
        target=Find_Target_Weak(t_off);
        }while (target->alive==0);
        Boost_Supreme(attacker,target);
    }
}

//fonction qui determine l'indice du premier combattant a attaquer
int Turn_Off(Team t1, Team t2, int *sd, int nb_players){
  int index_max_sd=0;    // index de la vitesse max dans sd
  for(int i=0; i < nb_players*2; i++){
      if(sd[index_max_sd] > sd[i]){
          index_max_sd= i;
        }
    }
    sd[index_max_sd] = -1;  
    return index_max_sd;
}


void Combat (Team t1, Team t2 , int mode_jeu, int mode_dif){
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

    max = Turn_Off (t1,t2,sd,nb_players);
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
            do {
            target=Find_Target(t2);
            }while(target->alive==0);
            Offense(attacker, target);// ATTAQUE
            break;
        case 3 : // ATTAQUE SPECIALE
            if (attacker->sp_attack.spe_type==0){//DAMAGE
                do{
                target=Find_Target(t2);
                }while(target->alive==0);
                Spe_Damage(attacker,target);
            }else if (attacker->sp_attack.spe_type==1){// HEAL
                Find_Spe_Heal(attacker, target, t1, t2); //t1=equipe qui attaque et t2= equipe qui esquive
            }else { // BOOST
                Find_Spe_Boost(attacker, target, t1,t2); //t1=equipe qui attaque et t2= equipe qui esquive
            }
            break; 
        }
    } 
    else { // EQUIPE 2 ATTAQUE
        attacker=&t2.f[max-nb_players];
        if(mode_jeu==1){ //JOUEUR VS MACHINE
            switch (mode_dif){
            case 1: //MODE NOOB
                do{
                target=Find_Target_Noob(t1);
                }while(target->alive==0);
                Offense(attacker,target);
                break;
            case 2 : //MODE FACILE
                do{
                    Find_Target_Weak(t1);
                }while (target->alive==0);
                Offense(attacker,target);
                break;
            case 3 : // MODE MOYEN
                if (attacker->sp_attack.spe_type==0){//DAMAGE
                    do{
                    target=Find_Target_Weak(t1);
                    }while (target->alive==0);
                    Spe_Damage(attacker, target);
                }else if (attacker->sp_attack.spe_type==1){//HEAL
                   Find_Spe_Heal_Ai(attacker,target, t2,t1); // t2 = equipe qui attaque et t1= equipe qui esquive
                }else { //BOOST 
                   Find_Spe_Boost_Ai(attacker,target,t2,t1); // t2 = equipe qui attaque et t1= equipe qui esquive
                }

                break;
            case 4 : // MODE DIFFICILE
                if (attacker->sp_attack.spe_type==0){//DAMAGE
                    do{
                    target=Find_Target(t1);
                    }while (target->alive==0);
                    Spe_Damage(attacker, target);
                }else if (attacker->sp_attack.spe_type==1){//HEAL
                    Find_Spe_Heal(attacker, target, t2, t1); // t2 = equipe qui attaque et t1= equipe qui esquive
                }else { //BOOST 
                    Find_Spe_Boost(attacker,target,t2,t1);// t2 = equipe qui attaque et t1= equipe qui esquive
                }
                break;
            }

        }
        else { //JOUEUR VS JOUEUR
            printf ("Equipe %s c'est a vous d'attaquer avec le combattant %s\n ", t2.name, attacker->name);
            do{
                printf ("Comment voulez-vous attaquer ?\n1 : ne pas attaquer \n2 : Attaquer \n3:Faire une attaque speciale\n");// choix du type de l'attaque
                scanf ("%d",&type_offense);
            }while (type_offense!=1 || type_offense!=2 || type_offense!= 3);
            switch (type_offense){
            case 1 : // NE PAS ATTAQUER
                break;
            case 2 : 
                do{
                target=Find_Target(t1);
                }while(target->alive==0);
                Offense(attacker, target);// ATTAQUE
                break;
            case 3 : // ATTAQUE SPECIALE
                if (attacker->sp_attack.spe_type==0){//DAMAGE
                    do{
                    target=Find_Target(t1);
                    }while (target->alive==0);
                    Spe_Damage(attacker, target);
                }else if (attacker->sp_attack.spe_type==1){//HEAL
                    Find_Spe_Heal(attacker, target, t2, t1); // t2 = equipe qui attaque et t1= equipe qui esquive
                }else { //BOOST 
                    Find_Spe_Boost(attacker,target,t2,t1);// t2 = equipe qui attaque et t1= equipe qui esquive
                }
                break; 
            }
        }   
    }
}