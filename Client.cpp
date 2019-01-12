#include "Client.h"

static int incrementer = 0;  // static variable representing id generator

Client::Client(const std::string &name, const std::string &surname, int id) : name(name),
                                                                              surname(surname),
                                                                              id(id) {  // object Client is created at the first rental
    this->name = name;                                                                    // when object Client already is in the base, we ask for his id
    this->surname = surname;
    rented = {};
    toPayForKeeping = 0.0;
    information = "";
    this->id = id;
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

void Client::setInformation(const std::string &information) {
    Client::information = information;
}

const std::string &Client::getInformation() const {
    return information;
}

double Client::getToPayForKeeping() const {
    return toPayForKeeping;
}

void Client::setName(const std::string &name) {
    Client::name = name;
}

void Client::setSurname(const std::string &surname) {
    Client::surname = surname;
}

void Client::setRented(const std::map<int, int> &rented) {
    Client::rented = rented;
}

void Client::setId(int id) {
    Client::id = id;
}

Client::Client() {}


