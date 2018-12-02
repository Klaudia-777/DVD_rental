//
// Created by klaudia on 01.12.18.
//

#include <iostream>
#include "RentalService.h"

void RentalService::displayAvailableDVDs(std::vector<DVD> vec) {
    for (auto it : vec)
        std::cout << it.getTitle() << "\t" << it.getId() << std::endl;
}

std::vector<DVD >
RentalService::filterGenre(Genre genre) {              // + funkcja zliczająca ile filmów o tym samym tytule
    auto foundMovies = movieBase.findByGenre(genre);

    if (!foundMovies.empty())
        displayAvailableDVDs(foundMovies);
    else
        std::cout << "No movies found" << std::endl;
    return foundMovies;
}

void RentalService::rentDVD(int id) {

    movieBase.findById(id).setStatus(booked);
}

void RentalService::returnDVD(int id) {

    movieBase.findById(id).setStatus(inStore);

}

MovieBase &RentalService::getMovieBase() {

    return movieBase;
}







