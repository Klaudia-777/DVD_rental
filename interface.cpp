//
// Created by klaudia on 09.12.18.
//

#include "interface.h"
#include "DVD.h"
#include "MovieBase.h"
#include "RentalService.h"
#include "Status.h"
#include "movieGenre.h"
#include <cstdlib>
#include <iostream>

using namespace std;


Genre stringToGenre(string genre) {
    if (genre == "Action") return Action;
    else if (genre == "Adventure") return Adventure;
    else if (genre == "Comedy") return Comedy;
    else if (genre == "Crime") return Crime;
    else if (genre == "Drama") return Drama;
    else if (genre == "Fantasy") return Fantasy;
    else if (genre == "Historical") return Historical;  // -------------> itd dopisac wszystko z movieGenre.h
}


void addNewDVDToBase(RentalService &rent) {
    string genre, title;
    int price;
    cout << "Add new DVD to base." << endl;
    cout << "Enter genre:" << endl;
    cin >> genre;
    cout << "Enter title:" << endl;
    cin >> title;
    cout << "Enter price:" << endl;
    cin >> price;
    DVD movie(inStore, stringToGenre(genre), title, price);
    rent.getMovieBase().addToBase(movie);
}

void removeDVDFromBase(RentalService &rent) {
    int DVDsId;
    cout << "Remove DVD from base." << endl;
    cout << "Enter id:" << endl;
    cin >> DVDsId;
    rent.getMovieBase().removeFromBase(DVDsId);
}

void addNewClient(RentalService &rent) {
    cout << "Add new client." << endl;
    rent.getClientBase().newClient();
}

void removeClient(RentalService &rent) {
    int id;
    cout << "Remove client from base." << endl;
    cout << "Enter clients id:" << endl;
    cin >> id;
    rent.getClientBase().removeFromBase(id);
}

void rentDVD(RentalService &rent) {
    int DVDsId;
    cout << "Rent a DVD." << endl;
    cout << "Enter DVD's id:" << endl;
    cin >> DVDsId;
    rent.rentDVD(DVDsId);
}

void returnDVD(RentalService &rent) {
    int DVDsId;
    cout << "Return a DVD." << endl;
    cout << "Enter DVD's id:" << endl;
    cin >> DVDsId;
    rent.returnDVD(DVDsId);
}

void findByGenre(RentalService &rent) {
    string genre;
    cout << "Find by genre." << endl;
    cout << "Enter a genre:" << endl;
    cin >> genre;
    rent.filterGenre(stringToGenre(genre));
}

void displayAvailableDVDs(RentalService &rent) {
    cout << "Available DVDs:" << endl;
    rent.display(1);
}

void displayRentedDVDs(RentalService &rent) {
    cout << "Rented DVDs:" << endl;
    rent.display(0);
}

void displayClientsData(RentalService &rent) {
    int id;
    cout << "Display client's data." << endl;
    cout << "Enter client's id:" << endl;
    cin >> id;
    rent.getClientBase().showClientsData(id);
}