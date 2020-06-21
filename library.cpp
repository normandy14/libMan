#include <string>
#include <map>
#include "book.cpp"

using namespace std;

class Library {
  private:
    map<int, Book> booksmap;
  public:
    void addbook(int idIn, string nameIn, string authorIn, string categoryIn, int quantityIn, int priceIn, int rackNoIn);
    void deletebook(int id);
    void searchbook(string name);
    void issuebook(int id, int studentId);
    void viewbook(int id);
};

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
  
}

void Library::issuebook(int id, int studentId) {
  
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