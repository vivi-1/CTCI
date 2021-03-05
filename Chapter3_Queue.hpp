#ifndef CHAPTER3_QUEUE_HPP
#define CHAPTER3_QUEUE_HPP

#include<iostream>
#include<vector>
using namespace std;

class Queue {
public:
  //constructors:
  Queue() = default;
  Queue(int);
  Queue(const Queue &);
  ~Queue();
  //member functions
  string enqueue();
  string dequeueAny();
  string dequeueDog();
  string dequeueCat();

private:
  string ID;
  string type;

}

#endif //CHAPTER3_QUEUE_HPP
