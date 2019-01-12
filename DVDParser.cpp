#include "DVDParser.h"
#include "globalFunctions.h"
#include <regex>
#include <iostream>


std::string DVDParser::toJson(DVD dvd) {
    std::string json;
    json = "{status:" + statusToString(dvd.getStatus()) + ","
           + "genre:" + genreToString(dvd.getGenre()) + ","
           + "title:" + dvd.getTitle() + ","
           + "price:"+std::to_string(dvd.getPrice()) + ","
            + "id:"+std::to_string(dvd.getId()) + ",}\n";

    return json;
}

DVD DVDParser::fromJson(std::string json) {
    DVD dvd;
    std::regex wzorzec( ":\\w*," );
    auto words_begin =
            std::sregex_iterator(json.begin(), json.end(), wzorzec);
    auto words_end = std::sregex_iterator();
    int j = 0;
    for (std::sregex_iterator i = words_begin; i != words_end; i++) {
        std::smatch match = *i;
        std::string match_str = match.str().substr(1,match.str().length()-2);
        if(j==0) dvd.setStatus(stringToStatus(match_str));
        else if(j==1) dvd.setGenre(stringToGenre(match_str));
        else if(j==2) dvd.setTitle(match_str);
        else if(j==3) dvd.setPrice(atoi(match_str.c_str()));
        else dvd.setId(atoi(match_str.c_str()));
        j++;
//std::cout << match_str.substr(1,match_str.length()-2) << std::endl;
//        if(j==0) dvd.setStatus(booked);
//        else if(j==1) dvd.setGenre(Comedy);
//        else if(j==2) dvd.setTitle("lol");
//        else if(j==3) dvd.setPrice(12);
//        else dvd.setId(0);
//        j++;
    }
    return dvd;
}
