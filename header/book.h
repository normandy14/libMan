#ifndef __book_h_
#define __book_h_
#endif

#include <iostream>
#include <string>

using namespace std;

struct Book {
  int id;
  string name;
  string author;
  string category;
  int quantity;
  int price;
  int rackNo;
};
