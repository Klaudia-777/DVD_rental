#include <iostream>
#include <thread>
#include <zconf.h>
#include "DVD.h"
#include "MovieBase.h"
#include "RentalService.h"
#include "Status.h"
#include "movieGenre.h"
#include "InterfaceController.h"
#include "DVDParser.h"
#include "ClientParser.h"
#include "fileOperations.h"


using namespace std;

void myThread(InterfaceController *interfaceController) {    // a new thread in which the time of rental for each client
    while (true) {                      // and also payments for exceeded rental time are being counted
        interfaceController->getRent().countTimeAndPayments();
    }
}

void displayOptions() {
    cout << "MENU:" << endl;
    cout << "1. Add new DVD to base." << endl;
    cout << "2. Remove DVD from base." << endl;
    cout << "3. Add new client." << endl;
    cout << "4. Remove client from base." << endl;
    cout << "5. Rent a DVD." << endl;
    cout << "6. Return a DVD." << endl;
    cout << "7. Find by genre." << endl;
    cout << "8. Display available DVDs." << endl;
    cout << "9. Display rented DVDs:" << endl;
    cout << "10. Display client's data." << endl;
    cout << "11. Save." << endl;
    cout << "12. Exit." << endl;

}

void
handleInput(int option, InterfaceController &interfaceController, DVDParser &dvdParser,
            ClientParser &clientParser) {
    switch (option) {
        case 1:
            interfaceController.addNewDVDToBase();
            break;
        case 2:
            interfaceController.removeDVDFromBase();
            break;
        case 3:
            interfaceController.addNewClient();
            break;
        case 4:
            interfaceController.removeClient();
            break;
        case 5:
            interfaceController.rentDVD();
            break;
        case 6:
            interfaceController.returnDVD();
            break;
        case 7:
            interfaceController.findByGenre();
            break;
        case 8:
            interfaceController.displayAvailableDVDs();
            break;
        case 9:
            interfaceController.displayRentedDVDs();
            break;
        case 10:
            interfaceController.displayClientsData();
            break;
        case 11: {
            writeToFile(interfaceController.getRent(), dvdParser, clientParser);
            break;
        }
        case 12:
            break;
        default:
            cerr << "There's no such option. Choose again." << endl;
            break;

    }
}


int main() {

    DVDParser dvdParser;
    ClientParser clientParser;
    RentalService rent;

    readFromFile(rent, dvdParser, clientParser);

    InterfaceController interfaceController(rent);

    thread t1(myThread, &interfaceController);

    while (true) {
        displayOptions();
        int option;
        cin >> option;
        handleInput(option, interfaceController, dvdParser, clientParser);
        if (option == 12) {
            return 0;
        }
    }
}