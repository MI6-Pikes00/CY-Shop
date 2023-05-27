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

    Product products[SIZE_SHOP];
    int nb_products = 0;

    int i = 0;
    int choice = 0;
    int choiceUn = 0;
    int choiceDeux = 0;

    int ref = 0;
    int q = 0;

    loadProduct(products, &nb_products, "products.txt");

    while (1)
    {
        printf("MAIN MENU\n");
        printf("1. Stock management\n");
        printf("2. Customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1: // Gestion mode
            while (1)
            {
                quickSort(products, 0, nb_products - 1);

                printf("\n");
                stockVerification(products, nb_products);
                printf("\n");

                printf("1. Display products list\n");
                printf("2. Add new product\n");
                printf("3. Modifies product quantity\n");
                printf("4. Quit\n");
                printf("Enter your choice: ");
                scanf("%d", &choiceUn);

                switch (choiceUn)
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
                    
                    printf("Enter the reference of the product whose quantity you want to change: ");
                    scanf("%d", &ref);
                    printf("Put new quantity to add : ");
                    scanf("%d", &q);
                    modifiesQuantity(products, nb_products, ref, q);
                    saveProduct(products, nb_products, "products.txt");
                    break;

                case 4:
                    saveProduct(products, nb_products, "products.txt");
                    return 0;
                    break;

                default:
                    printf("Invalid choice.\n");
                    printf("\n");
                    break;
                }
            };

        case 2: // Purchase mode
            while (1)
            {
                loadCustomer(clients, &nbClients);
                printf("MAIN MENU\n");
                printf("1. Login\n");
                printf("2. Register\n");
                printf("3. Delete account\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choiceDeux);
                printf("\n");
                switch (choiceDeux)
                {
                case 1: // Login
                    // clearConsole();
                    i = accountAcces(clients, nbClients);
                    if ((i != -1))
                    {
                        purchase(clients, nbClients, i);
                    }
                    break;

                case 2: // Register
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
