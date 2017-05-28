//
// Created by Marcos khabie on 26/5/17.
//

#ifndef EJERCICIO2_MARKET_H
#define EJERCICIO2_MARKET_H

#include "Product.h"
#include "Factory.h"
#include "Provider.h"

typedef struct market{

    Product** products;
    int amountOfProducts;
    int maxCapacityOfProducts;

    Provider** providers;
    int amountOfProviders;
    int maxCapacityOfProviders;

    Factory** factories;
    int amountOfFactories;
    int maxCapacityOfFactories;

}Market;

Market* createMarket(int initialCapacityOfArrays);
void destroyMarket(Market* market);

Product* getProduct(Market* market,int code);

void addNewProduct(Market* market, Product* product);
void addNewProvider(Market* market, Provider* provider);
void addNewFactory(Market* market, Factory* factory);

void printMarket(Market* market);
void printProducts(Market* market);

#endif //EJERCICIO2_MARKET_H
