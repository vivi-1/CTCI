#ifndef CHAPTER3_MYQUEUE_HPP
#define CHAPTER3_MYQUEUE_HPP

#include<iostream>
#include<vector>
#include"Chapter3_Stack.hpp"
using namespace std;

class MyQueue {
  public:
    MyQueue (int);
    ~MyQueue();


    int qPeek();
    void qPush(int);
    int qPop();

  private:
    int maxSize;
    stack sPush;
    stack sPop;
};


MyQueue::MyQueue (int threshold){
  maxSize = threshold;
  stack sPush(maxSize);
  stack sPop(maxSize);

}

int MyQueue::qPeek() {
  return sPop.peek();
}

void MyQueue::qPush(int item) {
  sPush.push(item);
  sPop.cleanContents();
  while (!sPush.is_empty()) {
    sPop.push(sPush.pop());
  }
}

int MyQueue::qPop(){
  if (sPop.is_empty()){
    cout << "Queue is empty, no value to be popped\n";
    exit(EXIT_FAILURE);
  }
  return sPop.pop();
}


#endif //CHAPTER3_MYQUEUE_HPP
