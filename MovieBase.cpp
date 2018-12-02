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


void MovieBase::removeFromBase(int id) {
    base.erase(id);
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




