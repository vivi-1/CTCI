#include<iostream>
#include<vector>
#include <string>
using namespace std;

struct qNode{
  string data;
  qNode* next;
  qNode(string s) {
    data = s;
    next = NULL;
  }
};

class llQueue{
public:
  qNode *front, *rear;
  llQueue() {front = rear = NULL;}
  void Enqueue(string);
  void Dequeue();
  void print() const;
};

void llQueue::Enqueue(string item){
  qNode* temp = new qNode(item);
  if(rear == NULL) {
    front = rear = temp;
    return;
  }
  rear -> next = temp;
  rear = temp;
}

void llQueue::Dequeue(){
  if (front == NULL) return;
  cout << "dequeueing " << front->data << endl;
  qNode* temp = front;
  front = front->next;
  if (front == NULL) rear = NULL;
  delete(temp);
}

void llQueue::print() const {
  qNode* temp = front;
  while (temp != NULL) {
  cout << temp -> data << " ";
  temp = temp->next;
  }
}
