#include "struct.h"
Special construct_spe(char *nom){  //constructeur de la structure Special
  Special s;
  int l,c,n=0;
  char buffer[1000];
  FILE *fichier1;
  fichier1=fopen("../file/description_effets_spéciaux.txt","r+");//ouverture du fichier des effets spéciaux
  if (fichier1==NULL){// verification de l'ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  fscanf(fichier1, "%s", buffer);//récupération du premier mot 
  while (strcmp(buffer,nom)!=0){
    fseek(fichier1,9,1);
    fscanf(fichier1,"%s",buffer);
  }
  l=strlen(buffer);
  s.nom=malloc((l+1)*sizeof(char));
  if (s.nom==NULL){ //vérification allocation mémoire
    printf ("Erreur allocation mémoire\n");
    exit(1);
  }
  strcpy(s.nom,buffer);// copie de la chaine de buffer dans nom
  s.nom[l]='\0';
  fscanf(fichier1,"%d",&s.spe_type);// récupération de la valeur du type du fichier texte 
  fscanf(fichier1,"%d",&s.valeur); // récupération de la valeur du coup spécial du fichier texte
  fscanf(fichier1,"%d",&s.nmb_tourActif);//récupération du nombre de tours actifs de l'effet spécial
  fscanf(fichier1,"%d",&s.nmb_tourRecharge);//récupération du nombre de tours de recharge 
  fclose (fichier1);// fermeture du fichier
  return s;
}


Fighter construct_fighter(){ //constructeur de la structure Fighter
  Fighter f;
  FILE *fichier2;
  char *nom_effet;
  fichier2=fopen("../file/combattants.txt","r+");// ouverture du fichier texte des effets spéciaux
  if(fichier2==NULL){//verification ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  fscanf(fichier2, "%s",f.name); //récupérer le nom du fichier texte
  fscanf(fichier2,"%c",f.rang);// récupérer le rang du fichier texte 
  fscanf(fichier2,"%d",&f.max_health); // récupérer la valeur de max_health du fichier
  fscanf(fichier2,"%d",&f.health);// récupérer la valeur de health du fichier 
  fscanf(fichier2,"%d",&f.attack);// récupérer la valeur des attaques du fichier texte
  fscanf(fichier2,"%d",&f.defense);// récupérer la valeur des défenses du fichier texte
  f.dodge=rand()%11 +1; 
  fscanf(fichier2,"%d",&f.speed);// récupérer la valeur de la vitesse du fichier texte
  fscanf(fichier2,"%d",&f.alive);
  fscanf(fichier2, "%s", nom_effet);// récupérer le nom de l'effet spécial
  f.sp_attack=construct_spe(nom_effet); // constructeur de l'effet spécial 
  fscanf(fichier2,"%d",&f.spe_effects);//récupérer la valeur de la durée de l'effet 
  fclose(fichier2);// fermeture du fichier 
  return f;
}

Team construct_team(){  //constructeur de la structure Team
  Team t;
  do{
  printf ("saisissez le nombre de joueurs :\n");
  scanf ("%d",&t.players);
  }while (t.players<2);
  printf ("Saisissez le nom de votre equipe:\n");
  scanf ("%s",t.name);
  t.f=malloc(t.players*sizeof(Fighter));
  if (t.f==NULL){
    printf ("erreur allocation memoire\n");
    exit(1);
  }
  for (int i=0; i<t.players; i++){
    t.f[i]=construct_fighter();
  }
  return t;
}