#include "struct.h"

Special construct_spe(char *nom){  //constructeur de la structure Special
  Special s;
  int l;
  char buffer[1000];
  FILE *fichier1=NULL;
  fichier1=fopen("../file/description_effets_speciaux.txt","r");//ouverture du fichier des effets spéciaux
  if (fichier1==NULL){// verification de l'ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  fscanf(fichier1, "%s", buffer);//récupération du premier mot 
  while (strcmp(buffer,nom)!=0){
    fscanf(fichier1,"%[^\n]",buffer);
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
Fighter construct_fighter(char *nom_fighter){ //constructeur de la structure Fighter
  Fighter f;
  FILE *fichier2;
  char nom_effet[1000];
  char buffer[1000];

  fichier2=fopen("../file/combattants.txt","r");// ouverture du fichier texte des effets spéciaux
  if(fichier2==NULL){//verification ouverture du fichier
    printf("Ouverture du fichier impossible\n");
    exit(1);
  }
  
  fscanf(fichier2, "%s",buffer); //récupérer le nom du fichier texte
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
  fscanf(fichier2,"%c",&f.rank);// récupérer le rang du fichier texte 
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

Team construct_team(int n){  //constructeur de la structure Team
  Team t;
  t.players=n;
  printf ("Saisissez le nom de votre equipe:\n");
  scanf ("%s",t.name);
  t.f=malloc(t.players*sizeof(Fighter));
  if (t.f==NULL){
    printf ("erreur allocation memoire\n");
    exit(1);
  }
  return t;
}
int main (void ){
  Team t1,t2;
  int nb_player;
  char b1[1000];
  char b2[1000];

  do {
    printf ("Donner le nombre de combattants :\n");
    scanf ("%d",&nb_player);
  }while (nb_player<2);

  printf("EQUIPE1:\n");
  t1=construct_team(nb_player);
  printf ("EQUIPE2:\n");
  t2=construct_team(nb_player);
  Fighter f_buff;
  for (int i=0; i<nb_player; i++){
    f_buff.alive = 0;
    while(!f_buff.alive){
      printf("Equipe1 saisissez le nom du combattant que vous voulez:\n");
      scanf("%s",b1);
      f_buff = construct_fighter(b1);
    }
    t1.f[i]=f_buff;
    f_buff.alive = 0;
    while(!f_buff.alive){
      printf("Equipe2 saisissez le nom du combattant que vous voulez:\n");
      scanf("%s",b2);
      f_buff = construct_fighter(b2);
    }
    t2.f[i]=f_buff;
  }

  printf ("Nom equipe 1 :%s\n",t1.name);
  printf ("le nombre de joueurs de l'equipe 1 : %d\n",t1.players);
  printf ("les combattants de l'equipe 1 sont :\n");

  for (int i=0; i<nb_player; i++){
   printf ("nom du combattant %d : %s ",i,t1.f[i].name);
   printf(" rang :%c ",t1.f[i].rank);
   printf("max_health: %d ",t1.f[i].max_health);
   printf("health:%d ",t1.f[i].health);
   printf("attack: %d ",t1.f[i].attack);
   printf("defense : %d",t1.f[i].defense);
   printf("dodge: %d ",t1.f[i].dodge);
   printf("speed : %d",t1.f[i].speed);
   printf("alive: %d ",t1.f[i].alive);
   printf("nom effet special:%s\n",t1.f[i].sp_attack.nom);
   printf ("nmb_tourActif%d",t1.f[i].sp_attack.nmb_tourActif);
   printf ("nmb_tourRecharge%d",t1.f[i].sp_attack.nmb_tourRecharge);
   printf ("valeur: %d",t1.f[i].sp_attack.valeur);
   printf ("type:%d",t1.f[i].sp_attack.spe_type);
   printf("spe_effects: %d",t1.f[i].spe_effects);
  }

  printf ("Nom equipe 2 :%s\n",t2.name);
  printf ("le nombre de joeurs de l'equipe 2 : %d\n",t2.players);
  printf ("les combattants de l'equipe 2 sont :\n");

  for (int i=0; i<nb_player; i++){
   printf ("nom du combattant %d : %s ",i,t2.f[i].name);
   printf(" rang :%c ",t2.f[i].rank);
   printf("max_health: %d ",t2.f[i].max_health);
   printf("health:%d ",t2.f[i].health);
   printf("attack: %d ",t2.f[i].attack);
   printf("defense : %d",t2.f[i].defense);
   printf("dodge: %d ",t2.f[i].dodge);
   printf("speed : %d",t2.f[i].speed);
   printf("alive: %d ",t2.f[i].alive);
   printf("nom effet special:%s\n",t2.f[i].sp_attack.nom);
   printf ("nmb_tourActif%d",t2.f[i].sp_attack.nmb_tourActif);
   printf ("nmb_tourRecharge%d",t2.f[i].sp_attack.nmb_tourRecharge);
   printf ("valeur: %d",t2.f[i].sp_attack.valeur);
   printf ("type:%d",t2.f[i].sp_attack.spe_type);
   printf("spe_effects: %d",t2.f[i].spe_effects);
  }
  
  return 0;
}