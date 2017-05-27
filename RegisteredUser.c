//
// Created by Marcos khabie on 26/5/17.
//

#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "RegisteredUser.h"
RegisteredUser* createUser(  char* name, int dni, char* direction, int tel, char* province, char* country, int zipCode, int type){

    RegisteredUser* newRegisteredUser = malloc(sizeof(RegisteredUser));

    newRegisteredUser->name= malloc(sizeof(char)* (strlen(name)+1));
    newRegisteredUser->country= malloc(sizeof(char)* (strlen(country)+1));
    newRegisteredUser->province= malloc(sizeof(char)* (strlen(province)+1));

    strcpy(newRegisteredUser->name,name);
    strcpy(newRegisteredUser->country,country);
    strcpy(newRegisteredUser->province,province);

    newRegisteredUser->dni= dni;
    newRegisteredUser->direction=direction;
    newRegisteredUser->tel=tel;
    newRegisteredUser->zipCode=zipCode;
    newRegisteredUser->type=type;

    newRegisteredUser->sales = malloc(sizeof(Sale*) * 10);
    newRegisteredUser->amountOfSales = 0;
    newRegisteredUser->maxAmountOfSales = 10;

    return newRegisteredUser;
}

void adminAddsProduct(RegisteredUser* registeredUser,Market* market,Product* product){
    if (registeredUser->type==1) {
        addNewProduct(market, product);
    }
    else{
        printf("you are not an admin");
    }
}
void adminAddsProvider(RegisteredUser* registeredUser,Market* market, Provider* provider){
    if (registeredUser->type==1){
        addNewProvider(market, provider);
    }
    else{
        printf("you are not an admin");
    }
}
void adminAddsFactory(RegisteredUser* registeredUser,Market* market, Factory* factory){
    if (registeredUser->type==1){
        addNewFactory(market, factory);
    }
    else{
        printf("you are not an admin");
    }
}

void addNewSale(RegisteredUser* user, Sale* newSale){
    if(user->type == 0) {
        if (user->amountOfSales == user->maxAmountOfSales) {
            user->sales = realloc(user->sales, sizeof(Sale *) * user->maxAmountOfSales * 2);
            user->maxAmountOfSales = user->maxAmountOfSales * 2;
        }
        user->sales[user->amountOfSales] = newSale;
        user->amountOfSales++;
    }
    else{
        printf("You are not a client.");
    }
}

void addNewSaleLineToSale(RegisteredUser* user, int saleCode, SaleLine* newSaleLine){
    if(user->type == 0) {
        Sale *sale = findSale(user, saleCode);
        addNewSaleLine(sale, newSaleLine);
    }
    else{
        printf("You are not a client.");
    }
}

void printUser(RegisteredUser* user){

    printf("Name: %s, ",user->name);
    printf("DNI: %d, ", user->dni);
    printf("Type of user: ");
    if(user->type == 1){
        printf("ADMIN");
    }
    else{
        printf("CLIENT");
    }
    printf("\n");
}


Sale* findSale(RegisteredUser* user, int saleCode){
    for (int i = 0; i < user->amountOfSales; ++i) {
        if(user->sales[i]->code == saleCode){
            return user->sales[i];
        }
    }
    return NULL;
}


void freeUser(RegisteredUser* registeredUser){
    free(registeredUser->name);
    free(registeredUser->country);
    free(registeredUser->province);
    free(registeredUser);
}
