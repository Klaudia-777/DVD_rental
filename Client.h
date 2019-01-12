/*
 *  Domain class representing single client in client base.
 */

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
    std::string information;   // a message displaying in customer's profile when rental time is exceeded
    std::map<int, int> rented; // map of rented DVDs <DVD's id, corresponding rental time>
    int id=0;
    double toPayForKeeping;

public:
    Client();

    Client(const std::string &name, const std::string &surname,int id);

    int getId() const;

    const std::string &getName() const;

    const std::string &getSurname() const;

    std::map<int, int> &getRented();

    const std::string &getInformation() const;

    double getToPayForKeeping() const;

    void setToPayForKeeping(double toPayForKeeping);

    void setName(const std::string &name);

    void setSurname(const std::string &surname);

    void setRented(const std::map<int, int> &rented);

    void setId(int id);

    void addPayment(double toPay);

    void setInformation(const std::string &information);

    friend std::ostream &operator<<(std::ostream &os, const Client &client);



};

#endif //DVD_RENTAL_CLIENT_H
