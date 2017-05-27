//
// Created by Marcos khabie on 26/5/17.
//

#ifndef EJERCICIO2_SALES_H
#define EJERCICIO2_SALES_H

#include "SaleLine.h"

typedef struct sale{
    int code;
    char* dateOfSale;
    double finalPrice;
    double discount;

    SaleLine* saleLine;
    int amountOfSaleLines;
    int maxAmountOfSaleLines;

}Sale;

#endif //EJERCICIO2_SALES_H
