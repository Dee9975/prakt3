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
    Book(float price);
    float getPrice();
    void setPrice(float price);
    void print();
};


#endif //PRAKT_3_BOOK_H
