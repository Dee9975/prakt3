//
// Created by matiss on 08.10.19.
//

//

#include <iostream>
#include "Literature.h"
#include <ctime>

Literature::Literature() {
    this->type = "None";
    this->genre = "None";
    this->pageDensity = 1; // 1: 100 - 200 lpp 2: 200 - 300 lpp 3:  > 300 lpp
    litCount++;
}
Literature::Literature(std::string type, int pageDensity, std::string genre) {
    this->type = type;
    this->pageDensity = pageDensity;
    this->genre = genre;
    this->releaseYear = 0000;
    litCount++;
}
Literature::Literature(std::string type, std::string genre) {
    this->type = type;
    this->genre = genre;
    this->releaseYear = 0000;
    litCount++;
}
std::string Literature::getGenre() {
    return this->genre;
}
std::string Literature::getType() {
    return this->type;
}
float Literature::getPageDensity() {
    return this->pageDensity;
}
void Literature::setPageDensity(float pd) {
    this->pageDensity = pd;
}
void Literature::print() {
    std::cout << "Type: " << this->type << "\n";
    std::cout << "Genre: " << this->genre << "\n";
    std::cout << "Page Density: " << this->pageDensity << "\n";
    std::cout << "Literature Count: " << this->litCount << "\n";
}

void Literature::setType(std::string t) {
    this->type = t;
}

void Literature::setGenre(std::string g) {
    this->genre = g;
}

float Literature::getReleaseYear() {
  return this->releaseYear;
}

void Literature::setReleaseYear(float year) {
  this->releaseYear = year;
}

int Literature::calculateAge() {
  if(this->releaseYear == 0000) {
    return 0;
  }
  int year;
  time_t now = time(0);
  tm *ltm = localtime(&now);
  year = 1900 + ltm->tm_year;

  return year - this->releaseYear;
}

Literature::~Literature() {
    std::cout << "A source of literature has been destroyed" << std::endl;
    litCount--;
}

int Literature::calculateAge(int remakeYear) {
  return 0;
}
