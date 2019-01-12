/*
 *  Database with access methods
 *  storing DVDs available in rental.
 */

#ifndef DVD_RENTAL_MOVIEBASE_H
#define DVD_RENTAL_MOVIEBASE_H


#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include "DVD.h"

class MovieBase {

private:
    std::map<int, DVD> base;  // database of movies implemented as map in which
                              // key-unique DVD's id, value- corresponding DVD object
public:

    MovieBase();

    void addToBase(DVD object);

    void removeFromBase(int id);

    std::vector<DVD> findByStatus(Status status);

    std::vector<DVD> findByGenre(Genre genre);

    const std::map<int, DVD> &getBase() const;

    DVD &findById(int id);

};

#endif //DVD_RENTAL_MOVIEBASE_H
