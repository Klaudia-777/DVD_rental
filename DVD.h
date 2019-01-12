/*
 *  Domain class representing DVD.
 */

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
    int price;
    int id = {};

public:
    DVD(Status status, Genre genre, std::string title, int price,int id);

    DVD();

    Status getStatus();

    void setStatus(Status status);

    Genre getGenre() const;

    std::string getTitle();

    int getPrice();

    void setPrice(int price);

    void setGenre(Genre genre);

    void setTitle(const std::string &title);

    void setId(int id);

    bool operator==(const DVD &rhs) const;

    int getId() const;
};

#endif //DVD_RENTAL_DVD_H
