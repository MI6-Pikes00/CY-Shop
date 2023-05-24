#include "structFile.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_CLIENTS 1000 // Maximum number of clients that can be registered

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
            //appeller la fonction main de purchase
            break;
        }
    }

    if (i == nbClients)
    {
        printf("Invalid account number.\n");
    }
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


/* int main()
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
            accountAcces(clients, nbClients);
            break;

        case 2: // Create a new account
            accountRegister(clients, &nbClients);
            break;

        case 3: // Delete account
            deleteAccount(clients, nbClients);
            break;

        case 4: // Exit
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid choice.\n");
            printf("\n");
            break;
        }
    } while (choix != 4);

    return 0;
}
 */