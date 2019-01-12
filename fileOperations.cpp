#include "fileOperations.h"
#include <fstream>
#include <iostream>

using namespace std;

void writeToFile(RentalService &rentalService, DVDParser &dvdParser, ClientParser &clientParser) {
    std::ofstream ofs;
    ofs.open("/home/klaudia/Pulpit/DVD_rental (kopia)/DVDs.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    ofstream myfile("/home/klaudia/Pulpit/DVD_rental (kopia)/DVDs.txt", ios_base::in | ios_base::app);
    if (!myfile)
        cout << "Nie można otworzyć pliku!" << endl;
    if (!rentalService.getMovieBase().getBase().empty()) {
        for (const pair<int, DVD> &it : rentalService.getMovieBase().getBase()) {
            myfile << dvdParser.toJson(it.second);
        }
    }
    cout << "Tekst zapisany w pliku" << endl;
    myfile.close();


    std::ofstream ofs1;
    ofs1.open("/home/klaudia/Pulpit/DVD_rental (kopia)/Clients.txt", std::ofstream::out | std::ofstream::trunc);
    ofs1.close();

    ofstream myfileClients("/home/klaudia/Pulpit/DVD_rental (kopia)/Clients.txt", ios_base::in | ios_base::app);
    if (!myfileClients)
        cout << "Nie można otworzyć pliku!" << endl;
    if (!rentalService.getClientBase().getBase().empty()) {
        for (const pair<int, Client> &it : rentalService.getClientBase().getBase()) {
            myfileClients << clientParser.toJson(it.second);
        }
    }
    cout << "Tekst zapisany w pliku" << endl;
    myfileClients.close();
}

void readFromFile(RentalService &rentalService, DVDParser &dvdParser, ClientParser &clientParser) {
    std::ifstream input("/home/klaudia/Pulpit/DVD_rental (kopia)/DVDs.txt");
    if (input.is_open()) {
        std::string line;
        while (getline(input, line)) {
            rentalService.getMovieBase().addToBase(dvdParser.fromJson(line));
        }
        input.close();
    }
    std::ifstream inputClients("/home/klaudia/Pulpit/DVD_rental (kopia)/Clients.txt");
    if (inputClients.is_open()) {
        std::string lineClient;
        while (getline(inputClients, lineClient)) {
            rentalService.getClientBase().addToBase(clientParser.fromJson(lineClient));
        }
        inputClients.close();
    }
}