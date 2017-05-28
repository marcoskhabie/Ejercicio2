//
// Created by Marcos khabie on 26/5/17.
//

#include <stdlib.h>
#include <string.h>
#include <printf.h>
#include "Provider.h"

Provider* createProvider(  char* name,int id, char* direction,int tel, char* locality, char* province, char* country,int zipCode){

    Provider* newProvider= malloc(sizeof(Provider));

    newProvider->name= malloc(sizeof(char)* strlen(name)+1);
    newProvider->country= malloc(sizeof(char)* (strlen(country)+1));
    newProvider->province= malloc(sizeof(char)* (strlen(province)+1));
    newProvider->direction= malloc(sizeof(char)* (strlen(direction)+1));
    newProvider->locality= malloc(sizeof(char)* (strlen(locality)+1));


    strcpy(newProvider->name,name);
    strcpy(newProvider->country,country);
    strcpy(newProvider->province,province);
    strcpy(newProvider->locality,locality);
    strcpy(newProvider->direction,direction);

    newProvider->tel=tel;
    newProvider->zipCode=zipCode;
    newProvider->id = id;

    return newProvider;
}
void printProvider(Provider* provider){

    printf("Name of provider %s, ", provider->name);
    printf("id number: %d, ", provider->id);
    printf("country: %s, ", provider->country);
    printf("province: %s, ", provider->province);
    printf("locality: %s,", provider->locality);
    printf("ZipCode: %d \n", provider->zipCode);
}
void freeProvider(Provider* provider){

    free(provider->name);
    free(provider->country);
    free(provider->province);
    free(provider->locality);
    free(provider->direction);
    free(provider);

}