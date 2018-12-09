#include <iostream>
#include "DVD.h"
#include "MovieBase.h"
#include "RentalService.h"
#include "Status.h"
#include "movieGenre.h"
#include "interface.h"
#include <thread>
#include <zconf.h>



void myThread(RentalService *rent) {
    while (true) {
        rent->countTimeAndPayments();
    }
}

using namespace std;


int main() {
    RentalService rent;

    thread t1(myThread, &rent);

    while (true) {

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
        cout << "11. Exit." << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                addNewDVDToBase(rent);
                break;
            case 2:
                removeDVDFromBase(rent);
                break;
            case 3:
                addNewClient(rent);
                break;
            case 4:
                removeClient(rent);
                break;
            case 5:
                rentDVD(rent);
                break;
            case 6:
                returnDVD(rent);
                break;
            case 7:
                findByGenre(rent);
                break;
            case 8:
                displayAvailableDVDs(rent);
                break;
            case 9:
                displayRentedDVDs(rent);
                break;
            case 10:
                displayClientsData(rent);
                break;
            case 11:
                cout << "EXIT" << endl;
                return 0;

            default:
                cerr << "There's no such option. Choose again." << endl;
                break;

        }

    }
    return 0;
}