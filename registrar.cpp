#include <iostream>
#include <vector>
#include "header/registrar.h"
#include "header/functions.h"

using namespace std;

// Adds a student to the registrar
void Registrar::addStudent(int idIn, string nameIn, string emailIn) {
  Student student;
  student.id = idIn;
  student.name = nameIn;
  student.email = emailIn;
  registrarMap.insert({student.id, student});
}

// Searches and returns the books that match the user title
void Registrar::searchStudent(string name) {
  string name_;
  for (map<int,Student>::iterator it = registrarMap.begin(); it != registrarMap.end(); ++it) {
    name_ = it -> second.name;
    if (tokenSortRatio(name, name_) > 0.40) {
      viewStudent(it -> second.id);
    }
  }
}

// Modifies a student's attributes
void Registrar::modifyStudent(int id, string nameIn = "", string emailIn = "") {
  Student student = registrarMap[id];
  if (nameIn != "") {
    student.name = nameIn;
  }
  if (emailIn != "") {
    student.email = emailIn;
  }
  registrarMap[id] = student;
}

// Updates a student
void Registrar::updateStudent(int id, Student student) {
  registrarMap[id] = student;
}

// Displays the student's attributes
void Registrar::viewStudent(int id) {
  Student student = registrarMap[id];
  cout << "name: " << student.name << endl;
  cout << "email: " << student.email << endl;
  Book book;
  cout << student.checkedBooks.size() << endl;
  for (vector<Book>::iterator it = student.checkedBooks.begin() ; it != student.checkedBooks.end(); ++it) {
    book = *it;
    cout << "id: " << book.id << endl;
    cout << "name: " << book.name << endl;
    cout << "author: " << book.author << endl;
  }
}

// Removes a student from the registrar
void Registrar::deleteStudent(int id) {
  registrarMap.erase(id);
}

// Returns a student from the registrar
Student Registrar::getStudent(int id) {
  return registrarMap[id];
}