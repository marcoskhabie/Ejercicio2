//
// Created by Marcos khabie on 26/5/17.
//

#ifndef EJERCICIO2_PRODUCT_H
#define EJERCICIO2_PRODUCT_H

enum TypeOf{
    REFLEX,
    COMPACT
};

typedef struct product{
    char* name;
    int codeNumber;
    int idProvider;
    int idFactory;
    double price;

    int type; //  0 for accessory,1 for camera.

    double megaPixels;
    double screen;
    double zoom;
    int typeOfCamera; //0 for reflex 1 for compact.

    char* typeOfAccessory;
    char* description;
}Product;


Product* createCamera(char* name,int typeOfCamera, int codeNumber, double price, double megaPixels, double screen, double zoom, int idProvider,int idFactory);

Product* createAccessory(char* name, int codeNumber, double price, char* typeOfAccessory, char* description, int idProvider,int idFactory);

void printProduct(Product* product);
void destroyProduct(Product* product);

#endif //EJERCICIO2_PRODUCT_H
