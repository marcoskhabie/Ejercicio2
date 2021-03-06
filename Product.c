//
// Created by Marcos khabie on 26/5/17.
//

#include <printf.h>
#include <stdlib.h>
#include <string.h>
#include "Product.h"

Product* createCamera(char* name,int typeOfCamera, int codeNumber, double price, double megaPixels, double screen, double zoom, int idProvider,int idFactory){
    Product* newProduct= malloc(sizeof(Product));

    newProduct->name= malloc(sizeof(char)* (strlen(name)+1));
    strcpy(newProduct->name,name);

    newProduct->codeNumber=codeNumber;
    newProduct->typeOfCamera=typeOfCamera;
    newProduct->price=price;
    newProduct->type=1;
    newProduct->megaPixels=megaPixels;
    newProduct->screen=screen;
    newProduct->zoom=zoom;
    newProduct->idFactory=idFactory;
    newProduct->idProvider=idProvider;

    return newProduct;

}

Product* createAccessory(char* name, int codeNumber, double price, char* typeOfAccessory, char* description, int idProvider,int idFactory){

    Product* newProduct= malloc(sizeof(Product));

    newProduct->name= malloc(sizeof(char)* (strlen(name)+1));
    newProduct->description=malloc(sizeof(char)* (strlen(description)+1));
    newProduct->typeOfAccessory=malloc(sizeof(char)* (strlen(typeOfAccessory)+1));

    strcpy(newProduct->name,name);
    strcpy(newProduct->description,description);
    strcpy(newProduct->typeOfAccessory,typeOfAccessory);

    newProduct->codeNumber=codeNumber;
    newProduct->price=price;
    newProduct->type=0;
    newProduct->idFactory=idFactory;
    newProduct->idProvider=idProvider;

    return newProduct;

}

void printProduct(Product* product){

    printf("Name of product %s, ", product->name);
    printf("Code number: %d,", product->codeNumber);
    printf("Price: %lf,", product->price);
    printf("Id of provider: %d,", product->idProvider);
    printf("Id of factory: %d. \n", product->idFactory);
    printf("Additional information -> ");

    if(product->type==1){
        printf("product type: Camera, ");

        printf("MegaPixels: %f,", product->megaPixels);
        printf("Screen: %f, ", product->screen);
        printf("Zoom: %f, ", product->zoom);
        if (product->typeOfCamera==0){
            printf("Type of Camera : Reflex  \n" );
        }

        else { printf("Type of Camera : Compact \n" );}


    }
    else{
        printf("product type: Accessory, ");

        printf("%s, ", product->typeOfAccessory);
        printf("%s \n", product->description);
    }


}
void destroyProduct(Product* product){

    free( product->name);
    free(product->typeOfAccessory);
    free(product->description);
    free(product);
}
