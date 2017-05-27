//
// Created by Marcos khabie on 26/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "Sale.h"

Sale* createSale(int code, int discount, int initialAmountOfSaleLines){
    Sale* newSale = malloc(sizeof(Sale));
    newSale->code = code;
    newSale->discount = discount;
    newSale->finalPrice = 0;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char dateOfSale[64];
    strftime(dateOfSale, sizeof(dateOfSale), "%c", tm);

    newSale->dateOfSale = malloc(sizeof(char)*(strlen(dateOfSale)+1));
    strcpy(newSale->dateOfSale, dateOfSale);

    newSale->maxAmountOfSaleLines = initialAmountOfSaleLines;
    newSale->amountOfSaleLines = 0;

    newSale->saleLines = malloc(sizeof(SaleLine*) * initialAmountOfSaleLines);
}
Sale* destroySale(Sale* sale);

void addNewSaleLine(Sale* sale, SaleLine* saleLine){
    if(sale->amountOfSaleLines == sale->maxAmountOfSaleLines){
        sale->saleLines = realloc(sale->saleLines, sizeof(SaleLine*)* sale->maxAmountOfSaleLines*2);
        sale->maxAmountOfSaleLines = sale->maxAmountOfSaleLines*2;
    }
    sale->saleLines[sale->amountOfSaleLines] = saleLine;
    sale->amountOfSaleLines++;

    sale->finalPrice += (priceOfSaleLine(saleLine) *(1-sale->discount));
}

