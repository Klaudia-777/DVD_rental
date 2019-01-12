/*
 * This class is respocsible for conversion of elements
 * stored in MovieBase. It turns objects of DVD class
 * into strings in json's-like form and opposite.
 */

#ifndef DVD_RENTAL_DVDPARSER_H
#define DVD_RENTAL_DVDPARSER_H


#include <string>
#include "DVD.h"

class DVDParser {
public:
    std::string toJson(DVD dvd);
    DVD fromJson(std::string json);
};



#endif //DVD_RENTAL_DVDPARSER_H
