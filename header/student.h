#ifndef __student_h_
#define __student_h_
#endif

#include <string>
#include <vector>

using namespace std;

struct Student {
  int id;
  string name;
  string email;
  vector<Book> checkedBooks;
};