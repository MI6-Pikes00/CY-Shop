#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "editFileProduct.c"

int placeAvailabe(Product products[], int nb_products)
{
    int s = 0;
    for (int j = 0; j < nb_products; j++)
    {
        s += products[j].quantity * products[j].place;
    }
    return s;
}

void stockVerification(Product products[], int nb_products)
{
    printf("Stock place available : %d \n", SHOP - placeAvailabe(products, nb_products));

    printf("Product out of stock :\n");
    for (int i = 0; i < nb_products; i++)
    {
        if (products[i].quantity == 0)
        {
            printf("\tName : %s, ", products[i].name);
            printf("\tReference : %d\n", products[i].reference);
        }
    }
}

// Function to test that the above functions work well during development.

int main()
{

    // Creation of product tab to simulate reality

    Product products[SIZE];
    int nb_products = 0;

    loadProduct(products, &nb_products, "products.txt");

    stockVerification(products, nb_products);

    return 0;
}
