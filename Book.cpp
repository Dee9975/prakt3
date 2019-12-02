//
// Created by matiss on 08.10.19.
//

#include "Book.h"
#include <ctime>
#include <iostream>

Book::Book(float price, std::string type, std::string genre): Literature(type, genre) {
    this->price = price;
    //this->type = type;
    //this->genre = genre;
    setPageDensity(1);
}

void Book::setPrice(float price) {
    this->price = price;
}

float Book::getPrice() {
    return this->price;
}

int Book::calculateAge(int remakeYear) {
  int year;
  if (this->releaseYear == 0000) {
    return 0;
  }
  time_t now = time(0);
  tm *ltm = localtime(&now);
  year = 1900 + ltm->tm_year;

  return (year - remakeYear);
}

void Book::print() {
  std::cout << "Literature info: " << "\nPrice: " << this->price << "\nType: " << this->type << "\nGenre: " << this->genre << "\nLiterature Count: " << litCount << std::endl;
}