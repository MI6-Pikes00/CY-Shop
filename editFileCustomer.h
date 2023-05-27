#ifndef HEADER_EDITFILECUSTOMER
#define HEADER_EDITFILECUSTOMER 1
#include "structFile.h"

void loadCustomer(Customer clients[MAX_CLIENTS], int *nbClients);
int genereraccountNumber();
int accountNumberAttributed(int accountNumber, Customer clients[], int nbClients);
void accountRegister(Customer clients[], int *nbClients);
void deleteFile(int accountNumber);
void deleteAccount(Customer clients[], int nbClients);
int accountAcces(Customer clients[], int nbClients);
void saveClient(Customer client[], int i);
void copyIntArray(const int source[], int destination[], int length);
#endif