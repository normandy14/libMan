#include <string>
#include <cctype>
#include <iostream>
#include "functions.h"

using namespace std;

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

float tokenSortRatio(string s1, string s2) {
  int rLen;
  int cLen;
  int cost;
  int min_;
  float ratio;
  for (char &c: s1) {
    c = to_lowercase(c);
  }
  for (char &c: s2) {
    c = to_lowercase(c);
  }
  rLen = s1.length();
  cLen = s2.length();
  int distMatrix[rLen][cLen] = { };
  
  for (int i=0; i < rLen; i++) {
    for (int j=0; j < cLen; j++) {
      distMatrix[i][0] = i;
      distMatrix[0][j] = j;
    }
  }

  for (int i=1; i < rLen; i++) {
    for (int j=1; j < cLen; j++) {
      if (s1[i] == s2[j]) {
        cost = 0;
      }
      else {
        cost = 2;
      }
      min_ = min(distMatrix[i-1][j] + 1, distMatrix[i][j-1] + 1, distMatrix[i-1][j-1] + cost);
      distMatrix[i][j] = min_;
    }
  }
  ratio = ((rLen + cLen) - distMatrix[rLen-1][cLen-1]) / (float)(rLen + cLen);
  return ratio;
}

char to_lowercase(char c) {
  if ( c >= 'A' && c <= 'Z') {
    return c + 32;
  }
  return c;
}