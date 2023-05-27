#ifndef HEADER_EDITFILEPRODUCT
#define HEADER_EDITFILEPRODUCT 1
#include "structFile.h"

int placeAvailabe(Product products[], int nb_products);
void stockVerification(Product products[], int nb_products);
int checkReference(Product products[], int nb_products, int ref);
void addProduct(Product products[], int *nb_products);
void displayProduct(Product products[], int nb_products);
void quickSort(Product tab[], int start, int end);
void saveProduct(Product products[], int nb_products, const char *fileName);
void loadProduct(Product products[], int *nb_products, const char *fileName);
void modifiesQuantity(Product products[], int nb_products, int ref, int q);
#endif