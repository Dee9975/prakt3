//
// Created by matiss on 08.10.19.
//

#ifndef PRAKT_3_LITERATURE_H
#define PRAKT_3_LITERATURE_H

#include <string>

class Literature {
private:
    int pageDensity{};
protected:
    std::string genre;
    std::string type;
    float releaseYear;
public:
    static int litCount;

    Literature();
    Literature(std::string type, std::string genre);
    Literature(std::string type, float pageDensity, std::string genre);
    void setType(std::string type);
    void setGenre(std::string g);
    void setPageDensity(float pd);
    void setReleaseYear(float year);
    float getReleaseYear();
    float getPageDensity();
    std::string getType();
    std::string getGenre();
    void print();
    int calculateAge();
    int calculateAge(int remakeYear);
    ~Literature();
};


#endif //PRAKT_3_LITERATURE_H
