//
// Created by klaudia on 05.12.18.
//

#include <iostream>
#include "ClientBase.h"
#include "MovieBase.h"

ClientBase::ClientBase() {

}

void ClientBase::addToBase(Client object) {
    base.emplace(object.getId(), object);
}

void ClientBase::removeFromBase(int id) {
    base.erase(id);
}

std::map<int, Client> &ClientBase::getBase() {
    return base;
}

Client &ClientBase::findById(int id) {
    return base.at(id);
}

void ClientBase::newClient() {
    std::cout << "-------~NEW CLIENT~------" << std::endl;
    std::string name, surname;
    std::cout << "Enter client's name:" << std::endl;
    std::cin >> name;
    std::cout << "Enter client's surname:" << std::endl;
    std::cin >> surname;
    Client client(name, surname);
    std::cout << "New client's id: " << client.getId() << std::endl;
    addToBase(client);
}

void ClientBase::rentDVD(int DVDId) {
    bool isNew;
    std::cout << "New client?" << std::endl;           //----------------enter 1 -> new client or 0 -> client already in base
    std::cin >> isNew;
    if (isNew) newClient();
    int id = 0;
    std::cout << "-------~RENT DVD MENU~------" << std::endl;
    std::cout << "Enter client's id:" << std::endl;
    std::cin >> id;
    if (base.find(id) != base.end()) {
        base.at(id).getRented().emplace(std::make_pair(DVDId, 0));
        showClientsData(id);

    } else {
        std::cout << "There's no such client" << std::endl;
        rentDVD(DVDId);
    }

}

bool ClientBase::returnDVD(int DVDId) {
    std::cout << "------~RETURN DVD MENU~-----" << std::endl;
    int id;
    std::cout << "Enter client's id:" << std::endl;
    std::cin >> id;
    if (base.find(id) == base.end()) {
        std::cout << "There's no such client" << std::endl;
        return false;
    } else if (base.find(id) != base.end() &&
               getBase().at(id).getRented().find(DVDId) == getBase().at(id).getRented().end()) {
        std::cout << "This client's rented-DVDs-base has no such DVD." << std::endl;
        return false;
    } else {
        findById(id).getRented().erase(DVDId);
        findById(id).setToPayForKeeping(0);
        findById(id).setInformation(" ");
        std::cout << getBase().at(id) << std::endl;
        return true;
    }
}

void ClientBase::showClientsData(int id) {
    if (base.find(id) != base.end()) std::cout << getBase().at(id) << std::endl;
    else std::cout << "There's no such client." << std::endl;
}


