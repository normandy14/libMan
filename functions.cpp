#include <string>
#include <cctype>
#include <iostream>
#include "header/functions.h"

using namespace std;

// Returns the min of three ints
int min(int x, int y, int z) {
  if (x > y) {
    if (y > z) {
      return z;
    }
    return y;
  }
  else {
    if (x > z) {
      return z;
    }
    return x;
  }
}

// Computes the difference between two strings
float tokenSortRatio(string s1, string s2) {
  int cost;
  int min_;
  float ratio;
  int rLen = s1.length();
  int cLen = s2.length();
  s1 = lowerCaseStr(s1);
  s2 = lowerCaseStr(s2);
  
  int matrix[rLen][cLen] = { };
  
  // initalize matrix
  for (int i=0; i < rLen; i++) {
    for (int j=0; j < cLen; j++) {
      matrix[i][0] = i;
      matrix[0][j] = j;
    }
  }
  
  // compute the cost, numeric value of performing an operation on the strings
  for (int i=1; i < rLen; i++) {
    for (int j=1; j < cLen; j++) {
      if (s1[i] == s2[j]) {
        cost = 0;
      }
      else {
        cost = 2;
      }
      // choose the min of the operations, and store in the matrix
      min_ = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + cost);
      matrix[i][j] = min_;
    }
  }
  // calculate the ratio
  ratio = ((rLen + cLen) - matrix[rLen-1][cLen-1]) / (float)(rLen + cLen);
  return ratio;
}

// Converts a string to lowercase
string lowerCaseStr(string s) {
  for (char &c: s) {
    cout << c << endl;
    c = toLowerChar(c);
  }
  return s;
}

// Coverts a char to lowercase
char toLowerChar(char c) {
  if ( c >= 'A' && c <= 'Z') {
    return c + 32;
  }
  return c;
}