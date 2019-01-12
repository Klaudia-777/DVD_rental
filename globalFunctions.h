/*
 * In this file there are metods converting string
 * to genre and the other way. They are often used
 * in the project.
 */

#include "movieGenre.h"
#include "Status.h"

#ifndef DVD_RENTAL_GLOBALFUNCTIONS_H
#define DVD_RENTAL_GLOBALFUNCTIONS_H

#endif //DVD_RENTAL_GLOBALFUNCTIONS_H


Genre stringToGenre(std::string genre);
std::string genreToString(Genre genre);
Status stringToStatus(std::string status);
std::string statusToString(Status status);