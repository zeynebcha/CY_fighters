#include "struct.h"
//-----DAMAGE--------
void Spe_Damage ( Fighter *attacker, Fighter *target){
 int  val, damage;
    val= rand()%15+1;// valeur d'équilibrage
    if (val<target->dodge){// test d'esquive
     printf ("esquive!%s",target->name);
    }else {
        damage= (attacker->sp_attack.valeur+attacker->attack)-target->defense;
    }
    if (damage>0){
        target->health=target->health-damage;
        printf ("%s a pris %d de degats et il lui reste %d points de vie \n",target->name,damage,target->health);
    }else {
        printf ("Adversaire trop fort pour lui causer des degats\n");
    }
}

//-----HEAL-------
void Soin_Intensif(Fighter *attacker, Fighter *target){
    int  heal;
    heal= target->max_health-attacker->sp_attack.valeur;
    target->health=target->health+heal;
    printf ("%s a pris %d de heal et il a donc %d points de vie \n",target->name,heal,target->health);
}
void Descente_Soignante(Fighter *attacker ,Team t){
    int heal; 
    for (int i=0; i<t.players; i++){
        heal = t.f[i].max_health-attacker->sp_attack.valeur;
        if (heal>0){
            t.f[i].health=t.f[i].health+heal;
            printf ("%s a %d points de vie",t.f[i].name,t.f[i].health);
        }
    }
}
void Barriere_Protectrice (Fighter *attacker, Fighter *target){
    int heal, damage;  
    heal = attacker->max_health - attacker->health;
    if (heal>0){
        attacker->health=attacker->health + heal;
        printf ("%s a pris %d de heal et il a donc %d points de vie\n",attacker->name, heal, attacker->health);
    }
    damage=(attacker->sp_attack.valeur-attacker->attack)-target->defense;
    if (damage>0){
        target->dodge=target->defense-damage;
        printf ("%s a pris %d de degats et il lui reste %d de points de vie\n",target->name, damage, target->health);
    }
}
//----BOOST-----
void Aspiration(Fighter *attacker, Fighter *target){
    int asp;
    asp= target->defense - attacker->sp_attack.valeur;
    if (asp>0){
        attacker->defense+=asp;
        target->defense-=asp;
        printf ("%s vous avez aspire %d et vous avez donc desormais %d defense\n",attacker->name,asp,attacker->defense);
        printf ("%s vous avez perdu des points de defense et vous avez desormais %d defense\n",target->name,target->defense);
    }
}
void Tempete(Fighter *attacker, Fighter *target){
    int increase_speed;
    increase_speed=attacker->sp_attack.valeur;
    attacker->speed=attacker->speed + increase_speed;
    target->speed=target->speed + increase_speed;
    printf ("%s a %d vitesse\n",attacker->name,attacker->speed);
    printf ("%s a %d de vitesse\n", target->name, target->speed);
}
void Boost_Supreme (Fighter *attacker, Fighter *target){
    int boost;
    boost=attacker->sp_attack.valeur;
    attacker->attack+=boost;
    attacker->dodge+=boost;
    target->attack+=boost;
    target->dodge+=boost;
    printf ("%s a %d attaque et %d esquives\n",attacker->name,attacker->attack, attacker->dodge);
    printf ("%s a %d attaque et %d esquives\n", target->name, target->attack, target->dodge);
}