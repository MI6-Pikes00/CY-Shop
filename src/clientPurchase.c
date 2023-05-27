#include "clientPurchase.h"
#include "editFileCustomer.h"
#include "editFileProduct.h"
#include "search.h"
#include <stdio.h>
#include <string.h>

// Purchase mode
void purchase(Customer clients[], int nbClients, int i)
{
    Product products[SIZE_SHOP];
    int nb_products = 0;

    // Loading of products in stock
    loadProduct(products, &nb_products, "products.txt");

    Panier panier[SIZE_CARD];

    // Setup variables
    int nbItem = 0;
    int choix;
    int ipanier = 0;
    int ihistorique = -1;
    int c;
    int choixpouraddaupanier;
    int q;
    int in_buying_mode = 0;
    float ptotal = 0;

    do
    {
        // Printing Purchase Menu
        printf("\n");
        printf("Purchase Menu\n");
        printf("-------------- \n");
        printf("1. Purchase history\n");
        printf("2. Cart (%d)\n", nbItem);
        printf("3. See Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix)
        {
        case 1: // Print purchase history
            clearConsole();

            if (clients[i].nbPurchase != 0)
            {
                printf("Purchase history:\n");
                for (int j = 0; j < clients[i].nbPurchase; j++)
                {
                    printf("%d ", clients[i].purchase[j]);
                }
            }
            else
            {
                printf("\nNo previous order.\n");
            }

            break;

        case 2: // Access to the cart
            clearConsole();
            in_buying_mode = 1;
            while (in_buying_mode)
            {
                if (nbItem == 0)
                {
                    printf("Your cart is empty.\n");
                }
                else
                {
                    // Print the cart
                    for (int i = 0; i < nbItem; i++)
                    {
                        printf("\nProduct Name: %s", panier[i].name);
                        printf("\nQuantity: %d ", panier[i].quantity);
                        printf("\nPrice: %.2f$\n", panier[i].price);
                        ptotal += panier[i].price;
                    }
                    printf("\nTotal: %.2f$\n", ptotal);
                    clients[i].sold -= ptotal;

                    printf("\n");
                    printf("1. Buy\n");
                    printf("2. Exit\n");
                    printf("Enter your choice: ");
                    int valid = scanf("%d", &choix);
                    if (valid != 1)
                    {
                        while (getchar() != '\n')
                        {
                            // clean the entrances
                        }
                    }
                    printf("\n");

                    switch (choix)
                    {
                    case 1: // Valid option
                        clients[i].sold -= ptotal;
                        if (clients[i].sold >= ptotal)
                        {
                            printf("Validate process ...\n");
                            printf("THANKS FOR YOUR ORDER\n");
                            // Adding product to the order history of an account

                            for (ipanier = 0; ipanier < nbItem; ipanier++)
                            {
                                strcpy(&clients[i].purchase[ipanier], panier[ipanier].name);
                                clients[i].nbPurchase += 1;
                                saveClient(clients, i);

                                /* Rezise stock after order */

                                modifiesQuantity(products, nb_products, panier[ipanier].reference, -panier[ipanier].quantity);
                            }

                            saveProduct(products, nb_products, "products.txt");

                            // Empty the cart
                            memset(panier, 0, SIZE_CARD);
                            nbItem = 0;
                            in_buying_mode = 0;
                        }
                        else
                        {
                            printf("Insufficient sold!");
                            printf("\nSold: %.2f$", clients[i].sold);
                        }

                        break;

                    case 2: // Exit option
                        printf("Return\n");
                        clearConsole();
                        break;

                    default:
                        printf("Invalid choice.\n");
                        break;
                    }
                }
            };
            break;

        case 3: // Menu to search object to buy
            clearConsole();
            for (int i = 0; i < nb_products; i++)
            {
                if (products[i].quantity > 0)
                {
                    printf("Name : %-10s\t", products[i].name);
                    printf("Reference : %4d\t", products[i].reference);
                    printf("Quantity : %2d\n", products[i].quantity);
                }
            }

            do
            {
                // Add to cart
                printf("\n");
                printf("1. Add to cart\n");
                printf("2. Search by Name/Ref\n"); // have to have case search
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choix);
                printf("\n");

                switch (choix)
                {
                case 1: // Add to cart
                    printf("Enter the reference: ");
                    scanf("%d", &choixpouraddaupanier);

                    printf("Enter the quantity you want: ");
                    scanf("%d", &q);

                    // Method to add product to cart
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
                                printf("\nAdded succesfully to cart\n");
                            }
                            else
                            {
                                printf("Saisir une quantité plus base pas assez de stocks \n");
                            }
                        }
                    }
                    break;

                case 2:
                    searchProduct(products, nb_products);
                    break;

                case 3: // Exit
                    printf("Returning in connection.");
                    clearConsole();
                    break;

                default:
                    printf("Invalid choice.\n");
                    printf("\n");
                    break;
                }
            } while (choix != 3);
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
