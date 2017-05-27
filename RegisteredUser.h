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
    int direction;
    int tel;
    char* province;
    char* country;
    int zipCode;
    int type ;// 0 client 1 admin


}RegisteredUser;

RegisteredUser* createUser(  char* name, int dni, int direction, int tel, char* province, char* country, int zipCode, int type);

void addProduct(RegisteredUser* registeredUser,Market* market,Product* product);
void addProvider(RegisteredUser* registeredUser,Market* market, Provider* provider);
void addFactory(RegisteredUser* registeredUser,Market* market, Factory* factory);

void freeUser(RegisteredUser* registeredUser);


#endif //EJERCICIO2_REGISTEREDUSER_H
