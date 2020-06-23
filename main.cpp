#include <iostream>
#include "library.cpp"
#include "registrar.cpp"

Registrar issueBook(int bookId, int studentId, Library library, Registrar registry);

int main() {
  // Create library, add books to library
  Library lib;
  lib.addbook(100, "Harry Potter: Philosopher's Stone", "J.K. Rowling", "Fantasy", 3, 24, 10);
  lib.addbook(200, "Wealth of Nations", "Adam Smith", "Non-fiction", 1, 40, 7);
  lib.addbook(300, "Rich Dad Poor Dad", "Robert T. Kiyosaki", "Non-fiction", 2, 15, 8);
  lib.addbook(400, "The Pragmatic Programmer", "Andrew Hunt", "Non-fiction", 5, 8, 8);
  lib.addbook(500, "Data Structures and Problem Solving using C++", "Mark Allen Weiss", "Non-fiction", 1, 120, 8);
  
  // Create registrar, add students to registrar
  Registrar reg;
  reg.addStudent(1, "Jane Doe", "jane.doe@gmail.com");
  reg.addStudent(2, "John Smith", "john.smith@gmail.com");
  reg.addStudent(3, "Joseph Joel", "joseph.joel@gmail.com");
  
  reg = issueBook(200, 3, lib, reg);
  reg = issueBook(400, 3, lib, reg);
  reg.viewStudent(3);
  return 0;
}

Registrar issueBook(int bookId, int studentId, Library library, Registrar registry) {
  Book book = library.getbook(bookId);
  Student student = registry.getStudent(studentId);
  student.checkedBooks.push_back(book);
  registry.updateStudent(studentId, student);
  return registry;
}