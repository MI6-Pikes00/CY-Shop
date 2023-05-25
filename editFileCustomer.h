#ifndef HEADER_EDITFILECUSTOMER
#define HEADER_EDITFILECUSTOMER 1
#include "structFile.h"

void loadCustomer(Customer clients[], int nbClients);
int genereraccountNumber();
int accountNumberAttributed(int accountNumber, Customer clients[], int nbClients);
void accountRegister(Customer clients[], int *nbClients);
void deleteFile(int accountNumber);
void deleteAccount(Customer clients[], int nbClients);
int accountAcces(Customer clients[], int nbClients);
#endif