#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{  //Création de la structure Special
  char *nom;
 /* char *description;*/
  int nmb_tourActif;
  int nmb_tourRecharge;
  int valeur; //0=DEGAT, 1=HEAL, 2=BOOST
  int spe_type ;
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

Special construct_spe(int pos_ligne){  //constructeur de la structure Special
  Special s;
  int l,c,n=0;
  char buffer[1000];
  FILE *fichier1;
  fichier1=fopen("description_effets_spéciaux.txt","r+");//ouverture du fichier des effets spéciaux
  if (fichier1==NULL){// verification de l'ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  c=fgetc(fichier1);
  while (n!=pos_ligne){
    while (c!='\n'){
      fgetc(fichier1);
    }
  n++;
  }
  fscanf(fichier1, "%s", buffer);//récupération du premier mot 
  l=strlen(buffer);
  s.nom=malloc((l+1)*sizeof(char));
  if (s.nom==NULL){ //vérification allocation mémoire
    printf ("Erreur allocation mémoire\n");
    exit(1);
  }
  strcpy(s.nom,buffer);// copie de la chaine de buffer dans nom
  fscanf(fichier1,"%d",&s.spe_type);// récupération de la valeur du type du fichier texte 
  fscanf(fichier1,"%d", &s.valeur); // récupération de la valeur du coup spécial du fichier texte
  fclose (fichier1);// fermeture du fichier
  return s;
}

Fighter construct_fighter(){ //constructeur de la structure Fighter
  Fighter f;
  FILE *fichier2;
  fichier2=fopen("combattants.txt","r+");// ouverture du fichier texte des effets spéciaux
  if(fichier2==NULL){//verification ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  fscanf(fichier2, "%s",f.name); //récupérer le nom du fichier texte
  fscanf(fichier2,"%s",f.rang);// récupérer le rang du fichier texte 
  fscanf(fichier2,"%d",&f.max_health); // récupérer la valeur de max_health du fichier
  fscanf(fichier2,"%d",&f.health);// récupérer la valeur de health du fichier 
  fscanf(fichier2,"%d",&f.attack);// récupérer la valeur des attaques du fichier texte
  fscanf(fichier2,"%d",&f.defense);// récupérer la valeur des défenses du fichier texte
  f.dodge=rand()%11 +1; 
  fscanf(fichier2,"%s",&f.speed);// récupérer la valeur de la vitesse du fichier texte
  fscanf(fichier2, "%d", f.sp_attack);// récupérer l'effet special du combattant
  fscanf(fichier2,"%d",&f.spe_effects);//récupérer la valeur de la durée de l'effet 
  fclose(fichier2);// fermeture du fichier 
  return f;
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
  int mode_jeu = 0;
  int dif = 0;
  do{
    printf("Quel mode de jeux voulez-vous ?\n1 : pour Joueur VS Machine \n2 : pour Joueur VS Joueur");
  scanf("%d", &mode_jeu);
  }while((mode_jeu != 1) || (mode_jeu != 2));  //test de vérification

  if(mode_jeu == 1){  //pour lancer le 1er mode : Joueur VS Machine
    do{
      printf("Choix du mode de difficulté : \n1 : pour Noob \n2 : pour Facile \n3 : pour Moyen \n4 : pour Difficile \n5 : pour Torture \n");
      scanf("%d", &dif);
    }while((dif < 1) || (dif > 5));
    combat1();
  }
    
  else{  //pour lancer le 2nd mode : Joueur VS Joueur 
    combat2();
  }
}
