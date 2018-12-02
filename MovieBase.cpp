//
// Created by klaudia on 01.12.18.
//

#include <bits/streambuf_iterator.h>
#include "MovieBase.h"

MovieBase::MovieBase() {}

void MovieBase::addToBase(DVD movie) {
    int id = movie.getId();
    base.emplace(std::make_pair(id, movie));
}

void MovieBase::saveRentedDVDs(int id) {
   rentedDVDs.emplace(std::make_pair(id, base.at(id)));
}

void MovieBase::removeFromBase(int id) {
        base.erase(id);
}

void MovieBase::removeFromRentedDVDs(int id) {
       rentedDVDs.erase(id);
}

std::map<int, DVD> MovieBase::getBase() const{
    return base;
}

std::map<int, DVD> MovieBase::getRentedDVDs() const {
    return rentedDVDs;
}




