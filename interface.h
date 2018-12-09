//
// Created by klaudia on 09.12.18.
//

#ifndef DVD_RENTAL_INTERFACE_H
#define DVD_RENTAL_INTERFACE_H


#include "RentalService.h"

void addNewDVDToBase(RentalService &rent);
void removeDVDFromBase(RentalService &rent);
void addNewClient(RentalService &rent);
void removeClient(RentalService &rent);
void rentDVD(RentalService &rent);
void returnDVD(RentalService &rent);
void findByGenre(RentalService &rent);
void displayAvailableDVDs(RentalService &rent);
void displayRentedDVDs(RentalService &rent);
void displayClientsData(RentalService &rent);


#endif //DVD_RENTAL_INTERFACE_H
