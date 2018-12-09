//
// Created by klaudia on 05.12.18.
//

#include "Client.h"


static int incrementer = 0;

Client::Client(const std::string &name, const std::string &surname) : name(name),
                                                                      surname(surname) {  //---------obiekt tworzymy przy pierwszym wypozyczeniu,
    this->name = name;                                                                      //-------pozniej pytamy o id i szukamy w bazie
    this->surname = surname;
    rented = {};
    toPayForKeeping = 0.0;
    information = "";
    id = incrementer++;
}

int Client::getId() const {
    return id;
}

std::map<int, int> &Client::getRented() {
    return rented;
}

const std::string &Client::getName() const {
    return name;
}

const std::string &Client::getSurname() const {
    return surname;
}

std::ostream &operator<<(std::ostream &os, const Client &client) {
    os << "-------~CLIENT'S DATA~------" << std::endl;
    os << "Client's id: " << client.id << std::endl << "Name: " << client.name << std::endl << "Surname: "
       << client.surname << std::endl << client.information << std::endl;
    os << "Rented DVDs: " << std::endl;
    for (auto i : client.rented) {
        os << "DVDs id: " << i.first << " " << "Rented for: " << i.second << std::endl;
    }
    os << std::endl;
    os << "toPayForKeeping: "
       << client.toPayForKeeping << std::endl << "-----------------------------";
    return os;
}


void Client::setToPayForKeeping(double toPayForKeeping) {
    this->toPayForKeeping = toPayForKeeping;
}

void Client::addPayment(double toPay) {
    this->toPayForKeeping += toPay;
}

double Client::getToPayForKeeping() const {
    return toPayForKeeping;
}

void Client::setInformation(const std::string &information) {
    Client::information = information;
}
