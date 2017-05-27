//
// Created by Agustin Bettati  on 27/5/17.
//

#include <stdlib.h>
#include <printf.h>
#include "RegisteredUser.h"

void printListOfUsers(RegisteredUser** listOfUsers, int amt){
    for (int i = 0; i < amt; ++i) {
        printUser(listOfUsers[i]);
    }
}

RegisteredUser* findUser(int dni, RegisteredUser** listOfUsers, int amt){
    for (int i = 0; i < amt; ++i) {
        if(listOfUsers[i]->dni == dni){
            return listOfUsers[i];
        }
    }
    printf("No user has the dni entered.");
}

int main() {
      RegisteredUser* client1 = createUser("Agustin", 40269313, "5th Avenue",30202302,"New York","U.S.A.", 1252, 0);
    RegisteredUser* client2 = createUser("Marcos", 40265403, "Cabildo",543020202,"Buenos Aires","Argentina", 1010, 0);
    RegisteredUser* admin1 = createUser("Jorge", 38502342, "5th Avenue",23020232,"New York","U.S.A.", 1202, 1);
    RegisteredUser* admin2 = createUser("John", 39406323, "Cabildo",39202302,"Buenos Aires","Argentina", 1002, 1);

    RegisteredUser** listOfUsers = malloc(sizeof(RegisteredUser*)* 4);
    listOfUsers[0] = client1;
    listOfUsers[1] = client2;
    listOfUsers[2] = admin1;
    listOfUsers[3] = admin2;

    printListOfUsers(listOfUsers, 4);

    RegisteredUser* selectedUser = listOfUsers[2];






//    printf("\nBefore starting the system, some people and materials where added \nto make it easier to see its functionality. \n");
//    int action = -1;
//    do{
//        printf("Available operations:\n"
//                       " 1 - List of people with their respective loans.\n"
//                       " 2 - List of available material.\n"
//                       " 3 - Add new person.\n"
//                       " 4 - Add new material.\n"
//                       " 5 - Person asks for a loan.\n"
//                       " 6 - Person returns a loan.\n"
//                       " 7 - Close system.\n"
//                       "Enter your desired operation: ");
//        scanf("%d",&action);
//        printf("\n");
//
//        switch(action){
//            case 1:
//                break;
//            case 2:
//                break;
//            case 3:
//                break;
//            case 4:
//                break;
//            case 5:
//                break;
//            case 6:
//                break;
//            case 7:
//                printf("Hope the system was useful!");
//                break;
//            default:
//                printf("Please enter a valid operation! \n");
//                break;
//        }
//
//    } while(action != 7);

    return 0;
}

