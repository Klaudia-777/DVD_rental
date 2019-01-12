#include "InterfaceController.h"
#include "DVD.h"
#include "MovieBase.h"
#include "RentalService.h"
#include "Status.h"
#include "movieGenre.h"
#include "globalFunctions.h"
#include <cstdlib>
#include <iostream>

using namespace std;

InterfaceController::InterfaceController(const RentalService &rent) : rent(rent) {}


void InterfaceController::addNewDVDToBase() {
    string genre, title;
    int price;
    cout << "Add new DVD to base." << endl;
    cout << "Enter genre:" << endl;
    cin >> genre;
    cout << "Enter title:" << endl;
    cin >> title;
    cout << "Enter price:" << endl;
    cin >> price;
    int id;
    if(!rent.getMovieBase().getBase().empty()) id=((rent.getMovieBase().getBase().end())->first);
    else id=0;
    DVD movie(inStore, stringToGenre(genre), title, price,id);
    rent.getMovieBase().addToBase(movie);
}

void InterfaceController::removeDVDFromBase() {
    int DVDsId;
    cout << "Remove DVD from base." << endl;
    cout << "Enter id:" << endl;
    cin >> DVDsId;
    rent.getMovieBase().removeFromBase(DVDsId);
}

void InterfaceController::addNewClient() {
    cout << "Add new client." << endl;
    rent.getClientBase().newClient();
}

void InterfaceController::removeClient() {
    int id;
    cout << "Remove client from base." << endl;
    cout << "Enter clients id:" << endl;
    cin >> id;
    rent.getClientBase().removeFromBase(id);
}

void InterfaceController::rentDVD() {
    int DVDsId;
    cout << "Rent a DVD." << endl;
    cout << "Enter DVD's id:" << endl;
    cin >> DVDsId;
    rent.rentDVD(DVDsId);
}

void InterfaceController::returnDVD() {
    int DVDsId;
    cout << "Return a DVD." << endl;
    cout << "Enter DVD's id:" << endl;
    cin >> DVDsId;
    rent.returnDVD(DVDsId);
}

void InterfaceController::findByGenre() {
    string genre;
    cout << "Find by genre." << endl;
    cout << "Enter a genre:" << endl;
    cin >> genre;
    rent.filterByGenre(stringToGenre(genre));
}

void InterfaceController::displayAvailableDVDs() {
    cout << "Available DVDs:" << endl;
    rent.display(1);
}

void InterfaceController::displayRentedDVDs() {
    cout << "Rented DVDs:" << endl;
    rent.display(0);
}

void InterfaceController::displayClientsData() {
    int id;
    cout << "Display client's data." << endl;
    cout << "Enter client's id:" << endl;
    cin >> id;
    rent.getClientBase().showClientsData(id);
}

RentalService &InterfaceController::getRent() {
    return rent;
}

