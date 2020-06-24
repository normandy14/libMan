#include <string>
#include <map>
#include "library.h"
#include "functions.cpp"

using namespace std;

void Library::addbook(int idIn, string nameIn, string authorIn, string categoryIn, int quantityIn, int priceIn, int rackNoIn) {
  Book book;
  book.id = idIn;
  book.name = nameIn;
  book.author = authorIn;
  book.category = categoryIn;
  book.quantity = quantityIn;
  book.price = priceIn;
  book.rackNo = rackNoIn;
  booksmap.insert({book.id, book});
}

void Library::deletebook(int id) {
  booksmap.erase(id);
}

void Library::searchbook(string name) {
  string title;
  for (map<int,Book>::iterator it = booksmap.begin(); it != booksmap.end(); ++it) {
    title = it -> second.name;
    if (tokenSortRatio(name, title) > 0.40) {
      viewbook(it -> second.id);
    }
  }
}

void Library::viewbook(int id) {
  Book book = booksmap[id];
  cout << "id: " << book.id << endl;
  cout << "name: " << book.name << endl;
  cout << "author: " << book.author << endl;
  cout << "category: " << book.category << endl;
  cout << "quantity: " << book.quantity << endl;
  cout << "price: " << book.price << endl;
  cout << "rackNo: " << book.rackNo << endl;
}

Book Library::checkoutbook(int id) {
  if (booksmap[id].quantity == 0) {
    throw -1;
  }
  Book book = booksmap[id];
  book.quantity -= 1;
  booksmap[id] = book;
  return booksmap[id];
}

void Library::checkinbook(int id) {
  Book book = booksmap[id];
  book.quantity += 1;
  booksmap[id] = book;
}