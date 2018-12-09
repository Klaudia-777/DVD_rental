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
    if(movieBase.getBase().find(id)==movieBase.getBase().end()){
        std::cout << "There is no such DVD in the base." << std::endl;
    }
    else if (!movieBase.findById(id).getStatus() == booked) {
        clientBase.rentDVD(id);
        movieBase.findById(id).setStatus(booked);
    } else std::cout << "This DVD is not available" << std::endl;
}

void RentalService::returnDVD(int id) {
    if (!movieBase.findById(id).getStatus() == inStore) {
        if(clientBase.returnDVD(id)){
            movieBase.findById(id).setStatus(inStore);
        }
    } else std::cout << "This DVD is already in store." << std::endl;
}

MovieBase &RentalService::getMovieBase() {

    return movieBase;
}

ClientBase &RentalService::getClientBase() {
    return clientBase;
}

void RentalService::countTimeAndPayments() {
    for (auto client : clientBase.getBase()) {
        for (auto DVDs :client.second.getRented()) {
            if (DVDs.second >= 5) {
                clientBase.findById(client.first).addPayment(0.1);

            }
            if (DVDs.second == 5) {
                clientBase.findById(client.first).setInformation("Przekroczono czas wypożyczenia.");
            }
            DVDs.second++;
            clientBase.findById(client.first).getRented().at(DVDs.first)++;

        }
    }
    sleep(5);    //-----------dane klienta na potrzeby testów uaktualniają sie co 5s

}

std::string genreToString(Genre genre) {
    if (genre == Action) return "Action";
    else if (genre == Adventure) return "Adventure";
    else if (genre == Comedy) return "Comedy";
    else if (genre == Crime) return "Crime";
    else if (genre == Drama) return "Drama";
    else if (genre == Fantasy) return "Fantasy";
    else if (genre == Historical) return "Historical";
}

void RentalService::display(bool which) {
    if (which) {
        for (auto &it : movieBase.findByStatus(inStore))
            std::cout << it.getId() << ": " << it.getTitle() << ", " << genreToString(it.getGenre()) << std::endl;
    } else {
        for (auto &it : movieBase.findByStatus(booked))
            std::cout << it.getId() << ": " << it.getTitle() << ", " << genreToString(it.getGenre()) << std::endl;
    }
}







