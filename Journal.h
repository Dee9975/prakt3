//
// Created by matiss on 25.11.19.
//

#ifndef PRAKT_3_JOURNAL_H
#define PRAKT_3_JOURNAL_H

#include <string>
#include "Literature.h"
#include <iostream>
#include <ctime>

class Journal : public Literature {
private:
  std::string title;
public:
  Journal(std::string type, std::string genre);
  Journal(std::string type, std::string genre, std::string title);
  const std::string &getTitle() const;

  void setTitle(const std::string &title);
  void print() override;
  int calculateAge() override;
};


#endif //PRAKT_3_JOURNAL_H
