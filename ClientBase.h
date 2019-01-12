/*
 * This class implements basic operations on clients database.
 */

#ifndef DVD_RENTAL_CLIENTBASE_H
#define DVD_RENTAL_CLIENTBASE_H

#include <map>
#include "Client.h"
#include "MovieBase.h"

class ClientBase {
private:
    std::map<int, Client> base;         // database of clients implemented as a map where key - client's id and value - corresponding Client object                                                                            //
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
