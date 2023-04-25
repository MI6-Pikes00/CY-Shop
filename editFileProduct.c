#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structFile.c"

// Function to add product to the stock.

int checkReference(Product products[], int nb_products, int ref)
{
    // loop to find the product if reference is allready donated

    printf("verification !\n");

    for (int i = 0; i < nb_products; i++)
    {
        if (products[i].reference == ref)
        {
            return 0;
        }
        return 1;
    }
    return 11;
}

void addProduct(Product products[], int *nb_products)
{
    srand(time(NULL));
    int b = 1;

    printf("Put the name : ");
    scanf("%s", products[*nb_products].name);

    printf("Put the quantity : ");
    scanf("%d", &products[*nb_products].quantity);

    do
    {
        int s = 0;
        printf("Put the size (1 = SMALL, 2 = MEDIUM, 3 = LARGE): ");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            strcat(products[*nb_products].size, "SMALL");
            products[*nb_products].place = 1;
            b = 0;
            break;
        case 2:
            strcat(products[*nb_products].size, "MEDIUM");
            products[*nb_products].place = 2;
            b = 0;
            break;
        case 3:
            strcat(products[*nb_products].size, "LARGE");
            products[*nb_products].place = 4;
            b = 0;
            break;
        default:
            printf("Error value is not correct ! \n");
            break;
        }
    } while (b);

    printf("Size is defined ! \n");

    b = 1;

    // Loop to not asign twice the same reference use function check reference

    do
    {
        int ref = rand() % (9999 + 1 - 1000);
        if (checkReference(products, *nb_products, ref))
        {
            products[*nb_products].reference = ref;
            printf("The reference assigned is %d \n", ref);
            b = 0;
        }
    } while (b);

    (*nb_products)++;
}

// Function to display all products.

void displayProduct(Product products[], int nb_products)
{
    for (int i = 0; i < nb_products; i++)
    {
        printf("Product %d :\n", i + 1);
        printf("\tName : %s\n", products[i].name);
        printf("\tReference : %d\n", products[i].reference);
        printf("\tQuantity : %d\n", products[i].quantity);
        printf("\tSize : %s\n", products[i].size);
        printf("\tPlace : %d\n", products[i].place);
    }
}

// Function that allows to write to the text file where the data are stored.

void saveProduct(Product products[], int nb_products, const char *fileName)
{
    FILE *fichier = fopen(fileName, "w");

    if (fichier == NULL)
    {
        printf("Error : unable to open the file %s\n", fileName);
        return;
    }

    for (int i = 0; i < nb_products; i++)
    {
        fprintf(fichier, "%s %d %d %s %d\n", products[i].name, products[i].reference, products[i].quantity, products[i].size, products[i].place);
    }

    fclose(fichier);
}

// Function that allows you to load the customer file and then make changes to it.

void loadProduct(Product products[], int *nb_products, const char *fileName)
{
    FILE *fichier = fopen(fileName, "r");

    if (fichier == NULL)
    {
        printf("Error : unable to open the file%s\n", fileName);
        return;
    }

    while (!feof(fichier))
    {
        fscanf(fichier, "%s %d %d %s %d\n", products[*nb_products].name, &products[*nb_products].reference, &products[*nb_products].quantity, products[*nb_products].size, &products[*nb_products].place);
        (*nb_products)++;
    }

    fclose(fichier);
}

// Fuction to modifies porduct quantity by there reference.

void modifiesQuantity(Product products[], int nb_products)
{
    int ref;
    printf("Enter the reference of the product whose quantity you want to change: ");
    scanf("%d", &ref);

    // loop to find the product associate with the reference
    for (int i = 0; i < nb_products; i++)
    {
        if (products[i].reference == ref)
        {
            printf("Current quantity : %d\n", products[i].quantity);
            printf("Put new quantity : ");
            scanf("%d", &products[i].quantity);
            printf("Quantity successfully modified.\n");
            return;
        }
    }
    // Error case if the user put another value like text or unkonow reference.
    printf("Error : product not find.\n");
}

// Function to test that the above functions work well during development.

/* int main() {

    //Creation of product tab to simulate reality

    Product products[100];
    int nb_products = 0;

    loadProduct(products, &nb_products, "products.txt");

    //Quick menu to test the different functions

    while (1) {
        printf("1. Display products list\n");
        printf("2. Add new product\n");
        printf("3. Modifies product quantity\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Products list:\n");
                displayProduct(products, nb_products);
                break;
            case 2:
                addProduct(products, &nb_products);
                saveProduct(products, nb_products, "products.txt");
                break;
            case 3:
                modifiesQuantity(products, nb_products);

                break;

            case 4:
                return 0;
                break;
            default:
                printf("Erreur : choice invalide\n");
        }
    }
}
 */