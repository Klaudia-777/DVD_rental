#include <vector>
#include <iostream>
#include <zconf.h>
#include "DVD.h"
#include "RentalService.h"
#include "globalFunctions.h"

void RentalService::displayAvailableDVDs(std::vector<DVD> vec) {
    for (auto it : vec)
        std::cout << it.getTitle() << "\t" << it.getId() << std::endl;
}

std::vector<DVD>
RentalService::filterByGenre(Genre genre) {
    auto foundMovies = movieBase.findByGenre(genre);
    if (!foundMovies.empty())
        displayAvailableDVDs(foundMovies);
    else
        std::cout << "No movies found" << std::endl;
    return foundMovies;
}

void RentalService::rentDVD(int id) {
    if (movieBase.getBase().find(id) == movieBase.getBase().end()) {
        std::cout << "There is no such DVD in the base." << std::endl;
    } else if (!movieBase.findById(id).getStatus() == booked) {
        clientBase.rentDVD(id);
        movieBase.findById(id).setStatus(booked);
    } else std::cout << "This DVD is not available" << std::endl;
}

void RentalService::returnDVD(int id) {
    if (!movieBase.findById(id).getStatus() == inStore) {
        if (clientBase.returnDVD(id)) {
            movieBase.findById(id).setStatus(inStore);
        }
    } else std::cout << "This DVD is already in store." << std::endl;
}

void RentalService::countTimeAndPayments() {
    for (auto client : clientBase.getBase()) {
        for (auto DVDs :client.second.getRented()) {
            if (DVDs.second >= 5) {
                clientBase.findById(client.first).addPayment(0.1);

            }
            if (DVDs.second == 5) {
                clientBase.findById(client.first).setInformation("Przekroczono_czas_wypozyczenia");
            }
            DVDs.second+=1;
            clientBase.findById(client.first).getRented().at(DVDs.first)+=1;

        }
    }
    sleep(5);    //customer's data are being updated every 5s
}

void RentalService::display(bool which) {
    for (auto &it : movieBase.findByStatus(which ? inStore : booked))
        std::cout << it.getId() << ": " << it.getTitle() << ", " << genreToString(it.getGenre()) << std::endl;
}

MovieBase &RentalService::getMovieBase() {

    return movieBase;
}

ClientBase &RentalService::getClientBase() {
    return clientBase;
}
