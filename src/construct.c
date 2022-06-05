#include "struct.h"

//constructeur de la structure Special
Special construct_spe(char *nom){  
  Special s;
  int l;
  char buffer[1000];
  FILE *fichier1=NULL;
  fichier1=fopen("../file/description_effets_speciaux.txt","r");//ouverture du fichier des effets spÃ©ciaux
  if (fichier1==NULL){// verification de l'ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  fscanf(fichier1, "%s", buffer);//rÃ©cupÃ©ration du premier mot 
  while (strcmp(buffer,nom)!=0){
    fscanf(fichier1,"%[^\n]",buffer);
    fscanf(fichier1,"%s",buffer);
    
  }
  l=strlen(buffer);
  s.nom=malloc((l+1)*sizeof(char));
  if (s.nom==NULL){ //vÃ©rification allocation mÃ©moire
    printf ("Erreur allocation mÃ©moire\n");
    exit(1);
  }
  strcpy(s.nom,buffer);// copie de la chaine de buffer dans nom
  s.nom[l]='\0';
  fscanf(fichier1,"%d",&s.spe_type);// rÃ©cupÃ©ration de la valeur du type du fichier texte 
  fscanf(fichier1,"%d",&s.valeur); // rÃ©cupÃ©ration de la valeur du coup spÃ©cial du fichier texte
  fscanf(fichier1,"%d",&s.nmb_tourActif);//rÃ©cupÃ©ration du nombre de tours actifs de l'effet spÃ©cial
  fscanf(fichier1,"%d",&s.nmb_tourRecharge);//rÃ©cupÃ©ration du nombre de tours de recharge 
  fclose (fichier1);// fermeture du fichier
  return s;
}

//constructeur de la structure Fighter
Fighter construct_fighter(const char *nom_fighter){ 
  Fighter f;
  FILE *fichier2;
  char nom_effet[1000];
  char buffer[1000];

  fichier2=fopen("../file/combattants.txt","r");// ouverture du fichier texte des effets spÃ©ciaux
  if(fichier2==NULL){//verification ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  
  fscanf(fichier2, "%s",buffer); //rÃ©cupÃ©rer le nom du fichier texte
  //rechercher le nom du combattant dans le fichier 
   while (strcmp(buffer,nom_fighter)!=0){
    fscanf(fichier2,"%[^\n]",buffer);
    if(fscanf(fichier2,"%s",buffer) == -1){
      f.alive = 0;
      return f;
    }
  }
  fgetc(fichier2);

  strcpy(f.name,buffer);
  fscanf(fichier2,"%c",&f.rank);// rÃ©cupÃ©rer le rang du fichier texte 
  fscanf(fichier2,"%d",&f.max_health); // rÃ©cupÃ©rer la valeur de max_health du fichier
  fscanf(fichier2,"%d",&f.health);// rÃ©cupÃ©rer la valeur de health du fichier 
  fscanf(fichier2,"%d",&f.attack);// rÃ©cupÃ©rer la valeur des attaques du fichier texte
  fscanf(fichier2,"%d",&f.defense);// rÃ©cupÃ©rer la valeur des dÃ©fenses du fichier texte
  f.dodge=rand()%11 +1; // esquive entre 1 et 10
  fscanf(fichier2,"%d",&f.speed);// rÃ©cupÃ©rer la valeur de la vitesse du fichier texte
  fscanf(fichier2,"%d",&f.alive);
  fscanf(fichier2, "%s", nom_effet);// rÃ©cupÃ©rer le nom de l'effet spÃ©cial
  f.sp_attack=construct_spe(nom_effet); // constructeur de l'effet spÃ©cial 
  fscanf(fichier2,"%d",&f.spe_effects);//rÃ©cupÃ©rer la valeur de la durÃ©e de l'effet 
  fclose(fichier2);// fermeture du fichier
  return f;
}

//constructeur de la structure Team
void construct_team(Team *to_inti, int n){  
  to_inti->players=n;
  printf ("Saisissez le nom de votre equipe:\n");
  scanf ("%s",to_inti->name);
  to_inti->f=malloc(to_inti->players*sizeof(Fighter));
  if (to_inti->f==NULL){
    printf ("erreur allocation memoire\n");
    exit(1);
  }
}