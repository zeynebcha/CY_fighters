#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    float attaque;
    float defense;
    float esquive;
    float vie;
    char nom[50];
}Ninja;

void combat(Ninja a, Ninja b){
    float de, degats;
    while(a.vie > 0 && b.vie > 0){
        de = rand()%2 + 0;                  // Ninja a attaque et Ninja b défense
        if(de > b.esquive){
            degats = a.attaque - b.defense;
        } 
        if(degats>0){
            b.vie -= degats;
        }    

        de = rand()%2 + 0;                  // Ninja b attaque et Ninja a défense
        if(de > b.esquive){
            degats = b.attaque - a.defense;
        }  
        if(degats>0){
            a.vie -= degats;
        printf("vie ninja a : %f \nvie ninja b : %f", a.vie, b.vie);
        }
    }
    if(a.vie > 0){
        b.vie = 0;
        printf("Le ninja a a gagné");
    }
    else{
        a.vie = 0;
        printf("Le ninja b a gagné");
    }
}

int main(){
    Ninja Bob, Rox;
    srand(time(NULL));
    Bob.attaque = rand()%6+5;
    Bob.defense = rand()%3+2;
    Bob.esquive = rand()%1,1+0,1;
    Bob.vie = rand()%21+80;
    Rox.attaque = rand()%6+5;
    Rox.defense = rand()%3+2;
    Rox.esquive = rand()%1,1+0,1;
    Rox.vie = rand()%21+80;
    scanf("%s", Bob.nom);
    scanf("%s", Rox.nom);
    combat(Bob, Rox);
}