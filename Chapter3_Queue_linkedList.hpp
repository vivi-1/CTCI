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
  string Dequeue();
  void print() const;
  bool is_empty() const;
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

string llQueue::Dequeue(){
  if (front == NULL) {
    cout << "No value to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  cout << "dequeueing " << front->data << endl;
  qNode* temp = front;
  string tempD = front->data;
  front = front->next;
  if (front == NULL) rear = NULL;
  delete(temp);
  return tempD;
}

void llQueue::print() const {
  qNode* temp = front;
  while (temp != NULL) {
  cout << temp -> data << " ";
  temp = temp->next;
  }
}

bool llQueue::is_empty() const {
  return front == NULL && rear == NULL;
}
