#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "Literature.h"
#include "Book.h"
#include "Journal.h"

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

/*
 * 4. praktiskias darbs - Virtuālās funkcijas. Nodošanas datums - 5.11. Izmainīt trešo praktisko darbu:
 * 1. Noformēt klases
 * 1.1. Bāzes klasi saglabāt failā ar paplašinājumu „.h”. Visas metodes noformēt kā ārējās (outline. Atstāt klasē tikai metožu aprakstus);
 * 1.2. Bāzes klases metožu realizāciju saglabāt failā ar paplašinājumu „.cpp”;
 * 1.3. Kā 1.1., tikai atvasinātai klasei; 1.4. Kā 1.2., tikai atvasinātai klasei.
 * 2.1. Bāzes klases rēķinošo metodi pārveidot par virtuālo;
 * 2.2. Print metodi bāzes klasē pārveidot par virtuālo;
 * 2.3. Pievienojiet nevirtuālo metodi, kas kaut ko izdrukā par bāzes klases elementu.
 * 3. Papildināt programmu ar vēl vienu atvasināto klasi atbilstoši individuālajam uzdevumam;
 * 3.1. Pievienot tai savu atribūtu un atbilstošās set / get metodes;
 * 3.2. Realizēt bāzes klases rēķinošo metodi otrajā atvasinātajā klasē (realizācijai ir jāatšķiras no pirmās atvasinātās klases);
 * 3.3. Pārdefinēt print metodi abās atvasinātajās klasēs, lai tā drukātu gan bāzes, gan atvasinātās klases atribūtus 3.3. Pārdefinējiet bāzes klases nevirtuālo metodi, lai tā drukātu atvasinātās klases tekstu.
 * 3.4. Pievienot pārslogotus konstruktorus.
 * 4. Main funkcijā izveidot masīvu no norādēm uz bāzes klases elementiem;
 * 4.1. for ciklā aizpildīt masīvu no 6 elementiem, izveidojot bāzes un atvasināto klašu objektus pēc lietotāja izvēles (lietotājs izvēlās gan objekta tipu, gan konstruktora variantu - iepējamo izvēli noformēt kā izvēlni: (nospiediet 1, ja vēlaties izveidot bāzes klases objektu ar pirmo konstruktoru, nospiediet 2, ja vēlaties ...).
 * 4.1.1. Izveidojot objektu ar konstruktoru ar parametriem, vismaz divu parametru vērtības pirms tam ir jāļauj ievadīt lietotājam. 4.2. Tālāk organizēt jaunu for ciklu (tātad, nebūs zināms, kura objekta variantu lietotājs ir izveidojis) kurā apstrādāt katru masīva elementu, izsaucot
 * 4.2.1. rēķinošo metodi;
 * 4.2.2. print metodi;
 * 4.2.3. nevirtuālo metodi.
 * 4.3. Pēdējā (trešajā) for ciklā atbrīvot atmiņu no visiem objektiem.
 * */

/*
 * 5. praktiskais darbs: Pilnīgi pabeigtajā 4. programmā veikt šādas izmaiņas:
 * 1. Bāzes klases rēķinošo virtuālo metodi pārveidot par tīri virtuālo;
 * 2. main funkcijā:
 * 2.1. pirmajā ciklā līdz ar to vairs nepiedāvāt izveidot bāzes klases objektu.
 * 2.2. pirms atmiņas atbrīvošanas organizēt jaunu for ciklu, kurā, izmantojot dinamisko tipu pārveidošanu un bāzes klases norādi, izsaukt visas atvasināto klašu metodes (arī unikālās) (ko āgrāk nevarēja izsaukt, jo bāzes klases norāde to nemācēja).
 */

std::string ResponseToLower(std::string text);
int askForPd();
void printLine();

int Literature::litCount = 0;

int main() {
  int calcYear;
  float pd, ry;
  std::string response, gen, typ;


  std::cout << "Would you like to add a new source of literature? [Y/n]" << std::endl;
  std::cin >> response;
  response = ResponseToLower(response);
  if (response == "y") {
    std::string genre, type;
    pd = askForPd();
    std::cout << "\nEnter the genre of the source of literature: ";
    std::cin >> genre;
    std::cout << "\nEnter the type of the source of literature: ";
    std::cin >> type;

    Literature *lit1 = new Literature(type,pd,genre);
    printLine();
    lit1->print();
    printLine();
  }

  std::cout << "Would you like to add a new book [Y/n] ";
  std::cin >> response;
  response = ResponseToLower(response);
  if (response == "y") {
    float price;
    std::cout << "Enter the type of the book: " << std::endl;
    std::cin >> typ;
    std::cout << "Enter the genre of the book: " << std::endl;
    std::cin >> gen;
    std::cout << "Enter the price of the book: ";
    std::cin >> price;
    Book *book1 = new Book(price, typ, gen);
    book1->setType(typ);
    book1->setGenre(gen);
    printLine();
    book1->print();
    printLine();
  }

  Literature *lit = new Literature;


  lit->setGenre("Action");
  lit->setType("Book");
  lit->setPageDensity(1);
  lit->setReleaseYear(112);



  gen = lit->getGenre();
  typ = lit->getType();
  pd = lit->getPageDensity();
  ry = lit->getReleaseYear();
  calcYear = lit->calculateAge();

  printLine();
  lit->print();
  printLine();


  Book *book = new Book(4.99, "Cool", "Genre");
  book->setReleaseYear(2000);
  book->setPrice(5);
  book->setPageDensity(2);

  gen = book->getGenre();
  typ = book->getType();
  pd = book->getPageDensity();
  ry = book->getReleaseYear();
  calcYear = book->calculateAge(2009);

  printLine();
  book->print();
  printLine();

  Literature *elements[6];
  std::string title;
  for (auto & element : elements) {
    int answer;
    std::cout << "What object would you like to create? [1: Book, 2: Journal, 3: Literature]" << std::endl;
    std::cin >> answer;
    switch (answer) {
      case 1: {
        float price;
        std::cout << "Enter the type of the book: " << std::endl;
        std::cin >> typ;
        std::cout << "Enter the genre of the book: " << std::endl;
        std::cin >> gen;
        std::cout << "Enter the price of the book: ";
        std::cin >> price;
        element = new Book(price, typ, gen);
        break;
      }
      case 2: {
        std::cout << "What kind of constructor would you like to use? [1: Default with no additional parameters. 2: With a title parameter.]" << std::endl;
        int secondAnswer;
        std::cin >> secondAnswer;
        switch (secondAnswer) {
          case 1: {
            std::cout << "Enter the type of the journal: " << std::endl;
            std::cin >> typ;
            std::cout << "Enter the genre of the journal: " << std::endl;
            std::cin >> gen;
            element = new Journal(typ, gen);
            break;
          }
          case 2: {
            std::cout << "Enter the type of the journal: " << std::endl;
            std::cin >> typ;
            std::cout << "Enter the genre of the journal: " << std::endl;
            std::cin >> gen;
            std::cout << "Enter the title of the journal: " << std::endl;
            std::cin >> title;
            element = new Journal(typ, gen, title);
            break;
          }
          default: {
            return 0;
            break;
          }
        }
        break;
      }
      case 3: {
        std::cout << "What kind of constructor would you like to use? [1: Default with no additional parameters. 2: With a title parameter.]" << std::endl;
        int secondAnswer;
        std::cin >> secondAnswer;
        switch (secondAnswer) {
          case 1: {
            element = new Literature();
            break;
          }
          case 2: {
            std::cout << "Enter the type of the source literature: " << std::endl;
            std::cin >> typ;
            std::cout << "Enter the genre of the source literature: " << std::endl;
            std::cin >> gen;

            element = new Literature(typ, gen);
            break;
          }
          default:{
            return 0;
            break;
          }
        }
        break;
      }
      default: {
        return 0;
      }
    }
  }

  for (auto & element : elements) {
    element->print();
    element->calculateAge();
    element->setReleaseYear(2000);
  }

  for (auto & element : elements) {
    delete element;
  }


  return 0;
}

std::string ResponseToLower(std::string text) {
   std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  return text;
}
int askForPd() {
  int pd;
  std::cout << "Enter the page density of the source of literature: ";
  std::cin >> pd;
  if(pd < 0) {
    std::cin.clear();
    askForPd();
  }
  return pd;
}
void printLine() {
  std::cout << "--------------------------------------------" << std::endl;
}