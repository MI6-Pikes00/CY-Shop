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
        // add case where product referance is unknowed
    }
    return 0;
}

//Function to sort item by name or referance or quantity by selection in the menu

int sortProduct(){
    return 0;
}