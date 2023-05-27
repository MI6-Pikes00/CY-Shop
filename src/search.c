#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structFile.h"
#define TAB 10

// Function to search an Item by his name or reference

int searchProduct(Product products[], int nb_products)
{
    int choice;
    int ref = 0;
    char name[SIZE];
    int in_Search = 1;
    while (in_Search)
    {
        printf("\nThis is for search a product by name or reference\n");
        printf("1. By name\n");
        printf("2. By reference\n");
        printf("3. Exit\n");
        printf("Enter choice : ");
        int validSearch = scanf("%d", &choice);
        if (validSearch != 1)
        {
            while (getchar() != '\n')
            {
                // clean the entrances
            }
        }
        
        switch (choice)
        {
        case 1: // search product by name

            printf("Enter the name of product : ");
            scanf("%s", name);

            for (int i = 0; i < nb_products; i++)
            {
                if (strcmp(name, products[i].name) == 0)
                {
                    printf("\n\tName : %s", products[i].name);
                    printf("\tReference : %d", products[i].reference);
                    printf("\tQuantity : %d\n", products[i].quantity);
                }
            }

            break;

        case 2: // search product by reference

            printf("Enter the reference: ");
            scanf("%d", &ref);
            
            int validRef = scanf("%d", &ref);
            if (validRef != 1)
            {
                while (getchar() != '\n')
                {
                    // clean the entrances
                }
            }

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
        case 3:
            printf("Exit\n");
            in_Search = 0;
        default:
            printf("Error loading searching menu\n");
            break;
        }
    }

    return 0;
}
