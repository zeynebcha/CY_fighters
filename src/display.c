#include"struct.h"

//procédure pour afficher l'interface graphique
void Display_Fighters (){
printf ("|Name| : Miroveed |Rank| : A |Max Hp| 14040 |Attack| : 1564 |Defense| : 1079 |Speed| : 96 ALIVE |Sp| : Soin_Intensif\n\n");
printf ("|Name| : Iela |Rang |: S |Max Hp| :21480  |Attack| :793 |Defense| : 1354 |Speed| :97 ALIVE |Sp| : Medusa \n \n");
printf("|Name| : Nallmar |Rank| : B  |Max Hp| : 18825 |Attack| : 1520 |Defense| : 804 |Speed| : 107 ALIVE |Sp | : Descente_Soignante \n\n");
printf ("|Name| : Arrion |Rank| : B |Max Hp| : 16020  |Attack| : 1674 |Defense| : 837 |Speed| : 104 ALIVE |Sp| : Epee_Ultime\n \n");
printf("|Name| : Daera |Rank| : S |Max Hp| : 19650  |Attack| : 1013 |Defense| : 1255 |Speed| : 106 ALIVE |Sp| : Barriere_Protectrice \n\n");
printf("|Name| : Ada |Rank| :A |Max Hp| : 20145 |Attack| : 1255 |Defense| : 980 |Speed| : 108 ALIVE |Sp|: Boost_Supreme\n\n");
printf ("|Name| :Tagriel |Rank|: B |Max Hp| : 31050 |Attack| : 1432 |Defense| : 1112 |Speed| : 85 ALIVE |Sp| : Aspiration \n\n");
printf ("|Name| : Lorel |Rank| : B |Max Hp| : 20805 |Attack| : 1002 |Defense| : 1189 |Speed| : 111 ALIVE |Speed| : Tornade\n\n" );
printf ("|Name| : Arel |Rank| : B |Max Hp| : 15690  | Attack| : 1696 |Defense| : 837 |Speed| : 101 ALIVE |Sp| : Charge_Shot\n\n" );
printf ("|Name| : Deam |Rank| : A |Max Hp| : 18165 |Attack| : 1332 |Defense| : 1035 |Speed| : 115 ALIVE |Sp| : Tempete\n\n" );
}

void Display_Team_Info(Team t){  
  printf(" _[%-20.20s]__________________________________________________________\n", t.name );
  printf("|%-81s|\n","");
  for(int i=0; i<t.players; i=i+2){

    if(i < t.players-1){
      printf("|   [%-2.2d] [%-10.10s] %s   [%-2.2d] [%-10.10s] %s\n", i, t.f[i].name, t.f[i].alive ? "ALIVE":"DEAD ", i+1, t.f[i+1].name, t.f[i+1].alive ? "ALIVE":"DEAD ");
      printf("|    %-5.5d/%-5.5d HP            %-5.5d/%-5.5d HP\n", t.f[i].health, t.f[i].max_health, t.f[i+1].health, t.f[i+1].max_health);
      printf("|   spe: %-18.18s   spe: %-18.18s\n", t.f[i].sp_attack.nom, t.f[i+1].sp_attack.nom);

    }
    else{
      printf("|   [%-2.2d] [%-10.10s] %s\n", i, t.f[i].name, t.f[i].alive ? "ALIVE":"DEAD ");
      printf("|       %-5.5d/%-5.5d HP\n", t.f[i].health, t.f[i].max_health);
      printf("|   spe: %-18.18s\n", t.f[i].sp_attack.nom);
    }
    printf("|%-81s|\n","");
    
  }
  printf("_________________________________________________________________________________\n");
}

