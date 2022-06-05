#include "struct.h"

int Turn_Of(Team t1, Team t2, int *sd, int nb_players);

Fighter* Find_Target(Team *t);
Fighter* Find_Target_Noob(Team *t);
Fighter* Find_Target_Weak(Team *t);

void Offense (Fighter *attacker, Fighter *target);

void Find_Spe_Heal(Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ);
void Find_Spe_Boost(Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ);
void Find_Spe_Heal_IA(Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ);
void Find_Spe_Boost_IA(Fighter *attacker, Fighter *target, Team *t_off, Team *t_targ);

void Team_attack_J(Team *t_off, Team *t_targ, Fighter *attacker);
void Team_attack_IA(int mode_dif, Team *t_j, Team *t_ia, Fighter *attacker);

void Fight (Team *t1, Team *t2 , int mode_jeu, int mode_dif);

int Team_Alive(Team t);