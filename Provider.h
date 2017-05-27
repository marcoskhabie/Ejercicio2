//
// Created by Marcos khabie on 26/5/17.
//

#ifndef EJERCICIO2_PROVIDER_H
#define EJERCICIO2_PROVIDER_H

#include "Product.h"


typedef struct provider{

    char* name;

    char* direction;
    int tel;
    char* province;
    char* country;
    char* locality;
    int zipCode;



}Provider;

Provider* createProvider(  char* name, char*  direction,int tel, char* locality, char* province, char* country,int zipCode);
void printProvider(Provider* provider);
void freeProvider(Provider* provider);

#endif //EJERCICIO2_PROVIDER_H
