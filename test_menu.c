#include <stdio.h> 
#include <string.h>

void home(){
    printf("\n \t\t\t WELCOME ON LT'S SHOP \n");
    printf("\n \t\t\t Please choose a menu : \n");
    printf("\n \t\t\t Gestion Mod...");
    printf("\n \t\t\t Purchase Mod...");
    printf("\n \t\t\t Exit...");
    printf("\n \n \t\t\t Reply : ");
}

void gestion(){
    printf("\n \n \t\t\t\t [Gestion Mod] \n");
    printf("\n \t\t\t Welcome on the gestion mod ! \n");
    printf("\n \t Here you can search a product in the stock by the name or the reference.");
    printf("\n \t You can also manage the stock by purchasing new parts...\n");
    printf("\n \n \t\t [1] Search a product...");
    printf("\n \n \t\t [2] Manage the stock...");
    printf("\n \n \t\t [3] Exit [Gestion Mod]...\n");
    printf("\n \n Select menu by 1, 2 or 3 : ");
}

void purchase(){
    
}


// ----------------------- Main Program -----------------------


int main(){
    char select[20];

    
    // Affichage des différents menus
    home();
    scanf("%s", select);

    // Comparaison between input and menu names
    if(strcmp(select, "Gestion") == 0){
        gestion();
    }
    else if(strcmp(select, "Purchase") == 0){
        purchase();
    }
    else if(strcmp(select, "Exit") == 0){
        return 0;
    }
    else{
        printf("Error... Please make sure your input is correct");
    }

}