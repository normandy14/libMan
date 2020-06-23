#include <iostream>
#include <vector>
#include "registrar.h"
#include "functions.h"

using namespace std;

void Registrar::addStudent(int idIn, string nameIn, string emailIn) {
  Student student;
  student.id = idIn;
  student.name = nameIn;
  student.email = emailIn;
  registrarMap.insert({student.id, student});
}

void Registrar::searchStudent(string name) {
  string name_;
  for (map<int,Student>::iterator it = registrarMap.begin(); it != registrarMap.end(); ++it) {
    name_ = it -> second.name;
    if (tokenSortRatio(name, name_) > 0.40) {
      viewStudent(it -> second.id);
    }
  }
}

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

void Registrar::updateStudent(int id, Student student) {
  registrarMap[id] = student;
}

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

void Registrar::deleteStudent(int id) {
  registrarMap.erase(id);
}

Student Registrar::getStudent(int id) {
  return registrarMap[id];
}