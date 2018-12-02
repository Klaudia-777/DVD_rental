//
// Created by klaudia on 01.12.18.
//

#include <iostream>
#include "RentalService.h"

void RentalService::displayAvailableDVDs(std::vector<std::pair<int, DVD>> vec) {
    for (std::pair<int, DVD> it : vec)
        std::cout << it.second.getTitle() << "\t" << it.first << std::endl;
}

std::vector<std::pair<int, DVD>>
RentalService::filterGenre(Genre genre) {    // + funkcja zliczająca ile filmów o tym samym tytule
    std::vector<std::pair<int, DVD>> foundMovies;
    for (auto &it : movieBase.getBase()) {
        if ((it.second).getGenre() == genre) {
            foundMovies.emplace_back(std::make_pair(it.first, it.second));
        }
    }
    if (!foundMovies.empty())
        displayAvailableDVDs(foundMovies);
    else
        std::cout << "No movies found" << std::endl;
    return foundMovies;

}


void RentalService::rentDVD(int id) {
    movieBase.saveRentedDVDs(id);
    movieBase.removeFromBase(id);

    for (auto &it : movieBase.getRentedDVDs()) {
        if (it.first == id) it.second.setStatus(booked);
    }
}

void RentalService::returnDVD(int id) {

    for (auto &it : movieBase.getRentedDVDs()) {
        if (it.first == id) {

            movieBase.addToBase(it.second);
            it.second.setStatus(inStore);

        }
    }
    movieBase.removeFromRentedDVDs(id);

}

MovieBase &RentalService::getMovieBase(){
    return movieBase;
}







