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

public:

    MovieBase();

    void addToBase(DVD object);

    void removeFromBase(int id);

    std::vector<DVD> findByStatus(Status status);

    std::vector<DVD> findByGenre(Genre genre);

    DVD &findById(int id);


};


#endif //DVD_RENTAL_MOVIEBASE_H
