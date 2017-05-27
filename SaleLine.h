//
// Created by Agustin Bettati  on 26/5/17.
//

#ifndef EJERCICIO2_SALELINE_H
#define EJERCICIO2_SALELINE_H

#include "Product.h"

typedef struct saleLine{
    int code;
    Product* product;
    int amount;

}SaleLine;

SaleLine* createSaleLine(int code, Product* product, int amount);
void destroySaleLine(SaleLine* saleLine);
double priceOfSaleLine(SaleLine* saleLine);

#endif //EJERCICIO2_SALELINE_H
