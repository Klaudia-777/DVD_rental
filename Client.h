//
// Created by klaudia on 05.12.18.
//

#ifndef DVD_RENTAL_CLIENT_H
#define DVD_RENTAL_CLIENT_H

#include <string>
#include <map>
#include <ostream>
#include "DVD.h"

class Client {
private:
    std::string name;
    std::string surname;
    std::map<int, int> rented; //------------id DVD, czas trzymania
    bool keepingTooLong;
    int id;
    double toPayForKeeping;

public:
    Client(const std::string &name, const std::string &surname);

    int getId() const;

    const std::string &getName() const;

    const std::string &getSurname() const;

    std::map<int, int> &getRented();

    void setKeepingTooLong(bool keepingTooLong);

    void setToPayForKeeping(double toPayForKeeping);

    friend std::ostream &operator<<(std::ostream &os, const Client &client);
};


#endif //DVD_RENTAL_CLIENT_H
