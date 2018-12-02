//
// Created by klaudia on 01.12.18.
//

#ifndef DVD_RENTAL_RENTALSYSTEM_H
#define DVD_RENTAL_RENTALSYSTEM_H


#include "DVD.h"
#include "MovieBase.h"
#include "movieGenre.h"

class RentalService {

    MovieBase movieBase;

public:

    void rentDVD(int id);

    void returnDVD(int id);

    void displayAvailableDVDs(std::vector<std::pair<int, DVD>> vec);

    std::vector<std::pair<int, DVD>> filterGenre(Genre genre);

    MovieBase &getMovieBase();

};


#endif //DVD_RENTAL_RENTALSYSTEM_H
