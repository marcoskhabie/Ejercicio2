//
// Created by Agustin Bettati  on 26/5/17.
//

#include <stdlib.h>
#include <printf.h>
#include "SaleLine.h"

SaleLine* createSaleLine(int code, Product* product, int amount){
    SaleLine* newSaleLine = malloc(sizeof(SaleLine));
    newSaleLine->code = code;
    newSaleLine->product = product;
    newSaleLine->amount = amount;

    return newSaleLine;
}
void destroySaleLine(SaleLine* saleLine){
    free(saleLine);
}
double priceOfSaleLine(SaleLine* saleLine){
    return saleLine->product->price * saleLine->amount;
}

void printSaleLine(SaleLine* saleLine){
    printf("Product: %s ", saleLine->product->name);
    printf("(code: %d), ", saleLine->product->codeNumber);
    printf("amount: %d \n", saleLine->amount);

}

