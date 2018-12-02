//
// Created by klaudia on 01.12.18.
//

#include "DVD.h"

static int incrementer=0;

DVD::DVD(Status status, Genre genre, std::string title, double price) {
    this->status = status;
    this->genre = genre;
    this->title = title;
    this->price = price;
    id = incrementer++;
}

Status DVD::getStatus() {
    return status;
}

void DVD::setStatus(Status status) {
    DVD::status = status;
}

Genre DVD::getGenre() const {
    return genre;
}

std::string DVD::getTitle() {
    return title;
}

double DVD::getPrice() {
    return price;
}

int DVD::getId() const {
    return id;
}

void DVD::setPrice(double price) {
    DVD::price = price;
}

bool DVD::operator==(const DVD &rhs) const {
    return status == rhs.status &&
           genre == rhs.genre &&
           title == rhs.title &&
           price == rhs.price;
}

//void DVD::setIncrementer(int incrementer) {
//    DVD::incrementer = incrementer;
//}
