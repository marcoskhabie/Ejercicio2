//
// Created by Marcos khabie on 26/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <printf.h>
#include "Sale.h"

Sale* createSale(int code, double discount, int initialAmountOfSaleLines){
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

    return newSale;
}
Sale* destroySale(Sale* sale){
    for (int i = 0; i < sale->amountOfSaleLines; ++i) {
        destroySaleLine(sale->saleLines[i]);
    }
    free(sale->dateOfSale);
    free(sale);
}

void printSale(Sale* sale){
    printf("Code of sale: %d, ",sale->code );

    printf("Date: %s, ",sale->dateOfSale );
    printf("current price: %lf ", sale->finalPrice);
    printf("(%lf discount), sale lines included: \n", sale->discount);
    if (sale->amountOfSaleLines == 0){
        printf("Empty.\n");
    }
    else{
        for (int i = 0; i < sale->amountOfSaleLines; ++i) {
            printSaleLine(sale->saleLines[i]);
        }
    }


}


void addNewSaleLine(Sale* sale, SaleLine* saleLine){
    if(sale->amountOfSaleLines == sale->maxAmountOfSaleLines){
        sale->saleLines = realloc(sale->saleLines, sizeof(SaleLine*)* sale->maxAmountOfSaleLines*2);
        sale->maxAmountOfSaleLines = sale->maxAmountOfSaleLines*2;
    }
    sale->saleLines[sale->amountOfSaleLines] = saleLine;
    sale->amountOfSaleLines++;

    sale->finalPrice += (priceOfSaleLine(saleLine) *(1-sale->discount));
}

