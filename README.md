## Combat :

# Fonction Turn_Of : 
Fonction qui determine qui est le 1er combattant à attaquer en fonction de sa vitesse
# Procedure Offense: 
Le combattant attaque la cible choisi juste en enlevant à ces points de vie la valeur de la différence entre l'attaque de l'attaquant et la défense de la cible
# Fonction Find_Target:
Prend en paramètre l'equipe où on veut trouver la cible et retourne la cible voulue
# Fonction Find_Target_Noob:
Prend en paramètre l'equipe où on veut chercher la cible et retourne une cible choisie aléatoirement
# Fonction Find_Target_Weak:
Prend en paramètre l'equipe où on veut chercher la cible et retourne la cible avec les points de vie le plus faible
# Find_Spe_Heal: 
Recherche le nom de l'attaque spéciale de type heal et appelle la procédure correspondante  
# Find_Spe_Boost:
Recherche le nom de l'attaque spéciale de type boost et appelle la procédure correspondante 
# Find_Spe_Heal_IA:
Recherche le nom de l'attaque spéciale de type heal et appelle la procédure correspondante en ciblant toujours la cible la plus faible 
# Find_Spe_Boost_IA:
Recherche le nom de l'attaque spéciale de type boost et appelle la procédure correspondante  en ciblant toujours la cible la plus faible
# Procedure Team_Attack_J :
procédure qui fait attaquer un seul combattant 
# Procedure Team_Attack_IA :
procédure qui fait attaquer la machine
# Procedure Fight :
procédure qui effectue un tour de combat 
# Fonction  Team_Alive : 
Retourne 1 s'il y a un seul combattant vivant dans l'équipe 


## Construct :

# Constructeur contruct_spe :
Fonction qui prend en paramètre le nom de l'attaque spéciale et la retourne
# Constructeur contruct_fighter :
Fonction qui prend en paramètre le nom du combattabt et le retourne
# Constructeur contruct_team :
Fonction qui prend en paramètre le nombre de joueurs et retourne une équipe

## Display :

# Procédure Display_Team_Info :
Affiche l'interface graphique des deux équipes (1ère adverse et 2nd attaquante) avec toutes les informations de leurs combattants: le nom le numero les points de vie et le nom de l'attaque spéciale

## Spe_of :

# Procédure Spe_Damage : 
le combattant choisi une cible et lui cause des dégats en fonction de la valeur de l'attaque spéciale
# Procédure Soin_Intensif : 
le combattant soigne un allié choisi 
# Procédure Aspiration : 
l'attaquant ajoute la valeur asp (=la différence entre la defense de la cible et la valeur de son attaque spéciale) à la valeur de sa défense et la retranche de la valeur de défense de la cible
# Procédure Tempete :
Augmente les vitesses de l'attaquant et d'un allié choisi 
# Procédure Barriere_Protectrice :
Soigne l'attaquant et diminue les esquives du combattant adverse
# Procédure Descente_Soignante :
Soigne tous les alliés de l'attaquant
# Procédure Boost_supreme :
Augmente les attaques et les esquives de l'attaquant et d'un allié choisi 

# Team 1 : Joueur
# Team 2 : Joueur ou machine 
# Les équipes sont constituées de 4 combattants chacune. Dans une équipe on peut choisir les mêmes combattants plusieurs fois mais on ne peut pas choisir le même combattant que l'equipe adverse.

## Mode de difficulté

# Noob : 
L'ordinateur n'a aucune technnique spéciale et attaque les combattants au hasard et l'équipe est prédéfinie avec des combattants ayant des affinités faibles.
# Facile :
L'ordinateur n'a aucune technique spéciale et attaque systématiquement les combattants qui ont le moins de points de vie et l'équipe est prédéfinie avec des combattants ayant des affinités faibles.
# Moyen : 
L'ordinateur a des techniques spéciales et cible toujours les plus faibles (alliés ou combattants) et l'équipe est prédéfinie avec des combattants ayant des affinités faibles.
# Difficle
L'ordinateur a des techniques spéciales et cible toujours les plus faibles (alliés ou combattants) et l'équipe est prédéfini avec des affinités fortes entre les combattants.

## main :

# Variables : 

# mode_jeu : 
variable ppur définir le mode de jeu
# dif:
variable pour définir le mode de difficulté dans le mode Joueur VS Machine
# team_md:
variable aléatoire pour choisir une des 3 equipes  prédéfinies
# nb_players:
Variable pour definir le nombre de joueur 
# buff_1 :
buffer pour le nom de combattant equipe 1
# buff_2: 
buffer pour le nom de combattant equipe 2 




