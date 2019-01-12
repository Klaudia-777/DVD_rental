/*
 *  Service class implementing methods responsible
 *  for the entire rental logic.
 */

#ifndef DVD_RENTAL_RENTALSYSTEM_H
#define DVD_RENTAL_RENTALSYSTEM_H

#include "DVD.h"
#include "MovieBase.h"
#include "movieGenre.h"
#include "ClientBase.h"

class RentalService {

    MovieBase movieBase;
    ClientBase clientBase;
public:

    void rentDVD(int id);

    void returnDVD(int id);

    void countTimeAndPayments();

    void displayAvailableDVDs(std::vector<DVD> vec);

    void display(bool which);       // displays stored (1) or rented  (0) DVDs

    std::vector<DVD> filterByGenre(Genre genre);

    MovieBase &getMovieBase();

    ClientBase &getClientBase();
};

#endif //DVD_RENTAL_RENTALSYSTEM_H
