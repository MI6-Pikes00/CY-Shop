#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.c"
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

//

int sortProduct(){
    return 0;
}