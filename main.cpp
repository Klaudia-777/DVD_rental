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
    rent.getMovieBase().addToBase(movie1);
    rent.getMovieBase().addToBase(movie2);
    rent.getMovieBase().addToBase(movie3);

    rent.filterGenre(Comedy);

    rent.rentDVD(1);

    cout << rent.getMovieBase().findByStatus(booked).size() << endl;
    cout << rent.getMovieBase().findByStatus(inStore).size() << endl;

    rent.returnDVD(1);

    cout << rent.getMovieBase().findByStatus(booked).size() << endl;
    cout << rent.getMovieBase().findByStatus(inStore).size() << endl;

    return 0;
}