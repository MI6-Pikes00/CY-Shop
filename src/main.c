#include "clientPurchase.h"
#include "editFileCustomer.h"
#include "editFileProduct.h"
#include "search.h"
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
    int choiceOne = 0;
    int choiceTwo = 0;
    int choiceThree = 0;

    int ref = 0;
    int q = 0;

    int in_main = 1;
    int in_Log = 0;
    int in_Gestion = 0;
    int in_Customer = 0;

    loadProduct(products, &nb_products, "src/products.txt");

    while (in_main)
    {
        printf("1. Log In\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1: // Log In
            loadCustomer(clients, &nbClients);
            i = accountAcces(clients, nbClients);
            if ((i != -1))
            {
                in_Log = 1;
            }
            while (in_Log)
            {
                clearConsole();
                printf("\nHello %s %s.\n", clients[i].name, clients[i].firstName);
                printf("\n\n \tMAIN MENU\n\n");
                printf("1. Gestion\n");
                printf("2. Purchase\n");
                printf("3. Customer\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choiceOne);

                printf("\n");

                switch (choiceOne)
                {
                case 1: // Gestion mode
                    clearConsole();
                    choiceOne = 0;
                    in_Gestion = 1;
                    while (in_Gestion)
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
                        int valid = scanf("%d", &choiceTwo);
                        if (valid != 1)
                        {
                            while (getchar() != '\n')
                            {
                                // clean the entrances
                            }
                        }

                        switch (choiceTwo)
                        {
                        case 1:
                            printf("Products list:\n");
                            displayProduct(products, nb_products);
                            break;
                        case 2:
                            addProduct(products, &nb_products);
                            quickSort(products, 0, nb_products - 1);
                            saveProduct(products, nb_products, "src/products.txt");
                            break;
                        case 3:

                            printf("\nEnter the reference of the product whose quantity you want to change: ");
                            int validGestion = scanf("%d", &ref);
                            if (validGestion != 1)
                            {
                                while (getchar() != '\n')
                                {
                                    // clean the entrances
                                }
                            }
                            printf("\nPut new quantity to add: ");
                            int validGestion1 = scanf("%d", &q);
                            if (validGestion1 != 1)
                            {
                                while (getchar() != '\n')
                                {
                                    // clean the entrances
                                }
                            }
                            modifiesQuantity(products, nb_products, ref, q);
                            saveProduct(products, nb_products, "src/products.txt");
                            break;

                        case 4:
                            saveProduct(products, nb_products, "src/products.txt");
                            in_Gestion = 0;
                            break;

                        default:
                            printf("Invalid choice.\n");
                            printf("\n");
                            break;
                        }
                    };
                    break;

                case 2: // Purchase mode
                    clearConsole();
                    printf("\n");
                    purchase(clients, nbClients, i);
                    break;

                case 3: // Customer mode
                    clearConsole();
                    in_Customer = 1;
                    while (in_Customer)
                    {
                        printf("1. Delete account\n");
                        printf("2. Exit\n");
                        printf("Enter your choice: ");
                        int validCustomer = scanf("%d", &choiceThree);
                        if (validCustomer != 1)
                        {
                            while (getchar() != '\n')
                            {
                                // clean the entrances
                            }
                        }
                        printf("\n");
                        switch (choiceThree)
                        {
                        case 1: // Delete account
                            clearConsole();
                            deleteAccount(clients, nbClients, i);
                            break;

                        case 2: // Exit
                            in_Customer = 0;
                            break;

                        default:
                            printf("Invalid choice.\n");
                            printf("\n");
                            return 0;
                            break;
                        }
                    };

                case 4: // Exit
                    printf("Goodbye!\n");
                    clearConsole();
                    in_Log = 0;
                    break;

                default:
                    printf("Invalid choice.\n");
                    printf("\n");
                    break;
                };
            }

            break;

        case 2: // Register
            clearConsole();
            accountRegister(clients, &nbClients);
            break;

        case 3: // Exit
            printf("Goodbye!\n");
            clearConsole();
            in_main = 0;
            break;

        default:
            printf("Invalid choice.\n");
            printf("\n");
            break;
        };

        return 0;
    }
}
