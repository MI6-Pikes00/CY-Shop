#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
//Entreprise de voiture,
//Gerer les stocks de pieces
//Gerer stock  de voitures 

//Defition of the product structure 
typedef struct {
    char name[SIZE];
    int referance;
    int quantity;
    char size[SIZE];
} Product;

//Defition of the customer structure 
typedef struct 
{
    char name[SIZE];
    char firstName[SIZE];
    int purchase[SIZE];
} Customer;

//Fonction to fill product structure
Product * registerProduct(){
    Product * p = malloc(sizeof(Product));
    int i = 0;
    printf("Put the name of the product: ");
    scanf("%s", p->name);
    printf("Put the reference of the product: ");
    scanf("%d", &p->referance);
    printf("Put number of quat of the product: ");
    scanf("%d", &p->quantity);
    printf("Put size, 1 = SMALL, 2 = MEDIUM, 3 = LARGE");
    scanf("%d", &i);

    switch (i){
    case 1:
        p->size = append("SMALL");
        break;

     case 2:
        p->size = "MEDIUM";
        break;

     case 3:
        p->size = "LARGE";
        break;

    default:
        p->size, "NONE";
        break;
    }
    return p;
}

Customer * registerCustomer(){
    Customer * c = malloc(sizeof(Customer));

    printf("Put the name of the product: ");
    scanf("%s", c->name);
    printf("Put the name of the product: ");
    scanf("%s", c->firstName);

    return c;
}

int main(int argc, char const *argv[])
{
    Product p = registerProduct();
    return 0;
}
