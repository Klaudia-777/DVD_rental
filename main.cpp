#include <iostream>
#include "DVD.h"
#include "MovieBase.h"
#include "RentalService.h"
#include "Status.h"
#include "movieGenre.h"

using namespace std;

int main() {

    DVD movie1(inStore, Comedy, "klaudia", 10.0);
    DVD movie2(inStore, Comedy, "radek", 10.0);
    DVD movie3(inStore, Action, "weronika", 10.0);

    cout << movie1.getId() << endl;
    cout << movie2.getId() << endl;
    cout << movie3.getId() << endl;


    RentalService rent;
    rent.movieBase.addToBase(movie1);
    rent.movieBase.addToBase(movie2);
    rent.movieBase.addToBase(movie3);

    rent.filterGenre(Comedy);

    rent.rentDVD(1);

    cout << rent.movieBase.getRentedDVDs().size() << endl;
    cout << rent.movieBase.getBase().size() << endl;

    rent.returnDVD(1);

    cout << rent.movieBase.getRentedDVDs().size() << endl;
    cout << rent.movieBase.getBase().size() << endl;


    return 0;
}