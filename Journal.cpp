//
// Created by matiss on 25.11.19.
//

#include "Journal.h"

const std::string &Journal::getTitle() const {
  return title;
}

void Journal::setTitle(const std::string &title) {
  Journal::title = title;
}

int Journal::calculateAge() {
  int year;
  if (this->releaseYear == 0000) {
    return 0;
  }
  time_t now = time(0);
  tm *ltm = localtime(&now);
  year = 1900 + ltm->tm_year;

  if ((year - this->releaseYear) > 1) {
    return -1;
  }

  return year - this->releaseYear;
}

void Journal::print() {
  std::cout << "Type: " << this->type << "\n";
  std::cout << "Genre: " << this->genre << "\n";
  std::cout << "Title: " << this->title << std::endl;
  std::cout << "Literature Count: " << Journal::litCount << "\n";
}

Journal::Journal(std::string type, std::string genre) : Literature(type, genre) {
  setPageDensity(1);
}

Journal::Journal(std::string type, std::string genre, std::string tit) : Literature(type, genre) {
  this->title = tit;
}