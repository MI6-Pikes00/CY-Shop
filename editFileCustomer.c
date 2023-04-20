#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structFile.c"

// Function to save new data to clients.txt.

void saveClients(Customer clients[], int nb_clients, char *fileName)
{
    FILE *file = fopen(fileName, "w");
    if (file == NULL)
    {
        printf("Error : unable to open the file %s\n", fileName);
        return;
    }

    fprintf(file, "%d\n", nb_clients);

    for (int i = 0; i < nb_clients; i++)
    {
        fprintf(file, "%s\n", clients[i].firstName);
        fprintf(file, "%s\n", clients[i].name);
        fprintf(file, "%d\n", clients[i].nbPurchase);
        for (int j = 0; j < clients[i].nbPurchase; j++)
        {
            fprintf(file, "%d ", clients[i].purchase[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to load data from clients.txt to modifies them.

void loadClients(Customer clients[], int *nb_clients, char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error : unable to open the file %s\n", fileName);
        return;
    }

    fscanf(file, "%d\n", nb_clients);

    for (int i = 0; i < *nb_clients; i++)
    {
        fscanf(file, "%s\n", clients[i].firstName);
        fscanf(file, "%s\n", clients[i].name);
        fscanf(file, "%d\n", &clients[i].nbPurchase);
        for (int j = 0; j < clients[i].nbPurchase; j++)
        {
            fscanf(file, "%d ", &clients[i].purchase[j]);
        }
        fscanf(file, "\n");
    }

    fclose(file);
}

// Function to add new client to data file.

void addClient(Customer clients[], int *nb_clients)
{
    printf("Put new customer first name : ");
    scanf("%s", clients[*nb_clients].firstName);

    printf("Put name of new customer : ");
    scanf("%s", clients[*nb_clients].name);

    clients[*nb_clients].nbPurchase = 0;

    (*nb_clients)++;
}

// Function to add purchase to specific customer.

void addPurchase(Customer clients[], int nb_clients)
{
    printf("Put first name of customer : ");
    char firstName[100];
    scanf("%s", firstName);

    printf("Put name of customer : ");
    char name[100];
    scanf("%s", name);

    int client_trouve = 0;
    for (int i = 0; i < nb_clients; i++)
    {
        if (strcmp(clients[i].firstName, firstName) == 0 && strcmp(clients[i].name, name) == 0)
        {
            printf("Put reference order : ");
            int commande;
            scanf("%d", &commande);

            clients[i].purchase[clients[i].nbPurchase] = commande;
            clients[i].nbPurchase++;

            client_trouve = 1;
            break;
        }
    }
    // Error case if the user put another value like text or unkonow client.
    if (!client_trouve)
    {
        printf("Customer not found\n");
    }
}

// Function to test that the above functions work well during development.

/*int main() {

    //Creation of client tab to simulate reality
    Customer clients[100];
    int nb_clients = 0;

    loadClients(clients, &nb_clients, "clients.txt");
    //Quick menu to test the different functions
    while (1) {
        printf("1. Afficher la liste des clients\n");
        printf("2. Ajouter un nouveau client\n");
        printf("3. Ajouter une commande\n");
        printf("4. Quitter\n");

        int choix;
        scanf("%d", &choix);

        if (choix == 1) {
            for (int i = 0; i < nb_clients; i++) {
                printf("%s %s : ", clients[i].name, clients[i].firstName);
                for (int j = 0; j < clients[i].nbPurchase; j++) {
                    printf("%d ", clients[i].purchase[j]);
                }
                printf("\n");
            }
        }

        else if (choix == 2) {
            addClient(clients, &nb_clients);
            saveClients(clients, nb_clients, "clients.txt");
        }

        else if (choix == 3) {
            addPurchase(clients, nb_clients);

        }

        else if (choix == 4) {
            break;
        }

        else {
            printf("Choix invalide\n");
        }
    }

    return 0;
}
 */