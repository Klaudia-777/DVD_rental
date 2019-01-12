#include <regex>
#include <iostream>
#include "ClientParser.h"

std::string ClientParser::toJson(Client client) {
    std::string json;
    json = "{name:" + client.getName() + ","
           + "surname:" + client.getSurname() + ","
           + "information:" + client.getInformation() + ",";
    json += "id:"+std::to_string(client.getId()) + ","
            + "toPayForKeeping:"+std::to_string(client.getToPayForKeeping()) + ",";
    json+= "maps :{";
    for (auto it:client.getRented()) {
        json += std::to_string(it.first) + ":" + std::to_string(it.second) + "_ ";
    }

    json+="}}\n";

    return json;
}

Client ClientParser::fromJson(std::string json) {
    Client client;
    std::regex wzorzec( ":(\\w*)," );
    std::regex wzorzecMap("(\\d+):(\\d+)_" );
    auto words_begin =
            std::sregex_iterator(json.begin(), json.end(), wzorzec);
    auto words_end = std::sregex_iterator();
    int j = 0;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str().substr(1,match.str().length()-2);
        if(j==0) client.setName(match_str);
        if(j==1) client.setSurname(match_str);
        if(j==2) client.setInformation(match_str);
        if(j==3) client.setId(atoi(match_str.c_str()));
        if(j==4) client.setToPayForKeeping(std::stod(match_str));
        j++;
    }
    auto words_beginMap =
            std::sregex_iterator(json.begin(), json.end(), wzorzecMap);
    auto words_endMap = std::sregex_iterator();
    std::map<int,int> rented;
    for (std::sregex_iterator i = words_beginMap; i != words_endMap; ++i) {
        std::smatch match1 = *i;
        std::string match_str1 = match1.str();
        int key = atoi(match1[1].str().c_str());
        int value = stoi(match1[2].str());
        rented.emplace(std::make_pair(key,value));
    }
    client.setRented(rented);
    return client;
}
