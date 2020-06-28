#include <iostream>
#include "library.cpp"
#include "registrar.cpp"

using namespace std;

void issueBook(int bookId, int studentId, Library *library, Registrar *registry);
void returnBook(int bookId, int studentId, Library *library, Registrar *registry);

int main() {
  // Create library, add books to library
  cout << "Adding books to library" << endl;
  Library lib;
  lib.addbook(100, "Harry Potter: Philosopher's Stone", "J.K. Rowling", "Fantasy", 3, 24, 10);
  lib.addbook(200, "Wealth of Nations", "Adam Smith", "Non-fiction", 1, 40, 7);
  lib.addbook(300, "Rich Dad Poor Dad", "Robert T. Kiyosaki", "Non-fiction", 2, 15, 8);
  lib.addbook(400, "The Pragmatic Programmer", "Andrew Hunt", "Non-fiction", 5, 8, 8);
  lib.addbook(500, "Data Structures and Problem Solving using C++", "Mark Allen Weiss", "Non-fiction", 1, 120, 8);
  
  // Create registrar, add students to registrar
  cout << "Adding students to registrar" << endl;
  Registrar reg;
  reg.addStudent(1, "Jane Doe", "jane.doe@gmail.com");
  reg.addStudent(2, "John Smith", "john.smith@gmail.com");
  reg.addStudent(3, "Joseph Joel", "joseph.joel@gmail.com");
  
  // Remove a book from the library and credit it to a student's account in the registry
  cout << "Issuing books to students" << endl;
  issueBook(200, 3, &lib, &reg);
  issueBook(400, 3, &lib, &reg);
  issueBook(400, 2, &lib, &reg);
  
  // View the change in quantity of a book in the library before and after its return
  cout << "Book properties in library before return" << endl;
  lib.viewbook(400);
  returnBook(400, 3, &lib, &reg);
  cout << "Book properties in library after return" << endl;
  lib.viewbook(400);
  
  // Use string matches to view a book
  cout << "Searching library with term 'rich dad'" << endl;
  lib.searchbook("rich dad");
  return 0;
}

/*
  Orchestrates interaction between library and registrar.
  Removes a book from the library to the inventory of a student
*/
void issueBook(int bookId, int studentId, Library *library, Registrar *registry) {
  Book book = library -> checkoutbook(bookId);
  Student student = registry -> getStudent(studentId);
  student.checkedBooks.push_back(book);
  registry -> updateStudent(studentId, student);
}

/*
  Orchestrates interaction between library and registrar.
  Removes a book from the the inventory of a student back to the library
*/
void returnBook(int bookId, int studentId, Library *library, Registrar *registry) {
  Student student = registry -> getStudent(studentId);
  int i = 0;
  for (auto const& book: student.checkedBooks) {
    if (book.id == bookId) {
      cout << book.name << endl;
      library -> checkinbook(bookId);
      student.checkedBooks.erase(student.checkedBooks.begin() + i);
      registry -> updateStudent(studentId, student);
      break;
    }
    i++;
  }
}