//
// Created by matiss on 08.10.19.
//

#ifndef PRAKT_3_BOOK_H
#define PRAKT_3_BOOK_H


#include "Literature.h"
#include <string>

class Book : public Literature {
private:
    float price;
public:
    explicit Book(float price, std::string type, std::string genre);
    float getPrice();
    void setPrice(float price);
    void print() override;

    int calculateAge(int remakeYear) override;
};


#endif //PRAKT_3_BOOK_H
