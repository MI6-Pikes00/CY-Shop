#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structFile.h"
#define TAB 10

// Function to search an Item

int searchProduct(Product productArray[], int referance)
{
    int choice;
    printf("This is for search a product by name or reference\n");
    printf("1. By name\n");
    printf("2. By reference\n ");
    printf("Enter choice : ");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // search product by name

            // saisie de la réference
            
            // strcmp <- fonction pour comparer deux chaines de caractères (inclue dans <string.h>)

        /* code */
        break;

    case 2: // search product by reference
        
        // saisie de la réference


        for (int i = 0; i < TAB; i++)
        {
            if (productArray[i].reference == referance)
            {
                return productArray[i].quantity;
            }
            printf("The typed reference is unknown\n");
        }
        break;

    default:
        break;
    }

    return 0;
}
