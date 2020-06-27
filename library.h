#ifndef __library_h_
#define __library_h_
#endif

#include <string>
#include <map>
#include "book.h"

using namespace std;

class Library {
  private:
    map<int, Book> booksmap;
  public:
    void addbook(int idIn, string nameIn, string authorIn, string categoryIn, int quantityIn, int priceIn, int rackNoIn);
    void deletebook(int id);
    void searchbook(string name);
    void viewbook(int id);
    Book checkoutbook(int id);
    void checkinbook(int id);
};