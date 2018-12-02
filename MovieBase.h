//
// Created by klaudia on 01.12.18.
//

#ifndef DVD_RENTAL_MOVIEBASE_H
#define DVD_RENTAL_MOVIEBASE_H


#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include "DVD.h"

class MovieBase {

private:
    std::map<int, DVD> base;
    std::map<int, DVD> rentedDVDs;

public:
    MovieBase(std::map<int, DVD> base);

    MovieBase();

    void addToBase(DVD object);

    void removeFromBase(int id);

    void removeFromRentedDVDs(int id);

    void saveRentedDVDs(int id);

    std::map<int, DVD> getRentedDVDs() const;

    std::map<int, DVD> getBase();

    MovieBase &operator=(MovieBase movieBase);
};


#endif //DVD_RENTAL_MOVIEBASE_H
