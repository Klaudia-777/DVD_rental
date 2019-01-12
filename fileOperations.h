/*
 * In this file there are methods handling file I/O operations.
 * While running application function readFromFile() is being called
 * and each line from DVDs.txt and Clients.txt is turned into object.
 * Then, recently created objects are placed in proper bases.
 * Function writeToFile is called every time when we create new object
 * from console.
 */

#ifndef DVD_RENTAL_FILEOPERATIONS_H
#define DVD_RENTAL_FILEOPERATIONS_H

#include "ClientParser.h"
#include "DVDParser.h"
#include "RentalService.h"

void writeToFile(RentalService &rentalService, DVDParser &dvdParser, ClientParser &clientParser);
void readFromFile(RentalService &rentalService, DVDParser &dvdParser, ClientParser &clientParser);
#endif //DVD_RENTAL_FILEOPERATIONS_H
