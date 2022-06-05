#include "struct.h"
#include "Spe_of.h"
#include "display.h"

//Fonction pour trouver la cible
Fighter* Find_Target(Team *t){
   int  num_target;
   Fighter *target;
    printf("choisissez le numero du combattant adverse a attaquer : \n"); // choix de la cible
    Display_Team_Info(*t);
    scanf("%d", &num_target);
    target = &t->f[num_target];
    return target;
}

//Fonction pour trouver une cible aleatoirement
Fighter* Find_Target_Noob(Team *t){
 int  num_target;
   Fighter *target;
    num_target=rand()%(t->players);//choix aleatoire de l'index de la cible
    target=&t->f[num_target];
    return target;
}

//Fonction pour trouver la cible qui le moins de points de vie
Fighter* Find_Target_Weak(Team *t){
    int  num_target=0;
   Fighter *target;
   for (int i=0; i<t->players; i++){
       if (t->f[i].health<t->f[num_target].health){
           num_target=i;
       }
    }
    target=&t->f[num_target];
    return target;
}

//Fonction attaque
void Offense (Fighter *attacker, Fighter *target){
    int  val = rand()%15+1; // valeur d'equilibrage
    int damage = 0;

    if (val<target->dodge){
        printf ("%s esquive! ",target->name);
    }else {
        damage = (attacker->attack) - (target->defense);
        if (damage > 0){
            target->health = target->health - damage;

            if(target->health <= 0){
                target->health = 0;
                target->alive = 0;
            }

            printf ("%s a pris %d de degats et il reste %d points de vie \n",target->name,damage,target->health);
        }else {
            printf ("Adversaire trop fort pour lui causer des degats!\n");
        }
    }

    
}

//Fonction qui determine et appelle la bonne attaque speciale de type heal
void Find_Spe_Heal(Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ){ // t_off=equipe qui attaque et t_targ=equipe qui esquive
    if (strcmp(attacker->sp_attack.nom,"Soin_Intensif")==0){
        do{
        target=Find_Target(t_off);
        }while(target->alive==0);
        Soin_Intensif(attacker, target);
        target->spe_effects=1;
    }else if (strcmp(attacker->sp_attack.nom,"Barriere_Protectrice")==0){
        do{
        target=Find_Target(t_targ);
        }while (target->alive==0);
        Barriere_Protectrice(attacker, target);
        attacker->spe_effects=1;
        target->spe_effects=0;
    } else if (strcmp(attacker->sp_attack.nom,"Descente_Soignante")==0){
        Descente_Soignante(attacker,t_off);
        for (int i=0; i<t_off->players; i++){
            t_off->f[i].spe_effects = 1;
        }
    }
}

//Fonction qui determine et appelle la bonne attaque speciale de type boost
void Find_Spe_Boost(Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ){
    if(strcmp(attacker->sp_attack.nom,"Aspiration")==0){
        do{
        target=Find_Target(t_targ);
        }while (target->alive==0);
        Aspiration(attacker, target);
        attacker->spe_effects=2;
        target->spe_effects=0;
    }else if (strcmp(attacker->sp_attack.nom,"Tempete")==0){
        do {
        target=Find_Target(t_off);
        }while(target->alive==0);
        Tempete(attacker,target);
        attacker->spe_effects=2;
        target->spe_effects=2;
    }else if (strcmp(attacker->sp_attack.nom,"Boost_Supreme")==0){
        do{
        target=Find_Target(t_off);
        }while (target->alive==0);
        Boost_Supreme(attacker,target);
        target->spe_effects=2;
        attacker->spe_effects=2;
    }
}

void Find_Spe_Heal_IA (Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ){
      if (strcmp(attacker->sp_attack.nom,"Soin_Intensif")==0){
        do{
        target=Find_Target_Weak(t_off);
        }while(target->alive==0);
        Soin_Intensif(attacker, target);
        target->spe_effects=1;
    }else if (strcmp(attacker->sp_attack.nom,"Barriere_Protectrice")==0){
        do{
        target=Find_Target_Weak(t_targ);
        }while (target->alive==0);
        Barriere_Protectrice(attacker, target);
        attacker->spe_effects=1;
        target->spe_effects=0;
    } else if (strcmp(attacker->sp_attack.nom,"Descente_Soignante")==0){
        Descente_Soignante(attacker,t_off);
        for (int i=0; i<t_off->players; i++){
            t_off->f[i].spe_effects = 1;
        }
    }
}

void Find_Spe_Boost_IA (Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ){
if(strcmp(attacker->sp_attack.nom,"Aspiration")==0){
        do{
        target=Find_Target_Weak(t_targ);
        }while (target->alive==0);
        Aspiration(attacker, target);
        attacker->spe_effects=2;
        target->spe_effects=0;
    }else if (strcmp(attacker->sp_attack.nom,"Tempete")==0){
        do {
        target=Find_Target_Weak(t_off);
        }while(target->alive==0);
        Tempete(attacker,target);
        attacker->spe_effects=2;
        target->spe_effects=2;
    }else if (strcmp(attacker->sp_attack.nom,"Boost_Supreme")==0){
        do{
        target=Find_Target_Weak(t_off);
        }while (target->alive==0);
        Boost_Supreme(attacker,target);
        target->spe_effects=2;
        attacker->spe_effects=2;
    }
}

//fonction qui determine l'indice du premier combattant a attaquer
int Turn_Of(int *sd, int nb_players){
  int index_max_sd=0;    // index de la vitesse max dans sd
  for(int i=0; i < nb_players*2; i++){
      if(sd[index_max_sd] < sd[i]){
          index_max_sd = i;
        }
    }

    if(sd[index_max_sd] != -1){ 
        return index_max_sd;
    }
    else{
        return -1;
    }
}


void Team_attack_J(Team *t_off, Team *t_targ, Fighter *attacker){
    int type_offense;
    Fighter *target;

    printf ("Equipe %s c'est a vous d'attaquer avec le combattant %s\n", t_off->name,attacker->name);
    do{
        printf ("Comment voulez-vous attaquer ?\n1 : ne pas attaquer \n2 : Attaquer \n3:Faire une attaque speciale\n");// choix du type de l'attaque
        scanf ("%d",&type_offense);
    }while (type_offense!=1 && type_offense!=2 && type_offense!= 3);

    switch (type_offense){
        case 1 :
            break;
        case 2 : 
            do {
            target=Find_Target(t_targ);
            }while(target->alive==0);

            Offense(attacker, target);// ATTAQUE
            break;
        case 3 : // ATTAQUE SPECIALE
            if (attacker->sp_attack.spe_type==0){//DAMAGE
                do{
                target=Find_Target(t_targ);
                }while(target->alive==0);
                Spe_Damage(attacker,target);
            }else if (attacker->sp_attack.spe_type==1){// HEAL
                Find_Spe_Heal(attacker, target, t_off, t_targ); //t1=equipe qui attaque et t2= equipe qui esquive
            }else { // BOOST
                Find_Spe_Boost(attacker, target, t_off, t_targ); //t1=equipe qui attaque et t2= equipe qui esquive
            }
            break; 
    }
}

void Team_attack_IA(int mode_dif, Team *t_j, Team *t_ia, Fighter *attacker){
    Fighter *target;
    printf ("Equipe %s c'est a vous d'attaquer avec le combattant %s\n", t_ia->name,attacker->name);
    switch (mode_dif){
        case 1: //MODE NOOB
            do{
                target=Find_Target_Noob(t_j);
            }while(target->alive==0);
            Offense(attacker,target);
            break;

        case 2 : //MODE FACILE
            do{
                Find_Target_Weak(t_j);
            }while (target->alive==0);
            Offense(attacker,target);
            break;
            
        case 3 : // MODE MOYEN
            if (attacker->sp_attack.spe_type==0){//DAMAGE
                do{
                    target=Find_Target_Weak(t_j);
                }while (target->alive==0);
                Spe_Damage(attacker, target);
            }else if (attacker->sp_attack.spe_type==1){//HEAL
                Find_Spe_Heal_IA(attacker,target, t_ia,t_j); // t2 = equipe qui attaque et t1= equipe qui esquive
            }else { //BOOST 
                Find_Spe_Boost_IA(attacker,target,t_ia,t_j); // t2 = equipe qui attaque et t1= equipe qui esquive
            }
            break;

        case 4 : // MODE DIFFICILE
            if (attacker->sp_attack.spe_type==0){//DAMAGE
                do{
                    target=Find_Target_Weak(t_j);
                }while (target->alive==0);
                Spe_Damage(attacker, target);
            }else if (attacker->sp_attack.spe_type==1){//HEAL
                Find_Spe_Heal_IA(attacker,target, t_ia,t_j); // t2 = equipe qui attaque et t1= equipe qui esquive
            }else { //BOOST 
                Find_Spe_Boost_IA(attacker,target,t_ia,t_j); // t2 = equipe qui attaque et t1= equipe qui esquive
            }
            break;
    }
}

void Fight (Team *t1, Team *t2 , int mode_jeu, int mode_dif){
    /* INIT */
    int nb_players =0;
    int max = 0;  
    int *sd ;
    Fighter *attacker;
    nb_players=t1->players;
    printf  ("\n");
    sd= malloc((nb_players*2)*sizeof(int)); // allocation dynamique d'un tableau contenant les vitesses des combattants
    if (sd==NULL){ // verification
        printf("erreur allocation memoire\n");
        exit(1);
    }

    for(int i=0; i < nb_players; i++){  //remplissage avec les vitesses des players de la team 1
        sd[i] = t1->f[i].alive ? t1->f[i].speed : -1;
    }

    for(int i=nb_players; i <nb_players*2; i++){  //remplissage avec les vitesses des players de team 2
        sd[i] = t2->f[i-nb_players].alive ? t2->f[i-nb_players].speed : -1;
    }

    /* FIGHT */

    max = Turn_Of(sd,nb_players);

    while(max != -1){
        sd[max] = -1; 
        
        if (max < nb_players){// c'est l'equipe 1 qui attaque 
            attacker = &t1->f[max];
            Team_attack_J(t1, t2, attacker);
        } 
        else { // EQUIPE 2 ATTAQUE
            attacker = &t2->f[max-nb_players];
            if(mode_jeu==1){ //JOUEUR VS MACHINE
                Team_attack_IA(mode_dif, t1, t2, attacker);
            }
            else { //JOUEUR VS JOUEUR
                Team_attack_J(t2, t1, attacker);
            }   
        }
        max = Turn_Of(sd,nb_players);
    }
    
}

int Team_Alive(Team t){
    for(int i=0; i<t.players; i++){
        if(t.f[i].alive==1) return 1;
    }
    return 0;
}