#include "clientPurchase.h"
#include "editFileCustomer.h"
#include "editFileProduct.h"
#include "structFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* int main()
{

    // Creation of product tab to simulate reality

    Product products[100];
    int nb_products = 0;

    loadProduct(products, &nb_products, "products.txt");

    // Quick menu to test the different functions

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
    }
} */


int main()
{
    srand(time(NULL));
    Customer clients [MAX_CLIENTS];
    int nbClients = 0;

    // Main menu
    int choix;
    do
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
            clearConsole();
            int i = 0;
            if((i=accountAcces(clients, nbClients)!=0)){
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
            printf("Goodbye!\n");
            clearConsole();
            break;

        default:
            printf("Invalid choice.\n");
            printf("\n");
            break;
        }
    } while (choix != 4);

    return 0;
}