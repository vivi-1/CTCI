#ifndef CHAPTER2_LINKEDLIST_HPP
#define CHAPTER2_LINKEDLIST_HPP
#include <iostream>
#include <cstdlib>
#include "Chapter2_HashTable.hpp"
using namespace std;
struct Node {

   int data;
   Node *next;
};

class LinkedList{
public:
  Node* head = NULL, *tail = NULL;
  void insert_end(int);
  void insert_begining(int);
  void display();
  void removeDups();
  int size() {return count;}
  void deleteNode(Node*);
private:
  int count=0;
};

void LinkedList::insert_end(int item) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  //Allocates size bytes of uninitialized storage. Otherwise it will give bus error.
  //which is a signal sent to an application if it attempts to access memory
  //outside of its address space. This could be caused by using a bad pointer
  //that has an invalid address in it.
  temp->data = item;
  temp->next = NULL;
  if(head == NULL) {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else{
    tail->next = temp;
    tail = temp;
  }
  count++;
}

void LinkedList::insert_begining(int item) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = item;
  temp->next = head;
  if (head == NULL) {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else {
    head = temp;
    temp = NULL;
  }
  count++;
}

void LinkedList::display(){
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void LinkedList::deleteNode(Node* n){
  if (head == n) {
    if(head->next == NULL) {
      cout << "There is only one node." << " The list can't be made empty ";
      return;
    }
    head->data = head->next->data;
    n = head->next;
    head->next = head->next->next;
    free(n);
    return;
  }
  Node *prev = head;
  while(prev->next != NULL && prev->next != n) prev = prev->next;
  if(prev->next == NULL) {
    cout << "\nGiven node is not present in Linked List";
    return;
  }
  prev->next = prev->next->next;
  free(n);
  return;
}

void LinkedList::removeDups(){
  cout << "Hello";
  struct Node** temp = (struct Node**) malloc(sizeof(struct Node));
  temp = &head;
  cout << "HelloHello";
  HashTable* ht= createTable(size());
  while ((*temp) != NULL) {
    if ((*ht).ht_search((*temp)->data) == 1) {
      deleteNode(*temp);
      count--;
    }
    else (*ht).ht_insert((*temp)->data, 1);
    *temp = (*temp)->next;
  }
  free_table(ht);
  free(temp);
}


#endif //CHAPTER2_LINKEDLIST_HPP
