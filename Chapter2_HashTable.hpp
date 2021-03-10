#ifndef CHAPTER2_HASHTABLE_HPP
#define CHAPTER2_HASHTABLE_HPP
#include <iostream>
#include<vector>
using namespace std;

int hash_function(int* key) {return *key;}

struct HashElements {
  int* key;
  int* value;
};

class HashTable{
public:
  HashTable() = default;
  HashElements** items;
  int size;
  int count;
  void ht_insert(int key, int value);
  void print_table();
  vector<int> key_list();
  int ht_search(int key);
};

HashElements* createElements(int*key, int*value){
  HashElements* element = (HashElements*)malloc(sizeof(HashElements));
  element->key = (int*)malloc(sizeof(int));
  element->value = (int*)malloc(sizeof(int));
  element->key = key;
  element->value = value;
  return element;
}

HashTable* createTable(int size) {
  HashTable* table = (HashTable*) malloc (sizeof(HashTable));
  table->size = size;
  table->count = 0;
  table->items= (HashElements**) calloc (table->size, sizeof(HashElements*));
  for (int i = 0; i< size; i++) table->items[i] = NULL;
  return table;
}

void free_elements(HashElements* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void handle_collision(HashElements* item){}

void HashTable::ht_insert(int key, int value){
  int index = hash_function(&key);
  HashElements* item = createElements(&key, &value);
  HashElements* current = items[index];
  if (current == NULL){
    if (count == size){
      free_elements(item);
      cerr << "HashTable is full\n";
      exit(EXIT_FAILURE);
    }
    items[index] = item;
    count++;
  }
  else{
    if (*current->key==key) *items[index]->value = value;
    else handle_collision(item);
  }
}

void HashTable::print_table() {
    cout <<"Hash Table:\n";
    for (int i=0; i<size; i++) {
        if (items[i]) {
            cout << i << " " << *(items[i]->key) << " " << *(items[i]->value);
        }
    }
    cout << endl;
}

void free_table(HashTable* table) {
    // Frees the table
    for (int i=0; i<table->size; i++) {
        HashElements* item = table->items[i];
        if (item != NULL)
            free_elements(item);
    }
    free(table->items);
    free(table);
}

vector<int> HashTable::key_list(){
  vector<int> result;
  cout <<"Key list:\n";
  for (int i=0; i<size; i++) {
      if (items[i]) {
        result.push_back(*items[i]->key);
        cout << *items[i]->key << " ";
      }
  }
  cout << endl;
  return result;
}

int HashTable::ht_search(int key) {
    int index = hash_function(&key);
    HashElements* item = items[index];
    while (item != NULL) {
        if (*item->key== key)
            return *item->value;
    }
    return 0;
}


#endif //CHAPTER2_HASHTABLE_HPP
