#include <iostream>
#include "MovieBase.h"

MovieBase::MovieBase() {}

void MovieBase::addToBase(DVD movie) {
    int id = movie.getId();
    base.emplace(std::make_pair(id, movie));
}


void MovieBase::removeFromBase(int id) {
    if(base.at(id).getStatus()==booked) std::cout << "No such DVD in store. It's rented."<< std::endl;
    else base.erase(id);
}

std::vector<DVD> MovieBase::findByStatus(Status status) {
    std::vector<DVD> foundMovies;
    for (auto &it : base) {
        if ((it.second).getStatus() == status) {
            foundMovies.emplace_back(it.second);
        }
    }
    return foundMovies;
}

std::vector<DVD> MovieBase::findByGenre(Genre genre) {
    std::vector<DVD> foundMovies;
    for (auto &it : base) {
        if ((it.second).getGenre() == genre) {
            foundMovies.emplace_back(it.second);
        }
    }
    return foundMovies;
}

DVD &MovieBase::findById(int id) {
    return base.at(id);
}

const std::map<int, DVD> &MovieBase::getBase() const {
    return base;
}