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

Market* createMarket(Product** products, int amountOfProducts, int maxCapacityOfProducts);

//Factory* getProduct(int idFactory);
//Factory* getProvider(int idFactory);
//Factory* getFactory(int idFactory);



void freeMarket(Market* market);
#endif //EJERCICIO2_MARKET_H
