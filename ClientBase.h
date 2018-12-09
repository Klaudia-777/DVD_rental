//
// Created by klaudia on 05.12.18.
//

#ifndef DVD_RENTAL_CLIENTBASE_H
#define DVD_RENTAL_CLIENTBASE_H


#include <map>
#include "Client.h"
#include "MovieBase.h"

class ClientBase {
private:
    std::map<int, Client> base;    // ----------int -client's id
public:

    ClientBase();

    void addToBase(Client object);

    void removeFromBase(int id);

    void newClient();

    void rentDVD(int DVDId);

    bool returnDVD(int DVDId);

    void showClientsData(int id);

    Client &findById(int id);

    std::map<int, Client> &getBase();


};


#endif //DVD_RENTAL_CLIENTBASE_H
