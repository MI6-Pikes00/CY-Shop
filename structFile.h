#ifndef HEADER_STRUCTFILE
#define HEADER_STRUCTFILE 1

#define SIZE 100
#define SIZE_SHOP 1000
#define MAX_CLIENTS 1000 
#define SIZE_CARD 1000           

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
    char password[SIZE];
    char purchase[SIZE];
    int nbPurchase;
    int reference;
} Customer;

typedef struct
{
    char name[SIZE];
    int reference;
    float price;
    int quantity;
} Panier;

void clearConsole();
#endif