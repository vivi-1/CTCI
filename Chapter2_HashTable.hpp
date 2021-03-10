#ifndef CHAPTER2_HASHTABLE_HPP
#define CHAPTER2_HASHTABLE_HPP
#include <iostream>
using namespace std;
struct HashElements {
  int* key;
  string* value;
  HashElements* createElements(int*, string*);
};

class HashTable{
public:
  HashTable() = default;
  HashElements** items;
  HashElements* createElements(int*, string*);
  int size;
  int count;

};

HashElements* HashElements::createElements(int*, string*){
  HashElements* element = (HashElements*)malloc(sizeof(HashElements));
  element->key = (int*)malloc(sizeof(int));
  element->value = (string*)malloc(sizeof(string));
  element->key = key;
  element->value = value;
  return element;
}

#endif //CHAPTER2_HASHTABLE_HPP
