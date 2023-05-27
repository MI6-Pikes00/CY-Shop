#include "clientPurchase.h"
#include "editFileProduct.h"
#include <stdio.h>
#include <string.h>

void purchase(Customer clients[], int nbClients, int i)
{
    // 

    Product products[SIZE_SHOP];
    int nb_products = 0;
    
    loadProduct(products, &nb_products, "products.txt");

    printf("Hello %s %s.\n", clients[i].name, clients[i].firstName);
    Panier panier[SIZE_CARD];

    int nbItem = 0;
    int choix;
    int ipanier = 0;
    int ihistorique = -1;
    int c;
    int choixpouraddaupanier;
    int q;

    do
    {
        // Printing Stock Management Menu
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
            if (clients[i].nbPurchase != -1)
            {
                for (int j = 0; j < clients[i].nbPurchase; j++)
                {
                    printf("%d", clients[i].purchase[j]);
                }
            }
            printf("Vous n'avez pas encore fait d'achat sur notre site web.\n");
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
                    printf("Validate process ...\n");
                    printf("THANKS FOR YOUR ORDER\n");

                    // Adding product to the order history of an account
                    for (ipanier; ipanier < nbItem; ipanier++)
                    {
                        printf("boucle 1"); // Just to test
                        if (clients[i].nbPurchase == -1)
                        {

                            for (ihistorique; ihistorique <= clients[i].nbPurchase; ihistorique++)
                            {
                                clients[i].purchase[ihistorique] = panier[ipanier].reference;
                                clients[i].nbPurchase += 1;
                            }
                        }
                        for (ihistorique; ihistorique <= clients[i].nbPurchase; ihistorique++)
                            if (panier[ipanier].reference != clients[i].purchase[ihistorique])
                            {
                                clients[i].purchase[ihistorique] = panier[ipanier].reference;
                                clients[i].nbPurchase += 1;
                            }
                    }

                        /* Rezise stock about order */

                    saveProduct(products, nb_products, "products.txt");

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
                // Add to card 
                printf("\n");
                printf("1. Add to card\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choix);
                printf("\n");

                switch (choix)
                {
                case 1:
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
