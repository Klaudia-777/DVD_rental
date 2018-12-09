#include <iostream>
#include "DVD.h"
#include "MovieBase.h"
#include "RentalService.h"
#include "Status.h"
#include "movieGenre.h"

#include <thread>
#include <zconf.h>


using namespace std;


void myThread(RentalService* rent)
{   while(true) {
        rent->countTimeAndPayments();
       sleep(1);
    }
}

int main() {
    RentalService rent;

    thread t1(myThread,&rent);

    DVD movie1(inStore, Comedy, "Mamma Mia", 10.0);
    DVD movie2(inStore, Comedy, "Deadpool", 10.0);
    DVD movie3(inStore, Action, "Spectre", 10.0);

    cout << movie1.getId() << endl;
    cout << movie2.getId() << endl;
    cout << movie3.getId() << endl;


    rent.getMovieBase().addToBase(movie1);
    rent.getMovieBase().addToBase(movie2);
    rent.getMovieBase().addToBase(movie3);


    rent.filterGenre(Comedy);

    rent.rentDVD(1);
  //  rent.rentDVD(1);
  //  rent.returnDVD(1);

    cout << rent.getMovieBase().findByStatus(booked).size() << endl;
    cout << rent.getMovieBase().findByStatus(inStore).size() << endl;

   // rent.returnDVD(1);

    cout << rent.getMovieBase().findByStatus(booked).size() << endl;
    cout << rent.getMovieBase().findByStatus(inStore).size() << endl;
   // rent.countTimeAndPayments();
    while (true){

    }
    return 0;
}