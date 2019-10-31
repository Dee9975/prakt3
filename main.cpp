#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "Literature.h"
#include "Book.h"

//Matiss Kalnins P2-4

//1.1. Izveidot sava individuālā varianta bāzes klasi ar trīs atribūtiem: publisko, aizsargāto un privāto (vismaz vienu - skaitlisku).
//1.2. Pievienojiet statisko atribūtu, kas atcerēsies objektu skaitu.
//1.3. Izveidot divus konstruktorus (vienu – bez parametriem), kas inicializē klases atribūtus un destruktoru, kas paziņo par objekta iznīcināšanu.
//1.4. Izveidojiet set un get metodes privātajam un aizsargātajam atribūtiem.
//1.5. Izveidot print metodi
//1.6. Izveidot kādu savu metodi, kas veic aprēķinus (ja iespējams, tad ar klases atribūtiem) un atgriež vērtību.
//
//2.1. Izveidot atvasināto klasi, kura publiski manto bāzes klasei un papildina bāzes klasi ar vienu privātu atrubūtu.
//2.2. Pievienot atbilstošās set un get metodes.
//2.3. Izveidot divus konstruktorus, kas inicializē jaunos klases atribūtus un destruktoru. Vienam no tiem atklātā veidā jāizsauc bāzes klases konstruktors, nododot tam parametrus.
//2.4. Pārdefinējiet bāzes klases metodi print, lai tā izdrukātu visu atribūtu vērtības.
//2.5. Pārdefinējiet metodi, kas rēķina (lai rēķina kaut kā citādi).
//
//3.1. Nodemostrēt visu metožu izsaukumu, izveidojot gan bāzes klases, gan atvasinātās klases objektus (izveidot dianmiski).
//3.1.2. Tā kā jāizsauc visas metodes (arī visi konstruktori), tad jāizveido četri(!!!) objekti.
//3.2. Vismaz vienam no objektiem visu metodēm nepieciešamo parametru ievadi organizēt main funkcijā (neaizmirsiet par kļūdainās ievades pārbaudi)!

int Literature::litCount = 0;
std::string ResponseToLower(std::string text);

int main() {
  std::string response;
  Literature *lit = new Literature;
  Book *book = new Book(4.99);
  std::cout << "Would you like to add a new source of literature? [Y/n]" << std::endl;
  std::cin >> response;
  response = ResponseToLower(response);
  if (response == "y") {
    std::string genre, type;
    float pd;
    std::cout << "Enter the page density"
                 " of the source of literature: ";
    std::cin >> pd;
    std::cout << "\nEnter the genre of the source of literature: ";
    std::cin >> genre;
    std::cout << "\nEnter the type of the source of literature: ";
    std::cin >> type;

    Literature *lit1 = new Literature(type,pd,genre);

    std::cout << "Would you like to add a new book [Y/n] ";
    std::cin >> response;
    response = ResponseToLower(response);
    if (response == "y") {
      float price;
      std::cout << "Enter the price of the book";
      std::cin >> price;
      Book *book1 = new Book(price);
    }

  }
  return 0;
}

std::string ResponseToLower(std::string text) {
   std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  return text;
}