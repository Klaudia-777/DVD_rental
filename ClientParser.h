/*
 * This class is respocsible for conversion of elements
 * stored in ClientBase. It turns objects of Client class
 * into strings in json's-like form and opposite.
 */

#ifndef DVD_RENTAL_CLIENTPARSER_H
#define DVD_RENTAL_CLIENTPARSER_H


#include <string>
#include "Client.h"

class ClientParser {
public:
    std::string toJson(Client client);
    Client fromJson(std::string json);

};


#endif //DVD_RENTAL_CLIENTPARSER_H
