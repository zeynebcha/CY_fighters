#include "struct.h"

int Turn_Off(Team t1, Team t2, int *sd, int nb_players);

Fighter* Find_Target(Team t );
Fighter* Find_Target_Noob(Team t);
Fighter* Find_Target_Weak(Team t);

void Offense (Fighter *attacker, Fighter *target);

void Find_Spe_Heal(Fighter *attacker, Fighter *target, Team t_off, Team t_targ);
void Find_Spe_Boost(Fighter *attacker, Fighter *target, Team t_off, Team t_targ);
void Find_Spe_Heal_Ai(Fighter *attacker, Fighter *target, Team t_off, Team t_targ);
void Find_Spe_Boost_Ai(Fighter *attacker, Fighter *target, Team t_off, Team t_targ);

void combat (Team t1, Team t2, int mode_jeu, int dif);

