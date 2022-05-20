#include <stdio.h>
#include <stdlib.h>

enum type {DEGAT, HEAL, BOOST};
/*v=strcmp(s, "DEGAT")*/
typedef struct{  //Création de la structure Special
  char *nom;
  char *description;
  int nmb_tourActif;
  int nmb_tourRecharge;
  int valeur;
  enum type spe_type ;
}Special;

typedef struct{  //Création de la structure Fighter
  char name[50];
  char rang;
  int max_health;
  int health;
  int attack;
  int defense;
  int dodge;
  int speed;
  Special sp_attack;
  int spe_effects;
}Fighter;

typedef struct{  //Création de la structure Team
  int players;
  char* name;
  Fighter f1;
  Fighter f2;
  Fighter f3;
}Team;

int nmbr_char_ligne(FILE *fichier){//Fonction qui calcule le nombre de caractères de la plus longue ligne dans un fichier
  int compt=0,max=0;
  int c=fgetc(fichier);
  while (c!=EOF){//la boucle s'arrête à  la fin du fichier
    while(fgetc(fichier)!=':');//récupérer les lignes après les deux points dans le fichier
    while (c!='\n'&& c!=EOF){ //boucle pour calculer le nombre de caractères par ligne 
      compt++;
      c=fgetc(fichier);
    }
    if (max<compt){
      max=compt;
    } 
  } 
  return max;
}

Special construct_spe(){  //constructeur de la structure Special
  Special effet;
  int n;
  char *s;
  FILE *fichier1;
  fichier1=fopen("description_effets_spéciaux.txt","r+");//ouverture du fichier des effets spéciaux
  if (fichier1==NULL){// verification
      printf("Ouverture du fichier impossible\n");
      exit(1);
    }
  n=nmbr_char_ligne(fichier1);//récupération du n max de caractères par lignes dans le fichier
  effet.nom=malloc(n*sizeof(char));
  if (effet.nom==NULL){ //vérification allocation mémoire
      printf ("Erreur allocation mémoire\n");
      exit(1);
    }
  fscanf(fichier1,"Nom : %s", effet.nom);
  effet.description=malloc(n*sizeof(char));
  if (effet.description==NULL){ //vérification allocation mémoire
    printf ("Erreur allocation mémoire\n");
    exit(1);
  }
  fscanf(fichier1, "Description : %s", effet.description);
  s=malloc(n*sizeof(char));
  fscanf(fichier1, "Type : %s", s);
  if (!strcmp(s, "DEGAT")){
    effet.spe_type = DEGAT;
  }else  if (!strcmp(s, "HEAL")){
    effet.spe_type = HEAL;
  } else if (!strcmp(s, "BOOST")){
    effet.spe_type = BOOST;
  }
  fscanf((fichier1,  "%d", &effet.valeur));
  fclose (fichier1);
  return effet;
}

Fighter construct_fighter(){ //constructeur de la structure Fighter
  
}

Team construct_team(){  //constructeur de la structure Team
  
}

void disp_align(char chain[], int place){
    int compt = strlenght(chain);
    if(place == 0){ //0 correspond à la fin des encadrés
        for(int i = 0; i < compt;i++){
            printf("_");
        }
        printf("\n");
    }
    if(place == 1){
        for(int i = 0; i < compt;i++){
            printf("_");
        }
        printf("\n");
    }
    
    
}

void display(Team t1, Team t2){  //procédure pour afficher l'interface graphique
printf("_[%s]______________________________\n", t1.name);   //1ère équipe - adverse
printf("| |\n");
printf("|   %s |1|", t1.f1.name);
printf("_________________________________");


printf("_[%s]______________________________", t2.name); // 2nd équipe - joueur

printf("_________________________________");

}

void fight1(){  //procédure de combat d'un Joueur VS Machine
  while(){
    
  }
}

void fight2(Team t1, Team t2){  //procédure de combat d'un Joueurs VS un Joueur
  while((t1 > 0) && (t2 > 0)){
    
  }
}

int main(void){
  int mode1 = 0;
  int mode2 = 0;
  Do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");
  scanf("%d", &mode1);
  while((mode1 != 1) || (mode1 != 2));  //test de vérification

  if(mode == 1){  //pour lancer le 1er mode : Joueur VS Machine
    Do{
      printf("Choix du mode de difficulté : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n5 : pour Torture \n");
    scanf("%d", &mode2)
    while((mode2 < 1) || (mode2 > 5);
    combat1();
  }
    
  else{  //pour lancer le 2nd mode : Joueur VS Joueur 
    combat2();
  }
}
