//
// Created by Marcos khabie on 26/5/17.
//

#include <stringlist.h>

#ifndef EJERCICIO2_REGISTEREDUSER_H
#define EJERCICIO2_REGISTEREDUSER_H



typedef struct registeredUser{

    char* name;
    int dni;
    int direction;
    int tel;
    int locality;
    char* province;
    char* country;
    char* zipCode;
    int type ;// 0 client 1 admin
    Sales** sales;

}RegisteredUser;

RegisteredUser* createUser(  char* name, int dni, int direction, int tel, int locality, char* province, char* country, char* zipCode, int type ,  Sales** sales);

void freeUser(RegisteredUser* registeredUser);


#endif //EJERCICIO2_REGISTEREDUSER_H
