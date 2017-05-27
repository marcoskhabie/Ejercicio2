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

RegisteredUser* askForDNIAndfindUser(RegisteredUser** listOfUsers, int amt){
    int dni;
    printf("Enter the dni of the desired user: ");
    scanf("%d", &dni);
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

    Market* market = createMarket(10);
    addNewProvider(market, createProvider("BestBuy", 1, "San Martin", 3020302, "pilar", "Buenos Aires", "Argentina",1202));
    addNewProduct(market, createCamera("Canon", 1, 101, 4500,3.2,21.5,4,1,1));
    /*
     *
     *
     * Hay que hardcodear el market un poco.
     *
     *
     */

    int closeProgram = 0;
    RegisteredUser* selectedUser = listOfUsers[2];

    while(closeProgram != 1) {
        int action = -1;
        printf("Current User: ");
        printUser(selectedUser);
        printf("\n");
        if (selectedUser->type == 0) {
            printf("<< CLIENT MENU >>\n"
                           " 1 - Change user.\n"
                           " 2 - Print list of products.\n"
                           " 3 - Print my sales.\n"
                           " 4 - Add new sale.\n"
                           " 5 - Add new sale line to a sale.\n"
                           " 6 - Close system.\n"
                           "Enter your desired operation: ");
            scanf("%d", &action);
            printf("\n");

            switch (action) {
                case 1:
                    printListOfUsers(listOfUsers, 4);
                    selectedUser = askForDNIAndfindUser(listOfUsers,4);
                    break;

                case 6:
                    closeProgram =1;
                    printf("Hope the system was useful!");
                    break;
                default:
                    printf("Please enter a valid operation! \n");
                    break;
            }
        }
        else {
            printf("<< ADMIN MENU >>\n"
                           " 1 - Change user.\n"
                           " 2 - Get information of market.\n"
                           " 3 - Register new product.\n"
                           " 4 - Register new provider.\n"
                           " 5 - Register new factory.\n"
                           " 6 - Close system.\n"
                           "Enter your desired operation: ");
            scanf("%d", &action);
            printf("\n");

            switch (action) {
                case 1:
                    printListOfUsers(listOfUsers, 4);
                    selectedUser = askForDNIAndfindUser(listOfUsers,4);
                    break;

                case 6:
                    closeProgram =1;
                    printf("Hope the system was useful!");
                    break;
                default:
                    printf("Please enter a valid operation! \n");
                    break;
            }
        }
    }



    return 0;
}

