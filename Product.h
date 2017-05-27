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
    double price;

    int type; // 1 for camara, 0 for accessory.

    double megaPixels;
    double screen;
    double zoom;
    enum Type;

    char* typeOfAccessory;
    char* description;
}Product;

Product* createCamara(char* name, int codeNumber, double price, int type, double megaPixels, double screen, double zoom,enum Type);
Product* createAccessory(char* name, int codeNumber, double price, int type, char* typeOfAccessory, char* description);
void destroyProduct(Product* product);

#endif //EJERCICIO2_PRODUCT_H
