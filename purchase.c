#include "editFileCustomer"
#include "editFileProduct"
#include "structFile.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define P 1000

/*
- Il faut reucpper le clients connecter + liste du stock dans un main menu:
    -recherche produit par nom / reference
    -Panier sous forme de liste reference + prix (Ne pas oublier de faire le total du prix)=
        -S'initialise a chaque connection
        -propose d'utiliser les point de fideliter
        -mode de validation de panier

    -Historique d'achat
    -Indication si le produit n'est plus en stock "Unavailable"
    -Point de fidéliter a partir d'un certains montant ou suivant le produit (pas obligatoire)
    -Categorie de piece de voiture ce baser sur les site de casse
*/

int main(Customer clients[], int i)
{
    printf("Hello %s %s.\n", clients[i].name, clients[i].firstName);
    Panier panier[P];
    int nbItem = 0;
    int choix;

    do
    {
        printf("MENU\n");
        printf("1. Purchase history\n");
        printf("2. Recherche article\n");
        printf("Panier (%d)\n", nbItem);
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix)
        {
        case 1: // Print purchase history
            printf("Purchase history:\n");
            for (int j = 0; j < clients[i].nbPurchase; j++)
            {
                printf("%d", clients[i].purchase[j]);
            }
            break;

        case 2: // Access to the card
            int c;
            do
            {
                float ptotal = 0;
                for (int i = 0; i < nbItem; i++)
                {
                    printf("%s ", panier[i].name);
                    printf("%d ", panier[i].quantity);
                    printf("%f\n", panier[i].price);
                    ptotal += panier[i].price;
                }
                printf("Total %d", ptotal);
            } while (c != 4);
            break;

        case 3: // Menu to search object to buy
            Product products[100];
            int nb_products = 0;
            loadProduct(products, &nb_products, "products.txt");
            displayProduct(products, nb_products);
            do
            {
                printf("MENU\n");
                printf("1. Purchase history\n");
                printf("2. Recherche article\n");
                printf("Panier (%d)\n", nbItem);
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choix);
                printf("\n");

                switch (choix)
                {
                case 1:
                    break;

                case 4: // Exit
                    printf("Déconection");
                    break;

                default:
                    printf("Invalid choice.\n");
                    printf("\n");
                    break;
                }
            } while (choix != 4);
            break;

        case 4: // Exit
            printf("Déconection");
            break;

        default:
            printf("Invalid choice.\n");
            printf("\n");
            break;
        }
    } while (choix != 4);
    return 0;
}
