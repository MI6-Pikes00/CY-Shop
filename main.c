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
            int choice1 = 0;
            while (1)
            {
                quickSort(products, 0, nb_products - 1);

                saveProduct(products, nb_products, "products.txt");

                printf("\n");
                stockVerification(products, nb_products);
                printf("\n");
                printf("1. Display products list\n");
                printf("2. Add new product\n");
                printf("3. Modifies product quantity\n");
                printf("4. Quit\n");

                scanf("Enter your choice: %d", &choice1);

                switch (choice1)
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
                    printf("Invalid choice.\n");
                    break;
                }
            };

        case 2: // Purchase mode
            int choice2 = 0;
            while (1)
            {
                loadCustomer(clients, &nbClients);
                printf("MAIN MENU\n");
                printf("1. Login\n");
                printf("2. Register\n");
                printf("3. Delete account\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice2);
                printf("\n");
                switch (choice2)
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
