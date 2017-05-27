//
// Created by Marcos khabie on 26/5/17.
//


#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "Factory.h"
#include "Market.h"

Factory* createFactory(char* name, int id){

    Factory* newFactory= malloc(sizeof(Factory));

    newFactory->name= malloc(sizeof(char)* strlen(name)+1);
    newFactory->id=id;

    strcpy(newFactory->name,name);

    return newFactory;

}
void printFactory(Factory* factory){

    printf("Name of factory %s \n", factory->name);
    printf("Code number: %d \n", factory->id);

}

void freeFactory(Factory* factory){
    free(factory->name);
    free(factory);
}