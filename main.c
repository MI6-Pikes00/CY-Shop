#include "clientPurchase.h"
#include "editFileCustomer.h"
#include "editFileProduct.h"
#include "structFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    Customer clients[MAX_CLIENTS];
    int nbClients = 0;

    Product products[100];
    int nb_products = 0;
    int i = 0;
    int choix = 0;
    while (1)
    {
        printf("MAIN MENU\n");
        printf("1. Purchase mode\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choix);
        printf("\n");
        switch (choix)
        {
        case 1: // Gestion mode
            while (1)
            {
                loadProduct(products, &nb_products, "products.txt");

                quickSort(products, 0, nb_products - 1);
                saveProduct(products, nb_products, "products.txt");

                printf("\n");
                stockVerification(products, nb_products);
                printf("\n");
                printf("1. Display products list\n");
                printf("2. Add new product\n");
                printf("3. Modifies product quantity\n");
                printf("4. Quit\n");

                int choice;
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Products list:\n");
                    displayProduct(products, nb_products);
                    break;
                case 2:
                    addProduct(products, &nb_products);
                    quickSort(products, 0, nb_products - 1);
                    saveProduct(products, nb_products, "products.txt");
                    break;
                case 3:
                    modifiesQuantity(products, nb_products);
                    saveProduct(products, nb_products, "products.txt");
                    break;

                case 4:
                    return 0;
                    break;

                default:
                    printf("Erreur : choice invalide\n");
                }
            };

        case 2: // Purchase mode
            while (1)
            {
                loadCustomer(clients, &nbClients);
                printf("MAIN MENU\n");
                printf("1. Register\n");
                printf("2. Create a new account\n");
                printf("3. Delete an account\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choix);
                printf("\n");
                switch (choix)
                {
                case 1: // Identify yourself
                    //clearConsole();
                    i = accountAcces(clients, nbClients);
                    if ((i != -1))
                    {
                        purchase(clients, nbClients, i);
                    }
                    break;

                case 2: // Create a new account
                    clearConsole();
                    accountRegister(clients, &nbClients);
                    break;

                case 3: // Delete account
                    clearConsole();
                    deleteAccount(clients, nbClients);
                    break;

                case 4: // Exit
                    return 0;
                    break;

                default:
                    printf("Invalid choice.\n");
                    printf("\n");
                    break;
                }
            };

        case 3: // Exit
            printf("Goodbye!\n");
            clearConsole();
            break;

        default:
            printf("Invalid choice.\n");
            printf("\n");
            break;
        };

        return 0;
    }
}
