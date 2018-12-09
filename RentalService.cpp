//
// Created by klaudia on 01.12.18.
//

#include <iostream>
#include <zconf.h>
#include "RentalService.h"

void RentalService::displayAvailableDVDs(std::vector<DVD> vec) {
    for (auto it : vec)
        std::cout << it.getTitle() << "\t" << it.getId() << std::endl;
}

std::vector<DVD>                                       // + filtrowanie po tytułach
RentalService::filterGenre(Genre genre) {              // + funkcja zliczająca ile filmów o tym samym tytule
    auto foundMovies = movieBase.findByGenre(genre);
    if (!foundMovies.empty())
        displayAvailableDVDs(foundMovies);
    else
        std::cout << "No movies found" << std::endl;
    return foundMovies;
}

void RentalService::rentDVD(int id) {
    if (!movieBase.findById(id).getStatus() == booked) {
        clientBase.rentDVD(id);
        movieBase.findById(id).setStatus(booked);
    } else std::cout << "This DVD is not available" << std::endl;
}

void RentalService::returnDVD(int id) {
    if (!movieBase.findById(id).getStatus() == inStore) {
        clientBase.returnDVD(id);
        movieBase.findById(id).setStatus(inStore);
    } else std::cout << "This DVD is already in store." << std::endl;
}

MovieBase &RentalService::getMovieBase() {

    return movieBase;
}

ClientBase &RentalService::getClientBase() {
    return clientBase;
}

void RentalService::countTimeAndPayments() {
    for(auto client : clientBase.getBase()){
        for(auto DVDs :client.second.getRented()){
            if(DVDs.second>=5) {
                client.second.setKeepingTooLong(true);
                client.second.setToPayForKeeping(0.1);
            }
            if(DVDs.second==5) {
                std::cout << "Przekroczono czas wypożyczenia. " << client.second.getName()<<std::endl;
            }
            std::cout << "Przekroczono czas wypożyczenia. " << DVDs.second<<std::endl;

            DVDs.second++;
        }
    }
}







