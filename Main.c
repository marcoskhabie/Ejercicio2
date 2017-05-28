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

Product* newProduct(){
    char name[20];
    int code;
    double price;
    int idProvider;
    int idFactory;
    int typeOfProduct;
    printf("--Enter information of new product--\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter code number: ");
    scanf("%d", &code);
    printf("Price of product: ");
    scanf("%lf", &price);
    printf("Id of the provider: ");
    scanf("%d", &idProvider);
    printf("Id of the factory: ");
    scanf("%d", &idFactory);
    printf("Camera (1) or a Accessory(0): ");
    scanf("%d", &typeOfProduct);
    if(typeOfProduct == 1){
        int typeOfCamera;
        double megaPixels;
        double screen;
        double zoom;
        printf("Compact (1) or Reflex(0): ");
        scanf("%d", &typeOfCamera);
        printf("megaPixels: ");
        scanf("%lf", &megaPixels);
        printf("screen size: ");
        scanf("%lf", &screen);
        printf("zoom: ");
        scanf("%lf", &zoom);
        return createCamera(name,typeOfCamera,code,price,megaPixels,screen,zoom,idProvider,idFactory);
    }
    else{
        char typeOfAccessory[20];
        char description[20];
        printf("Type of accessory: ");
        scanf("%s", typeOfAccessory);
        printf("Description: ");
        scanf("%s", description);
        return createAccessory(name,code,price,typeOfAccessory,description,idProvider,idFactory);
    }

}

Factory* newFactory(){
    char name[20];
    int id;
    printf("--Registering new factory--\n");
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter id number: ");
    scanf("%d", &id);
    return createFactory(name, id);
}

Provider* newProvider(){
    char name[20];
    int id;
    int telephone;
    char country[20];
    char province[20];
    char locality[20];
    char direction[20];
    int zipCode;

    printf("--Registering new provider--\n");
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter id number: ");
    scanf("%d", &id);
    printf("Enter telephone number: ");
    scanf("%d", &telephone);
    printf("Country: ");
    scanf("%s", country);
    printf("Province: ");
    scanf("%s", province);
    printf("Locality: ");
    scanf("%s", locality);
    printf("Direction: ");
    scanf("%s", direction);
    printf("zip code: ");
    scanf("%d", &zipCode);

    return createProvider(name,id,direction,telephone,locality,province,country,zipCode);
}

Sale* askForValuesAndCreateSale(){
    int code;
    double discount;
    printf("--Creating new Sale--\n");
    printf("Enter code of sale: ");
    scanf("%d",&code);
    printf("Discount of the sale: ");
    scanf("%lf", &discount);
    return createSale(code, discount,10);
}

void askForSaleNumberAndCreateNewSaleLine(RegisteredUser* user, Market* market){
    int code;
    printf("Enter the code of the sale: ");
    scanf("%d",&code);

    int saleLineCode;
    int codeOfProduct;
    int amount;
    printf("--Creating new sale line--\n");
    printf("code of the sale line: ");
    scanf("%d",&saleLineCode);
    printf("code of the product: ");
    scanf("%d", &codeOfProduct);
    printf("quantity of the specified product: ");
    scanf("%d", &amount);

    addNewSaleLineToSale(user,code,createSaleLine(saleLineCode,
                                                  getProduct(market,codeOfProduct),amount));
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
    addNewFactory(market, createFactory("Tech factory",10));
    addNewProduct(market, createCamera("Canon",1, 101, 4500,3.2,21.5,4,1,10));
    addNewProduct(market, createCamera("Sony",0,212,4000,6,12,7,1,10));
    addNewProduct(market, createAccessory("Tripod",98,250,"stabilizer","rigid tripod",1,10));
    addNewProduct(market, createAccessory("Modular microphone",32,600,"directional mic.","",1,10));

    addNewSale(client1, createSale(13, 0.05,10));
    addNewSaleLineToSale(client1,13,createSaleLine(15, getProduct(market, 101),3));


    int closeProgram = 0;
    RegisteredUser* selectedUser = listOfUsers[2];

    while(closeProgram != 1) {
        int action = -1;
        printf("\nCurrent User: ");
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
                case 2:
                    printProducts(market);
                    break;
                case 3:
                    printSalesOfUser(selectedUser);
                    break;
                case 4:
                    addNewSale(selectedUser, askForValuesAndCreateSale());
                    break;
                case 5:
                    askForSaleNumberAndCreateNewSaleLine(selectedUser, market);
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
                case 2:
                    printMarket(market);
                    break;
                case 3:
                    adminAddsProduct(selectedUser,market, newProduct());
                    break;
                case 4:
                    adminAddsProvider(selectedUser, market, newProvider());
                    break;
                case 5:
                    adminAddsFactory(selectedUser, market, newFactory());
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

