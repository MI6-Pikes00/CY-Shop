#include "editFileProduct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if there is place available.

int placeAvailabe(Product products[], int nb_products)
{
    int s = 0;

    // Loop to calculate the number of place the stock take.

    for (int j = 0; j < nb_products; j++)
    {
        s += products[j].quantity * products[j].place;
    }
    return s;
}

// Function to check if there is no unavailable product and print it to the worker.

void stockVerification(Product products[], int nb_products)
{
    printf("Stock place available : %d \n", SHOP - placeAvailabe(products, nb_products));

    printf("\n");

    // Loop for check if quantity of product is 0, if it is, we print it.
    int c = 0;
    printf("Product out of stock :\n");
    for (int i = 0; i < nb_products; i++)
    {
        if (products[i].quantity == 0)
        {
            printf("\tName : %s, ", products[i].name);
            printf("\tReference : %d\n", products[i].reference);
            c++;
        }
    }

    // Loop to display 5 first product with the lowest stock after out of stock products.
    printf("Product with low stock :\n");
    for (int j = c; j < c + 5; j++)
    {
        printf("\tName : %s, ", products[j].name);
        printf("\tReference : %d\n", products[j].reference);
    }
}

// Function to check if reference is already attributed to a product.

int checkReference(Product products[], int nb_products, int ref)
{
    // Loop to find the product if reference is allready donated.

    printf("verification !\n");

    for (int i = 0; i < nb_products; i++)
    {
        if (products[i].reference == ref)
        {

            // Return 0 if the reference is already asigned so he chose another.
            return 0;
        }

        // Return 1 if the reference is new.
        return 1;
    }
    return 1;
}

// Function to add product to the stock.

void addProduct(Product products[], int *nb_products) // We put *nb_products, because we are modifying the value at the end
{
    // Condition to check if there is place available.
    if (SHOP - placeAvailabe(products, *nb_products) > 0)
    {
        int b = 1;

        printf("Put the name : ");
        scanf("%s", products[*nb_products].name);

        printf("Put the quantity : ");
        scanf("%d", &products[*nb_products].quantity);

        // Loop to check if the recovery of input is correct
        do
        {
            int p = 0;
            printf("Put the size (1 = SMALL, 2 = MEDIUM, 3 = LARGE): ");
            scanf("%d", &p);
            if (SHOP - (placeAvailabe(products, *nb_products) + (products[*nb_products].quantity * p)) > 0)
            {
                // Case who attribute good variable to input
                switch (p)
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
            }
            // Basic case, return an error if there is no place
            else
            {
                printf("There is no more space, the object %s is to big", products[*nb_products].name);
                return;
            }
        } while (b);

        printf("Size is defined ! \n");

        b = 1;

        // Loop to not asign twice the same reference use function check reference

        do
        {
            int ref = rand() % (9999 + 1 - 1000); // If more item, increase the 9999
            if (checkReference(products, *nb_products, ref))
            {
                products[*nb_products].reference = ref;
                printf("The reference assigned is %d \n", ref);
                b = 0;
            }
        } while (b);

        (*nb_products)++;
    }

    else
    {
        printf("No more space\n");
    }
}

// Function to display all products.

void displayProduct(Product products[], int nb_products)
{
    // Loop to print all product list with their information
    for (int i = 0; i < nb_products; i++)
    {
        printf("Product %d :\n", i + 1);
        printf("\tName : %s\n", products[i].name);
        printf("\tReference : %d\n", products[i].reference);
        printf("\tQuantity : %d\n", products[i].quantity);
        printf("\tSize : %s\n", products[i].size);
        printf("\tPlace: %d\n", products[i].place);
    }
}

// Function that allows to write to the text file where the data are stored.

void saveProduct(Product products[], int nb_products, const char *fileName)
{
    // Open the file in writing mode.
    FILE *file = fopen(fileName, "w");
    // Condition so the function printf error if the file is not found.
    if (file == NULL)
    {
        printf("Error : unable to open the file %s\n", fileName);
        return;
    }
    // Loop who print all information in the file. (Rewrite all)
    for (int i = 0; i < nb_products; i++)
    {
        fprintf(file, "%s %d %d %s %d \n", products[i].name, products[i].reference, products[i].quantity, products[i].size, products[i].place);
    }

    // Close the file after the ending
    fclose(file);
}

// Function that allows you to load the customer file and then make changes to it.

void loadProduct(Product products[], int *nb_products, const char *fileName)
{
    FILE *file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Error : unable to open the file %s \n", fileName);
        return;
    }
    // Loop who scan the file data.
    while (!feof(file))
    {
        fscanf(file, "%s %d %d %s %d\n", products[*nb_products].name, &products[*nb_products].reference, &products[*nb_products].quantity, products[*nb_products].size, &products[*nb_products].place);
        (*nb_products)++;
    }

    fclose(file);
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
            int q = 0;
            printf("Put new quantity to add : ");
            scanf("%d", &q);
            // Condition verify if plave available.
            if (SHOP - (placeAvailabe(products, nb_products) + (products[i].place * (products[i].quantity + q))) >= 0)
            {
                products[i].quantity += q;
                printf("Quantity successfully modified.\n");
            }
            else
            {
                printf("No more place available !\n");
                printf("You just have %d place left.\n", SHOP - (placeAvailabe(products, nb_products)));
            }
            return;
        }
    }
    // Error case if the user put another value like text or unkonow reference.
    printf("Error : product not find.\n");
}

// Function to sort by quantity product.

void quickSort(Product tab[], int start, int end)
{
    if (start < end)
    {
        int pivot = tab[start].quantity;
        int i = start + 1;
        int j = end;

        while (i <= j)
        {
            while (i <= j && tab[i].quantity <= pivot)
            {
                i++;
            }
            while (i <= j && tab[j].quantity > pivot)
            {
                j--;
            }
            if (i < j)
            {
                Product temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }

        Product temp = tab[start];
        tab[start] = tab[j];
        tab[j] = temp;

        quickSort(tab, start, j - 1);
        quickSort(tab, j + 1, end);
    }
}

// Function to test that the above functions work well during development.

/* int main()
{

    // Creation of product tab to simulate reality

    Product products[100];
    int nb_products = 0;

    loadProduct(products, &nb_products, "products.txt");

    // Quick menu to test the different functions

    while (1)
    {

        quickSort(products, 0, nb_products - 1);
        saveProduct(products, nb_products, "products.txt");

        printf("\n");
        stockVerification(products, nb_products);
        printf("\n");
        printf("1. Display products list\n");
        printf("2. Add new product\n");
        printf("3. Modifies product quantity\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Products list:\n");
            displayProduct(products, nb_products);
            break;
        case 2:
            addProduct(products, &nb_products);
            quickSort(products, 0, nb_products - 1);
            saveProduct(products, nb_products, "products.txt");
            break;
        case 3:
            modifiesQuantity(products, nb_products);
            saveProduct(products, nb_products, "products.txt");
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