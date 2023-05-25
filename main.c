#include "clientPurchase.h"
#include "editFileCustomer.h"
#include "structFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    Customer clients [MAX_CLIENTS];
    int nbClients = 0;
    loadCustomer(clients, nbClients);
    // Main menu
    int choix;
    do
    {
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
            if(accountAcces(clients, nbClients)){
                int i = accountAcces(clients, nbClients);
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