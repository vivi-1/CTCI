#include<iostream>
#include<vector>
using namespace std;
#include <fstream>

//Q12.1
void PrintLK(char * filename, const int k) {
  std::ifstream file(filename);
  if (file.is_open()) {
      std::string line1, line2;
      int cnt1 = 0, cnt2 = 0;
      while (std::getline(file, line1) && !file.eof()) {
          ++cnt1;
      }
      while (std::getline(file, line2) && !file.eof()) {
          ++cnt2;
          while (cnt2 == cnt1 - k) printf("%s", line2.c_str());
      }
      file.close();
  }
}

//Q12.2

void reverse(char * str) {
  int size = 0;
  while ((*str)!= '\0') {
    ++size;
    ++str;
  }
  str -= 1;
  char c[size+1];
  for (int i=0; i != size && (*str)!= '\0' && str != nullptr; --str, ++i) {
    c[i] = *str;
  }
  str += 1;
  c[size+1] = '\0';
  for (int i = 0 ; i != size; ++str, ++i){
    *str = c[i];
  }
}

int main() {

/*
//Q12.1 Last K Lines: Write a method to print the last Klines of an input file
//using C++.

//Q12.2 implement a function void reverse(char * str) in C or C++ which reverses
//a null-terminated string
char cstring1[] = {"wei"};
char cstring2[4] = {'w', 'e', 'i'};
char cstring3[4] = {"wei"};
char cstring4[4] = {'w', 'e', 'i', '\0'};

reverse(cstring1);
reverse(cstring2);
reverse(cstring3);
reverse(cstring4);
cout << cstring1 << " " << cstring2  << " " << cstring3  << " " << cstring4 << endl;

*/

//Q12.3 Hash Table vs STL Map: Compare and contrast a hash table and an STL
//map. How is a hash table implemented? If the number of inputs is small, which
//data structure options can be used instead of a hash table?





  return 0;
}
