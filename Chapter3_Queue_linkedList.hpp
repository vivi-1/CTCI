#include<iostream>
#include<vector>
#include <string>
using namespace std;

struct qNode{
  string data1;
  string data2;
  qNode* next;
  qNode(string s1, string s2) {
    data1 = s1;
    data2 = s2;
    next = NULL;
  }
};

class llQueue{
public:
  qNode *front, *rear;
  llQueue() {front = rear = NULL;}
  void Enqueue(string, string);
  vector<string> Dequeue();
  void print() const;
  bool is_empty() const;
  vector<string> peek()const;
  llQueue findAndDeleteValue(string, string);
};

void llQueue::Enqueue(string s1, string s2){
  qNode* temp = new qNode(s1, s2);
  if(rear == NULL) {
    front = rear = temp;
    return;
  }
  rear -> next = temp;
  rear = temp;
}



vector<string> llQueue::Dequeue(){
  if (front == NULL) {
    cout << "No value to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  cout << "dequeueing " << front->data1 << " " <<  front->data2 << endl;
  qNode* temp = front;
  vector<string> result;
  result.push_back(front->data1);
  result.push_back(front->data2);
  front = front->next;
  if (front == NULL) rear = NULL;
  delete(temp);
  return result;
}

void llQueue::print() const {
  qNode* temp = front;
  while (temp != NULL) {
  cout << temp->data1 << " " << temp->data2 << " ";
  temp = temp->next;
  }
  cout << endl;
}

bool llQueue::is_empty() const {
  return front == NULL && rear == NULL;
}

vector<string> llQueue::peek()const {
  if (front == NULL) {
    cout << "No value to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  vector<string> result;
  result.push_back(front->data1);
  result.push_back(front->data2);
  return result;
}

llQueue llQueue::findAndDeleteValue(string s, string t) {
  llQueue temp;
  while (front->data1!=s || front->data2!=t) temp.Enqueue(Dequeue()[0], Dequeue()[1]);
  Dequeue();
  while(!is_empty()) temp.Enqueue(Dequeue()[0], Dequeue()[1]);
  return temp;
}
