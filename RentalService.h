//
// Created by klaudia on 01.12.18.
//

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

    std::vector<DVD> filterGenre(Genre genre);

    MovieBase &getMovieBase();

    ClientBase &getClientBase();
};


#endif //DVD_RENTAL_RENTALSYSTEM_H
