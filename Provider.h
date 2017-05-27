//
// Created by Marcos khabie on 26/5/17.
//

#ifndef EJERCICIO2_PROVIDER_H
#define EJERCICIO2_PROVIDER_H

#include "Product.h"


typedef struct provider{

    char* name;

    int direction;
    int tel;
    int locality;
    char* province;
    char* country;
    char* zipCode;
    Product** productsToProvide;


}Provider;

Provider* createProvider(    int direction,int tel, int locality, char* province, char* country,char* zipCode, Product** productsToProvide);

void freeProvider(Provider* provider);

#endif //EJERCICIO2_PROVIDER_H
