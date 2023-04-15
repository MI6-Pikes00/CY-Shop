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
        strncpy(p->size, "SMALL", sizeof(p->size)); // Voir ce que fait fct strncpy
        break;

     case 2:
        strncpy(p->size, "MEDIUM", sizeof(p->size));
        break;

     case 3:
        strncpy(p->size, "LARGE", sizeof(p->size));
        break;

    default:
        strncpy(p->size, "NONE", sizeof(p->size));
        break;
    }
    return p;
}

Customer * registerCustomer(){
    Customer * c = malloc(sizeof(Customer));

    printf("Enter customer name: ");
    scanf("%s", c->name);
    printf("Enter customer first name: ");
    scanf("%s", c->firstName);

    return c;
}

void printCustomer(Customer c){
    printf("First name: %s\n", c.firstName);
    printf("Name: %s\n", c.name);

}

int main(int argc, char const *argv[])
{
    /* 
    Product productArray[10];

    for(int i = 0; i<10; i++){
        productArray[i] = registerProduct();
    } 
    */

    Customer customer;
    customer = *registerCustomer();
    printCustomer(customer);




    return 0;
}
