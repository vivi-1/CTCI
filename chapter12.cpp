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


int main() {
//Q12.1 Last K Lines: Write a method to print the last Klines of an input file
//using C++.



//Q12.2



  return 0;
}
