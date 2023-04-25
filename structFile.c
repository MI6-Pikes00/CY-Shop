#include <stdio.h>
#define SIZE 100
#define SHOP 1000

// Defition of the product structure
typedef struct
{
    char name[SIZE];
    int reference;
    float price;
    int quantity;
    char size[SIZE];
    int place;
} Product;

// Defition of the customer structure
typedef struct
{
    char name[SIZE];
    char firstName[SIZE];
    int nbPurchase;
    int purchase[SIZE];
} Customer;