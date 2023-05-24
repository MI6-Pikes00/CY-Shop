#include "editFileProduct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_CLIENTS 1000 // Maximum number of clients that can be registered
#define P 1000           // Maximum article of panier can content

int genereraccountNumber()
{
    // Generation of a random number between 1000 and 9999
    srand(time(NULL));
    return rand() % (9999 + 1 - 1000);
}

int accountNumberAttributed(int accountNumber, Customer clients[], int nbClients)
{
    // Verification of the existence of the account number in the customer files
    for (int i = 0; i < nbClients; i++)
        if (clients[i].reference == accountNumber)
        {
            return 1;
        }
    return 0;
}

void accountRegister(Customer clients[], int *nbClients)
{
    int accountNumber = 0;
    if (*nbClients == MAX_CLIENTS)
    {
        printf("The maximum number of customers is reached.\n");
        return;
    }

    // Entering the new customer's information
    Customer newCustomer;
    printf("Enter your name: ");
    scanf("%s", newCustomer.firstName);
    printf("Enter your first name: ");
    scanf("%s", newCustomer.name);
    printf("Enter your password: ");
    scanf("%s", newCustomer.password);

    // Random generation of the account number
    do
    {
        accountNumber = genereraccountNumber();
    } while (accountNumberAttributed(accountNumber, clients, *nbClients));
    newCustomer.reference = accountNumber;

    // Add the new client to the list of clients    clients[*nbClients] = newCustomer;
    *nbClients++;

    // Save the new client in a file
    char fileName[20];
    sprintf(fileName, "%d.dat", accountNumber);

    char *folderPath = "clientFolder/";
    char *filePath = malloc(strlen(folderPath) + strlen(fileName) + 1);

    // Builds the complete path of the file
    strcpy(filePath, folderPath);
    strcat(filePath, fileName);

    FILE *file = fopen(filePath, "wb");
    if (file == NULL)
    {
        printf("Error while registering the new customer.\n");
        return;
    }
    fwrite(&newCustomer, sizeof(Customer), 1, file);
    fclose(file);

    printf("Your account has been successfully created.\n");
    printf("This is your account number: %d\n", accountNumber);
    printf("\n");
}

void deleteFile(int accountNumber)
{
    char fileName[20];
    sprintf(fileName, "%d.dat", accountNumber);

    char *folderPath = "clientFolder/";
    char *filePath = malloc(strlen(folderPath) + strlen(fileName) + 1);

    // Construit le chemin complet du file
    strcpy(filePath, folderPath);
    strcat(filePath, fileName);
    if (remove(filePath) == 0)
    {
        printf("Your %d account has been successfully deleted.\n", accountNumber);
    }
    else
    {
        perror("Error while deleting the file");
    }
}

void deleteAccount(Customer clients[], int nbClients)
{
    int accountNumber = 0;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("\n");

    if (accountNumberAttributed(accountNumber, clients, nbClients))
    {
        int choix = 0;
        do
        {
            printf("Do you want to delete your account\n");
            printf("1. Validate\n");
            printf("2. Cancel\n");

            printf("Enter your choice: ");
            scanf("%d", &choix);
            printf("\n");
            switch (choix)
            {
            case 1: // Deleting file
                deleteFile(accountNumber);
                return;

            case 2: // Cancel
                printf("Annulation ...\n");
                break;
            }
        } while (choix != 2);

        printf("Your account number does not exist.\n");
    }
}

void purchase(Customer clients[], int nbClients, int i)
{   
    Product products[100];
    int nb_products = 0;
    loadProduct(products, &nb_products, "products.txt");

    printf("Hello %s %s.\n", clients[i].name, clients[i].firstName);
    Panier panier[P];
    int nbItem = 0;
    int choix;
    int c;
    int choixpouraddaupanier;
    int q;

    do
    {
        printf("\n");
        printf("1. Purchase history\n");
        printf("2. Panier (%d)\n", nbItem);
        printf("3. Recherche article\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix)
        {
        case 1: // Print purchase history
            clearConsole();
            printf("Purchase history:\n");
            for (int j = 0; j < clients[i].nbPurchase; j++)
            {
                printf("%d", clients[i].purchase[j]);
            }
            break;

        case 2: // Access to the card
            clearConsole();
            do
            {
                if (nbItem == 0)
                {
                    printf("Votre panier est vide\n");
                }
                else
                {
                    float ptotal = 0;
                    for (int i = 0; i < nbItem; i++)
                    {
                        printf("%s ", panier[i].name);
                        printf("%d ", panier[i].quantity);
                        printf("%f\n", panier[i].price);
                        ptotal += panier[i].price;
                    }
                    printf("Total %f\n", ptotal);
                }
                printf("\n");
                printf("1. Validé\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choix);
                printf("\n");

                switch (choix)
                {
                case 1:
                    printf("Validate panier process en cours\n");
                    break;

                case 2:
                    printf("Return\n");
                    clearConsole();
                    break;

                default:
                    break;
                }

            } while (choix != 2);
            break;

        case 3: // Menu to search object to buy
            clearConsole();
            for (int i = 0; i < nb_products; i++)
            {
                if (products[i].quantity > 0)
                {
                    printf("\tName : %s", products[i].name);
                    printf("\tReference : %d", products[i].reference);
                    printf("\tQuantity : %d\n", products[i].quantity);
                }
            }

            do
            {
                printf("\n");
                printf("1. Add to panier\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choix);
                printf("\n");

                switch (choix)
                {
                case 1:
                    clearConsole();
                    printf("Enter the reference: ");
                    scanf("%d", &choixpouraddaupanier);

                    printf("Enter the quantity you wants ");
                    scanf("%d", &q);

                    for (int i = 0; i < nb_products; i++)
                    {
                        if (products[i].reference == choixpouraddaupanier)
                        {
                            if (products[i].quantity - q >= 0)
                            {
                                strcpy(panier[nbItem].name, products[i].name);
                                panier[nbItem].reference = products[i].reference;
                                panier[nbItem].price = products[i].price;
                                panier[nbItem].quantity = q;
                                nbItem++;
                                printf("Added succesfully to panier\n");
                            }
                            else
                            {
                                printf("Saisir une quantité plus base pas assez de stocks \n");
                            }
                            
                            
                        }
                    }
                    break;

                case 2: // Exit
                    printf("Returning in connection.");
                    clearConsole();
                    break;

                default:
                    printf("Invalid choice.\n");
                    printf("\n");
                    break;
                }
            } while (choix != 2);
            break;
        case 4: // Exit
            printf("Déconection");
            clearConsole();
            break;

        default:
            printf("Invalid choice.\n");
            printf("\n");
            break;
        }
    } while (choix != 4);
}

void accountAcces(Customer clients[], int nbClients)
{
    int accountNumber = 0;

    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("\n");

    char pswd[SIZE];

    printf("Enter your password: ");
    scanf("%s", pswd);
    printf("\n");

    // Search for the client corresponding to the account number
    int i;
    for (i = 0; i < nbClients; i++)
    {
        if (clients[i].reference == accountNumber && strcmp(clients[i].password, pswd) == 0)
        {
            clearConsole();
            purchase(clients, nbClients, i);
            break;
        }
    }

    if (i == nbClients)
    {
        printf("Invalid account number.\n");
    }
    printf("\n");
}

int main()
{
    // Loading clients from files
    Customer clients[MAX_CLIENTS];
    int nbClients = 0;

    DIR *dossier;
    struct dirent *entree;
    dossier = opendir("clientFolder");
    if (dossier == NULL)
    {
        printf("Error when opening the client file.\n");
        return 1;
    }

    while ((entree = readdir(dossier)) != NULL)
    {
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0)
        {
            continue;
        }

        char fileName[20];
        char *folderPath = "clientFolder/";
        char *filePath = malloc(strlen(folderPath) + strlen(fileName) + 1);

        // Builds the complete path of the file
        strcpy(fileName, entree->d_name);
        strcpy(filePath, folderPath);
        strcat(filePath, fileName);

        FILE *file = fopen(filePath, "rb");
        if (file == NULL)
        {
            printf("Error when opening the file %s.\n", fileName);
            continue;
        }

        fread(&clients[nbClients], sizeof(Customer), 1, file);
        fclose(file);

        nbClients++;
    }
    closedir(dossier);

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
            accountAcces(clients, nbClients);
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