//
// Created by Marcos khabie on 26/5/17.
//

#include <stringlist.h>
#include "Sale.h"
#include "Market.h"

#ifndef EJERCICIO2_REGISTEREDUSER_H
#define EJERCICIO2_REGISTEREDUSER_H


typedef struct registeredUser{

    char* name;
    int dni;
    char* direction;
    int tel;
    char* province;
    char* country;
    int zipCode;
    int type ;// 0 client 1 admin

    Sale** sales;
    int amountOfSales;
    int maxAmountOfSales;

}RegisteredUser;

RegisteredUser* createUser(  char* name, int dni, char* direction, int tel, char* province, char* country, int zipCode, int type);

void adminAddsProduct(RegisteredUser* registeredUser,Market* market,Product* product);
void adminAddsProvider(RegisteredUser* registeredUser,Market* market, Provider* provider);
void adminAddsFactory(RegisteredUser* registeredUser,Market* market, Factory* factory);

void addNewSale(RegisteredUser* user, Sale* newSale);
void addNewSaleLineToSale(RegisteredUser* user, int saleCode, SaleLine* newSaleLine);

void printUser(RegisteredUser* user);
void printSalesOfUser(RegisteredUser* user);

Sale* findSale(RegisteredUser* user, int saleCode);
void freeUser(RegisteredUser* registeredUser);


#endif //EJERCICIO2_REGISTEREDUSER_H
