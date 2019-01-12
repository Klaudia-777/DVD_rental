#include "DVD.h"
#include "MovieBase.h"


DVD::DVD(Status status, Genre genre, std::string title, int price,int id) {
    this->status = status;
    this->genre = genre;
    this->title = title;
    this->price = price;
    this->id=id;
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

int DVD::getPrice() {
    return price;
}

int DVD::getId() const {
    return id;
}

void DVD::setPrice(int price) {
    DVD::price = price;
}

bool DVD::operator==(const DVD &rhs) const {
    return status == rhs.status &&
           genre == rhs.genre &&
           title == rhs.title &&
           price == rhs.price;
}

DVD::DVD() {}

void DVD::setGenre(Genre genre) {
    DVD::genre = genre;
}

void DVD::setTitle(const std::string &title) {
    DVD::title = title;
}

void DVD::setId(int id) {
    DVD::id = id;
}
