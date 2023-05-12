#include "structFile.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_CLIENTS 1000 // Nombre maximum de clients pouvant être enregistrés

int genererNumeroCompte()
{
    // Génération d'un nombre aléatoire entre 1000 et 9999
    srand(time(NULL));
    return rand() % (9999 + 1 - 1000);
}

int numeroCompteExiste(int numeroCompte, Customer clients[], int nbClients)
{
    // Vérification de l'existence du numéro de compte dans les fichiers clients
    for (int i = 0; i < nbClients; i++)
        if (clients[i].reference == numeroCompte)
        {
            return 1;
        }
    return 0;
}

void accountRegister(Customer clients[], int *nbClients)
{
    int numeroCompte = 0;
    if (*nbClients == MAX_CLIENTS)
    {
        printf("Le nombre maximum de clients est atteint.\n");
        return;
    }

    // Saisie des informations du nouveau client
    Customer nouveauClient;
    printf("Entrez votre nom: ");
    scanf("%s", nouveauClient.firstName);
    printf("Entrez votre prénom: ");
    scanf("%s", nouveauClient.name);

    // Génération aléatoire du numéro de compte
    do
    {
        numeroCompte = genererNumeroCompte();
    } while (numeroCompteExiste(numeroCompte, clients, *nbClients));
    nouveauClient.reference = numeroCompte;

    // Ajout du nouveau client à la liste des clients
    clients[*nbClients] = nouveauClient;
    *nbClients++;

    // Enregistrement du nouveau client dans un fichier
    char fileName[20];
    sprintf(fileName, "%d.dat", numeroCompte);

    char *folderPath = "clientFolder/";
    char *filePath = malloc(strlen(folderPath) + strlen(fileName) + 1);

    // Construit le chemin complet du file
    strcpy(filePath, folderPath);
    strcat(filePath, fileName);

    FILE *file = fopen(filePath, "wb");
    if (file == NULL)
    {
        printf("Erreur lors de l'enregistrement du nouveau client.\n");
        return;
    }
    fwrite(&nouveauClient, sizeof(Customer), 1, file);
    fclose(file);

    printf("Votre compte a été créé avec succès.\n");
    printf("Voici votre numéro de compte: %d\n", numeroCompte);
    printf("\n");
}

void accountAcces(Customer clients[], int nbClients)
{
    int numeroCompte = 0;

    printf("Entrez votre numéro de compte: ");
    scanf("%d", &numeroCompte);
    printf("\n");

    // Recherche du client correspondant au numéro de compte
    int i;
    for (i = 0; i < nbClients; i++)
    {
        if (clients[i].reference == numeroCompte)
        {
            printf("Bonjour %s %s.\n", clients[i].name, clients[i].firstName);
            printf("Historique des achats:\n");
            break;
        }
    }

    if (i == nbClients)
    {
        printf("Numéro de compte invalide.\n");
    }
    printf("\n");
}

void deleteFile(int numeroCompte){
        char fileName[20];
        sprintf(fileName, "%d.dat", numeroCompte);

        char *folderPath = "clientFolder/";
        char *filePath = malloc(strlen(folderPath) + strlen(fileName) + 1);

        // Construit le chemin complet du file
        strcpy(filePath, folderPath);
        strcat(filePath, fileName);
        if (remove(filePath) == 0)
        {
            printf("Votre compte %d a été supprimé avec succès.\n", numeroCompte);
        }
        else
        {
            perror("Erreur lors de la suppression du fichier");
        }
    }
}

void deleteAccount(Customer clients[], int nbClients)
{
    int numeroCompte = 0;

    printf("Entrez votre numéro de compte: ");
    scanf("%d", &numeroCompte);
    printf("\n");

    if (numeroCompteExiste(numeroCompte, clients, nbClients))
    {
        int choix = 0;
        do
        {
            printf("Voulez vous supprimer votre compte\n");
            printf("1. Valider\n");
            printf("2. Annuler\n");
            
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            printf("\n");
            switch (choix)
            {
            case 1: // S'identifier
                deleteFile(numeroCompte);
                break;

            case 2: // Créer un nouveau compte
                printf("Annulation ...\n");
                break;

            }
        } while (choix != 2);
        
    printf("Votre numero de compte n'existe pas.\n");
}
/*   delocaliser les fonctions pour les appeles
  faire fonction pour supprimer compte en fonction de mdp
  faire recupperation de mot de passe suivant une question que l'on choisi
*/

int main()
{
    // Chargement des clients à partir des fichiers
    Customer clients[MAX_CLIENTS];
    int nbClients = 0;

    DIR *dossier;
    struct dirent *entree;
    dossier = opendir("clientFolder");
    if (dossier == NULL)
    {
        printf("Erreur lors de l'ouverture du dossier des clients.\n");
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

        // Construit le chemin complet du file
        strcpy(fileName, entree->d_name);
        strcpy(filePath, folderPath);
        strcat(filePath, fileName);

        FILE *file = fopen(filePath, "rb");
        if (file == NULL)
        {
            printf("Erreur lors de l'ouverture du file %s.\n", fileName);
            continue;
        }

        fread(&clients[nbClients], sizeof(Customer), 1, file);
        fclose(file);

        nbClients++;
    }
    closedir(dossier);

    // Menu principal
    int choix;
    do
    {
        printf("MENU PRINCIPAL\n");
        printf("1. S'identifier\n");
        printf("2. Créer un nouveau compte\n");
        printf("3. Supprimer un compte\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        printf("\n");
        switch (choix)
        {
        case 1: // S'identifier
            accountAcces(clients, nbClients);
            break;

        case 2: // Créer un nouveau compte
            accountRegister(clients, &nbClients);
            break;

        case 3:
            deleteAccount(clients, nbClients);
            break;

        case 4: // Quitter
            printf("Au revoir!\n");
            break;

        default:
            printf("Choix invalide.\n");
            printf("\n");
            break;
        }
    } while (choix != 4);

    return 0;
}
