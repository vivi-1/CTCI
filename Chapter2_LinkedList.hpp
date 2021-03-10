#ifndef CHAPTER2_LINKEDLIST_HPP
#define CHAPTER2_LINKEDLIST_HPP
#include <iostream>
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
  LinkedList removeDups();
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
}

void LinkedList::display(){
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

LinkedList LinkedList::removeDups(){
  Node* temp = head;
  while (temp != NULL) {

  }
}

#endif //CHAPTER2_LINKEDLIST_HPP
