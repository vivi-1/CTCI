// #ifndef CHAPTER2_LINKEDLIST_HPP
// #define CHAPTER2_LINKEDLIST_HPP
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
};

void LinkedList::insert_end(int item) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
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

// #endif //CHAPTER2_LINKEDLIST_HPP
