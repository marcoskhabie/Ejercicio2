//
// Created by Marcos khabie on 26/5/17.
//

#ifndef EJERCICIO2_FACTORY_H
#define EJERCICIO2_FACTORY_H

typedef struct factory{

    char* name;
    int id;

}Factory;

Factory* createFactory(char* name, int id);
void freeFactory(Factory* factory);
#endif //EJERCICIO2_FACTORY_H
