#include <stdio.h> 
#include <stdlib.h>

typedef struct{
    int Num;
    char Nom[100];
    char Prenom[1001];
    char email[1001];
} gestion;

typedef struct{
    int numero;
    char matiere[1001];
    char niveau[100];
    int note;
} purchase;

void home(){
    printf("\n \t\t\t WELCOME ON LT'S SHOP \n");
    printf("\n \t\t\t Please choose a menu : \n");
    printf("\n \t\t\t Gestion Mod...");
    printf("\n \t\t\t Purchase Mod...");
    printf("\n \n \t\t\t Exit...");
}

int main(){
    char select[15];

    // Affichage des différents menus : ...

    scanf("%s", &select);

    return 0;
}