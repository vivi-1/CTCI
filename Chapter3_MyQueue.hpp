#ifndef CHAPTER3_MYQUEUE_HPP
#define CHAPTER3_MYQUEUE_HPP

#include<iostream>
#include<vector>
#include "Chapter3_Stack.hpp"
using namespace std;

class MyQueue {
  public:
    MyQueue (int);
    ~MyQueue();


    int peek();
    void push();
    int pop();

  private:
    int maxSize;
    stack sPush(60);
    stack sPop(60);
};


MyQueue::MyQueue (int threshold){
  maxSize = threshold;
  stack sPush(maxSize);
  stack sPop(maxSize);

}



int MyQueue::peek() {
  if (sPop.is_empty()){
    cout << "Queue is empty, no value to be popped\n";
    exit(EXIT_FAILURE);
  }
  return sPop.peek();
}

void MyQueue::push(int item) {
  sPush.push(item);
  sPop.cleanContents();
  while (!sPush.is_empty()) {
    sPop.push(sPush.pop());
  }
}

int MyQueue::pop(){
  if (sPop.is_empty()){
    cout << "Queue is empty, no value to be popped\n";
    exit(EXIT_FAILURE);
  }
  return sPop.pop();
}


#endif //CHAPTER3_MYQUEUE_HPP
