//
// Created by Marcos khabie on 26/5/17.
//

#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "RegisteredUser.h"
RegisteredUser* createUser(  char* name, int dni, int direction, int tel, char* province, char* country, int zipCode, int type){

    RegisteredUser* newRegisteredUser = malloc(sizeof(RegisteredUser));

    newRegisteredUser->name= malloc(sizeof(char)* strlen(name));
    newRegisteredUser->country= malloc(sizeof(char)* strlen(country));
    newRegisteredUser->province= malloc(sizeof(char)* strlen(province));

    strcpy(newRegisteredUser->name,name);
    strcpy(newRegisteredUser->country,country);
    strcpy(newRegisteredUser->province,province);

    newRegisteredUser->dni= dni;
    newRegisteredUser->direction=direction;
    newRegisteredUser->tel=tel;
    newRegisteredUser->zipCode=zipCode;
    newRegisteredUser->type=type;

    return newRegisteredUser;
}

void addProduct(RegisteredUser* registeredUser,Market* market,Product* product){
    if (registeredUser->type==1){
        if(market->amountOfProducts==market->maxCapacityOfProducts) {
            market->products = realloc(market->products, sizeof(Product *) * market->maxCapacityOfProducts * 2);
            market->maxCapacityOfProducts = market->maxCapacityOfProducts * 2;
        }
        market->products[market->amountOfProducts]=product;
        market->amountOfProducts++;
        }
    else{
        printf("you are not an admin");
    }
}
void addProvider(RegisteredUser* registeredUser,Market* market, Provider* provider){
    if (registeredUser->type==1){
        if(market->amountOfProviders==market->maxCapacityOfProviders) {
            market->providers = realloc(market->providers, sizeof(Provider *) * market->maxCapacityOfProviders * 2);
            market->maxCapacityOfProviders = market->maxCapacityOfProviders * 2;
        }
        market->providers[market->amountOfProviders]=provider;
        market->amountOfProviders++;
    }
    else{
        printf("you are not an admin");
    }
}
void addFactory(RegisteredUser* registeredUser,Market* market, Factory* factory){
    if (registeredUser->type==1){
        if(market->amountOfFactories==market->maxCapacityOfFactories) {
            market->factories = realloc(market->factories, sizeof(Factory *) * market->maxCapacityOfFactories * 2);
            market->maxCapacityOfFactories = market->maxCapacityOfFactories * 2;
        }
        market->factories[market->amountOfProducts]=factory;
        market->amountOfFactories++;
    }
    else{
        printf("you are not an admin");
    }
}


void freeUser(RegisteredUser* registeredUser){
    free(registeredUser->name);
    free(registeredUser->country);
    free(registeredUser->province);
    free(registeredUser);
}
