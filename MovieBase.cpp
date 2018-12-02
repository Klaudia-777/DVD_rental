//
// Created by klaudia on 01.12.18.
//

#include <bits/streambuf_iterator.h>
#include "MovieBase.h"

MovieBase::MovieBase() {}

MovieBase::MovieBase(std::map<int, DVD> base) {
    this->base = base;
}

void MovieBase::addToBase(DVD movie) {
    int id = movie.getId();
    base.emplace(std::make_pair(id, movie));
}

void MovieBase::saveRentedDVDs(int id) {
    for (auto it = base.begin(); it != base.end(); ++it) {
        if (it->first == id) rentedDVDs.emplace(std::make_pair(it->first, it->second));
    }
}

void MovieBase::removeFromBase(int id) {
    for (auto it = base.begin(); it != base.end(); ++it) {
        if (it->first == id) base.erase(it);
    }
}

void MovieBase::removeFromRentedDVDs(int id) {
    for (auto it = rentedDVDs.begin(); it != rentedDVDs.end(); ++it) {
        if (it->first == id) rentedDVDs.erase(it);
    }
}

std::map<int, DVD> MovieBase::getBase() {
    return base;
}

std::map<int, DVD> MovieBase::getRentedDVDs() const {
    return rentedDVDs;
}

MovieBase &MovieBase::operator=(MovieBase movieBase) {
    base = movieBase.getBase();
    rentedDVDs = movieBase.getRentedDVDs();
    return *this;
}



