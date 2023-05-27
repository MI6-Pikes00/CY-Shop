#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structFile.h"
#define TAB 10

// Function to search an Item by his name or reference

int searchProduct(Product products[], int nb_products)
{
    int choice;
    int ref;
    char name[SIZE];
    while (1)
    {
        printf("This is for search a product by name or reference\n");
        printf("1. By name\n");
        printf("2. By reference\n ");
        printf("Enter choice : ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // search product by name

            printf("Enter the name of product : ");
            scanf("%s", name);

            for (int i = 0; i < nb_products; i++)
            {
                if (strcmp(name, products[i].name) == 0)
                {
                    printf("\tName : %s", products[i].name);
                    printf("\tReference : %d", products[i].reference);
                    printf("\tQuantity : %d\n", products[i].quantity);
                }
                else
                {
                    printf("Not found...");
                }
            }

            break;

        case 2: // search product by reference

            printf("Enter the reference: ");
            scanf("%d", &ref);

            for (int i = 0; i < TAB; i++)
            {
                if (products[i].reference == ref)
                {
                    printf("\tName : %s", products[i].name);
                    printf("\tReference : %d", products[i].reference);
                    printf("\tQuantity : %d\n", products[i].quantity);
                }
                printf("The typed reference is unknown\n");
            }
            break;

        default:
            break;
        }
    }

    return 0;
}
