/*
 * This Interface class implements the main methods in rental system.
 */

#ifndef DVD_RENTAL_INTERFACECONTROLLER_H
#define DVD_RENTAL_INTERFACECONTROLLER_H

#include <string>
#include "RentalService.h"

using namespace std;

class InterfaceController {
    RentalService rent;
public:
    InterfaceController(const RentalService &rent);

    void addNewDVDToBase();
    void removeDVDFromBase();
    void addNewClient();
    void removeClient();
    void rentDVD();
    void returnDVD();
    void findByGenre();
    void displayAvailableDVDs();
    void displayRentedDVDs();
    void displayClientsData();

    RentalService &getRent() ;
};


#endif //DVD_RENTAL_INTERFACECONTROLLER_H
