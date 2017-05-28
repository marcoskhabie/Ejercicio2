//
// Created by Marcos khabie on 26/5/17.
//

#include <stdlib.h>
#include <printf.h>
#include "Market.h"


Market* createMarket(int initialCapacityOfArrays){
    Market* newMarket = malloc(sizeof(Market));

    newMarket->amountOfFactories = 0;
    newMarket->amountOfProducts = 0;
    newMarket->amountOfProviders = 0;

    newMarket->maxCapacityOfFactories = initialCapacityOfArrays;
    newMarket->maxCapacityOfProducts = initialCapacityOfArrays;
    newMarket->maxCapacityOfProviders = initialCapacityOfArrays;

    newMarket->factories = malloc(sizeof(Factory*) * initialCapacityOfArrays);
    newMarket->products = malloc(sizeof(Product*) * initialCapacityOfArrays);
    newMarket->providers = malloc(sizeof(Provider*) * initialCapacityOfArrays);

    return newMarket;
}
void destroyMarket(Market* market){
    for (int i = 0; i < market->amountOfProducts; ++i) {
        destroyProduct(market->products[i]);
    }

    for (int j = 0; j < market->amountOfProviders; ++j) {
        freeProvider(market->providers[j]);
    }
    for (int k = 0; k < market->amountOfFactories; ++k) {
        freeFactory(market->factories[k]);
    }
    free(market);
}

Product* getProduct(Market* market,int code){
    for (int i = 0; i < market->amountOfProducts; ++i) {
        if(market->products[i]->codeNumber == code){
            return market->products[i];
        }
    }
    return NULL;
}


void addNewProduct(Market* market, Product* product){
    if(market->amountOfProducts==market->maxCapacityOfProducts) {
        market->products = realloc(market->products, sizeof(Product *) * market->maxCapacityOfProducts * 2);
        market->maxCapacityOfProducts = market->maxCapacityOfProducts * 2;
    }
    market->products[market->amountOfProducts]=product;
    market->amountOfProducts++;
}

void addNewProvider(Market* market, Provider* provider){
    if(market->amountOfProviders==market->maxCapacityOfProviders) {
        market->providers = realloc(market->providers, sizeof(Provider *) * market->maxCapacityOfProviders * 2);
        market->maxCapacityOfProviders = market->maxCapacityOfProviders * 2;
    }
    market->providers[market->amountOfProviders]=provider;
    market->amountOfProviders++;

}
void addNewFactory(Market* market, Factory* factory){
    if(market->amountOfFactories==market->maxCapacityOfFactories) {
        market->factories = realloc(market->factories, sizeof(Factory *) * market->maxCapacityOfFactories * 2);
        market->maxCapacityOfFactories = market->maxCapacityOfFactories * 2;
    }
    market->factories[market->amountOfProducts]=factory;
    market->amountOfFactories++;
}

void printMarket(Market* market){
    printf("-- Market info -- \n(PRODUCTS) \n");
    for (int i = 0; i < market->amountOfProducts; ++i) {
        printProduct(market->products[i]);
    }
    printf("(FACTORIES) \n");
    for (int j = 0; j < market->amountOfFactories; ++j) {
        printFactory(market->factories[j]);
    }
    printf("(PROVIDERS) \n");
    for (int k = 0; k < market->amountOfProviders; ++k) {
        printProvider(market->providers[k]);
    }
}

void printProducts(Market* market){
    printf("Products available in the market\n");
    for (int i = 0; i < market->amountOfProducts; ++i) {
        printProduct(market->products[i]);
    }
}
