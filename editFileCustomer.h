#ifndef HEADER_EDITFILECUSTOMER
#define HEADER_EDITFILECUSTOMER 1
#include "structFile.h"

void loadCustomer(Customer clients[MAX_CLIENTS], int *nbClients);
int genereraccountNumber();
int accountNumberAttributed(int accountNumber, Customer clients[], int nbClients);
void accountRegister(Customer clients[], int *nbClients);
void deleteFile(int accountNumber);
void deleteAccount(Customer clients[], int nbClients, int i);
int accountAcces(Customer clients[], int nbClients);
void saveClient(Customer client[], int i);
void copyIntArray(const char source[], char destination[], int length);
#endif