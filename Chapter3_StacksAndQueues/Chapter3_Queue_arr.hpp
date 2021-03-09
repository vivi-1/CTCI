#include<iostream>
#include<vector>
#include <string>
using namespace std;

class Queue {
public:
  friend class Animal;
  //constructors:
  Queue() = default;
  Queue(int);
  Queue(const Queue &);
  ~Queue();
  //member functions
  bool is_empty() const; //const at the end means the function cannot change
  //object members
  bool is_full() const;//const function:reading of a class variables is ok
  //inside of the function but writing inside of this function will cause an error
  int capacity() const {return maxsize;}
  int size() const {return bottom + 1;};
  void Enqueue(string);
  string Dequeue();
  void print() const;

private:
  string * arr;
  int bottom = -1;
  int maxsize;
};

Queue::Queue(int size) {
  maxsize = size;
  arr = new string[size];
}

Queue::Queue(const Queue& q){
  arr = new string[q.maxsize]; //The new expression attempts to allocate storage and then attempts to construct and initialize either a single unnamed object, or an unnamed array of objects in the allocated storage.
  maxsize = q.maxsize;
  bottom = q.bottom;
}

Queue::~Queue() {
  delete[] arr;//The delete [] operator deallocates memory and calls destructors for an array of objects created with new [].
}

bool Queue::is_empty() const{
  return bottom == -1;
}

bool Queue::is_full() const {
  return bottom == maxsize - 1;
}

void Queue::Enqueue(string item) {
  if (is_full()) {
    cerr<<"Queue is full\n";
    exit(EXIT_FAILURE);
  }
  arr[bottom+1] = item;
  bottom++;
}

string Queue::Dequeue() {
  if (is_empty()) {
    cerr << "Queue is empty, nothing to dequeue\n";
    exit(EXIT_FAILURE);
  }
  cout << "dequeueing " << arr[0] << endl;
  for (int i = 1; i <= bottom ; ++i){
    arr[i-1] = arr[i];
  }
  bottom--;
  return arr[0];
}

void Queue::print() const{
  for (int i = 0; i <= bottom; ++i) cout << arr[i] << " ";
  cout << endl;
}
