#include "struct.h"
//-----DAMAGE--------
void Charge_Shot(Fighter *attacker, Fighter *target){
    int  val, damage;
    val= rand()%15+1;// valeur d'équilibrage
    if (val<target->dodge){// test d'esquive
     printf ("esquive!%s",target->name);
    }else {
        damage= (attacker->sp_attack.valeur+attacker->attack)-target->defense;
    }
    if (damage>0){
        target->health=target->health-damage;
        printf ("%s a pris %d de degats et il reste %d points de vie \n",target->name,damage,target->health);
    }else {
        printf ("Adversaire trop fort pour lui causer des degats\n");
    }
}
void Tornade (Fighter *attacker, Fighter *target){
    int  val, damage;
    val= rand()%15+1;// valeur d'équilibrage
    if (val<target->dodge){ // test d'esquive
     printf ("esquive!%s",target->name);
    }else {
        damage= (attacker->sp_attack.valeur + attacker->attack)-target->defense;
    }
    if (damage>0){
        target->health=target->health-damage;
        printf ("%s a pris %d de degats et il reste %d points de vie \n",target->name,damage,target->health);
    }else {
        printf ("Adversaire trop fort pour lui causer des degats\n");
    }
}
void Epee_Ultime (Fighter *attacker, Fighter *target){
    int  val, damage;
    val= rand()%15+1;// valeur d'équilibrage
    if (val<target->dodge){ //test d'esquive
     printf ("esquive!%s",target->name);
    }else {
        damage= (attacker->sp_attack.valeur+attacker->attack)-target->defense;
    }
    if (damage>0){
        target->health=target->health-damage;
        printf ("%s a pris %d de degats et il reste %d points de vie \n",target->name,damage,target->health);
    }else{
        printf ("Adversaire trop fort pour lui causer des degats\n");
    }
}
void Medusa (Fighter *attacker, Fighter *target){
     int  val, damage;
    val= rand()%15+1;// valeur d'équilibrage
    if (val<target->dodge){ //test d'esquive
     printf ("esquive!%s",target->name);
    }else {
        damage= (attacker->sp_attack.valeur+attacker->attack)-target->defense;
    }
    if (damage>0){
        target->health=target->health-damage;
        printf ("%s a pris %d de degats et il reste %d points de vie \n",target->name,damage,target->health);
    }else{
        printf ("Adversaire trop fort pour lui causer des degats\n");
    }
}
//-----HEAL-------
void Soin_Intensif(Fighter *attacker, Fighter *target){
    int  val, heal;
    heal= target->max_health-attacker->sp_attack.valeur;
    target->health=target->health+heal;
}
void Descente_Soignante(Team t){
    
}
//----BOOST-----
void Aspiration(Fighter *attacker, Fighter *target){}
void Tempete(Fighter *attacker, Fighter *target){}
void Barriere_Protectrice (Fighter *attacker, Fighter *target){}
void Boost_Supreme (Fighter *attacker, Fighter *target){}
