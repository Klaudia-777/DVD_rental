//
// Created by klaudia on 01.12.18.
//

#ifndef DVD_RENTAL_DVD_H
#define DVD_RENTAL_DVD_H

#include "movieGenre.h"
#include "Status.h"
#include <string>


class DVD {
private:
    Status status;
    Genre genre;
    std::string title;
    double price;
    int incrementer;
    int id = {};

public:
    DVD(Status status, Genre genre, std::string title, double price);

    Status getStatus();

    void setStatus(Status status);

    Genre getGenre() const;

    std::string getTitle();

    double getPrice();

    void setPrice(double price);

    void setIncrementer(int incrementer);

    bool operator==(const DVD &rhs) const;

    int getId() const;
};


#endif //DVD_RENTAL_DVD_H
