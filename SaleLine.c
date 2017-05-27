//
// Created by Agustin Bettati  on 26/5/17.
//

#include <stdlib.h>
#include "SaleLine.h"

SaleLine* createSaleLine(int code, Product* product, int amount){
    SaleLine* newSaleLine = malloc(sizeof(SaleLine));
    newSaleLine->code = code;
    newSaleLine->product = product;
    newSaleLine->amount = amount;
}
void destroySaleLine(SaleLine* saleLine){
    free(saleLine);
}
double priceOfSaleLine(SaleLine* saleLine){
    return saleLine->product->price * saleLine->amount;
}
