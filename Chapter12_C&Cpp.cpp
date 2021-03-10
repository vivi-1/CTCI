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
//Hash table vs Standard Template Library (STL)
//STL is like tries, however, keys in tries only can be stored and processed digit
//by digit or character by character.However, STL is designed to work with



//Q12.4 Virtual Functions: How do virtual functions work in C++?

//Q12.5 Shallow vs Deep Copy: What is the difference between deep copy and
//shallow copy? Explain how you would use each.

//Q12.6 Volatile: What is the significance of the keyword "volatile" in C?

//Q12.7 Virtual Base Class: Why does a destructor in base class need to be
//declared virtual?

//Q12.8 Copy Node: Write a method that takes a pointer to a Node structure as a
//parameter and returns a complete copy of the passed in data structure.
//The Node data structure contains two pointers to other Nodes.


// Q12.9 Smart Pointer: Write a smart pointer class. A smart pointer is a data
//type, usually implemented with templates, that simulates a pointer while also
//providing automatic garbage collection. It automatically counts the number of
//references to a SmartPointer<T*>object and frees the object of type T when the
//reference count hits zero.

//12.10 Malloc: Write an aligned malloc and free function that supports
//allocating memory such that the memory address returned is divisible by a
//specific power of two.
//EXAMPLE
//align _mallo c (ieee, 128) will return a memory address that is a multiple of
//128 and that points to memory of size 1000 bytes.
//aligned_free() will free memory allocated by align_malloc.



//Q12.11 20 Alloc: Write a function in C called my2DAlloc which allocates a
//two-dimensional array. Minimize the number of calls to malloc and make sure
//that the memory is accessible by the notation arr[iJ [j].




  return 0;
}
