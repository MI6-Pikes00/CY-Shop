#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structFile.c"
#define TAB 10

//Function to search an Item

int searchProduct(Product productArray[], int referance){
    for (int i = 0; i<TAB; i++){
        if(productArray[i].referance == referance){
            return productArray[i].quantity;
        }
        printf("The typed reference is unknown\n");
    }
    return 0;
}

//Function to sort item by name or referance or quantity by selection in the menu
//1 : Name
//2 : Quantity

int sortProduct(int i){
    switch (i){
    case 1:
        /* code */
        break;

    case 2:
        /* code */
        break;

    default:
        printf("type of sort unsigned\n");
        break;
    }
    return 0;
}

