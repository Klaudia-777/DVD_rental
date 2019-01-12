#include "globalFunctions.h"

Genre stringToGenre(std::string genre) {
    if (genre == "Action") return Action;
    else if (genre == "Adventure") return Adventure;
    else if (genre == "Comedy") return Comedy;
    else if (genre == "Crime") return Crime;
    else if (genre == "Drama") return Drama;
    else if (genre == "Fantasy") return Fantasy;
    else if (genre == "Historical") return Historical;
    else if (genre == "Horror") return Horror;
    else if (genre == "Political") return Political;
    else if (genre == "Romance") return Romance;
    else if (genre == "Satire") return  Satire;
    else if (genre == "Science_fiction") return Science_fiction;
    else if (genre == "Thriller") return Thriller;
    else if (genre == "Western") return Western;
}

std::string genreToString(Genre genre) {
    if (genre == Action) return "Action";
    else if (genre == Adventure) return "Adventure";
    else if (genre == Comedy) return "Comedy";
    else if (genre == Crime) return "Crime";
    else if (genre == Drama) return "Drama";
    else if (genre == Fantasy) return "Fantasy";
    else if (genre == Historical) return "Historical";
    else if (genre == Horror) return "Horror";
    else if (genre == Political) return "Political";
    else if (genre == Romance) return "Romance";
    else if (genre == Satire) return "Satire";
    else if (genre == Science_fiction) return "Science_fiction";
    else if (genre == Thriller) return "Thriller";
    else if (genre == Western) return "Western";
}

Status stringToStatus(std::string status) {
    if (status == "inStore") return inStore;
    else if (status == "booked") return booked;
}

std::string statusToString(Status status){
    if(status==inStore) return "inStore";
    else if (status==booked) return "booked";
}