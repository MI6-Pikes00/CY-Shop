#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structFile.c"


void sauvegarder_clients(Customer clients[], int nb_clients, char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    fprintf(fichier, "%d\n", nb_clients);

    for (int i = 0; i < nb_clients; i++) {
        fprintf(fichier, "%s\n", clients[i].firstName);
        fprintf(fichier, "%s\n", clients[i].name);
        fprintf(fichier, "%d\n", clients[i].nbPurchase);
        for (int j = 0; j < clients[i].nbPurchase; j++) {
            fprintf(fichier, "%d ", clients[i].purchase[j]);
        }
        fprintf(fichier, "\n");
    }

    fclose(fichier);
}

void charger_clients(Customer clients[], int* nb_clients, char* nom_fichier) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    fscanf(fichier, "%d\n", nb_clients);

    for (int i = 0; i < *nb_clients; i++) {
        fscanf(fichier, "%s\n", clients[i].firstName);
        fscanf(fichier, "%s\n", clients[i].name);
        fscanf(fichier, "%d\n", &clients[i].nbPurchase);
        for (int j = 0; j < clients[i].nbPurchase; j++) {
            fscanf(fichier, "%d ", &clients[i].purchase[j]);
        }
        fscanf(fichier, "\n");
    }

    fclose(fichier);
}

void ajouter_client(Customer clients[], int* nb_clients) {
    printf("Entrez le nom du nouveau client : ");
    scanf("%s", clients[*nb_clients].firstName);

    printf("Entrez le prenom du nouveau client : ");
    scanf("%s", clients[*nb_clients].name);

    clients[*nb_clients].nbPurchase = 0;

    (*nb_clients)++;
}

void ajouter_commande(Customer clients[], int nb_clients) {
    printf("Entrez le nom du client : ");
    char nom[100];
    scanf("%s", nom);

    printf("Entrez le prenom du client : ");
    char prenom[100];
    scanf("%s", prenom);

    int client_trouve = 0;
    for (int i = 0; i < nb_clients; i++) {
        if (strcmp(clients[i].firstName, nom) == 0 && strcmp(clients[i].name, prenom) == 0) {
            printf("Entrez le numero de la commande : ");
            int commande;
            scanf("%d", &commande);

            clients[i].purchase[clients[i].nbPurchase] = commande;
            clients[i].nbPurchase++;

            client_trouve = 1;
            break;
        }
    }

    if (!client_trouve) {
        printf("Client introuvable\n");
    }
}


/* int main() {
    Customer clients[100];
    int nb_clients = 0;

    charger_clients(clients, &nb_clients, "clients.txt");

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
            ajouter_client(clients, &nb_clients);
            sauvegarder_clients(clients, nb_clients, "clients.txt");
        } 
        
        else if (choix == 3) {
            ajouter_commande(clients, nb_clients);
            
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