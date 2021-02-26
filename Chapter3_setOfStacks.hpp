#ifndef CHAPTER3_SETOFSTACKS_HPP
#define CHAPTER3_SETOFSTACKS_HPP

#include<iostream>
#include<vector>
#include "Chapter3_Stack.hpp"
using namespace std;

class setOfStacks {
  public:
    setOfStacks(int);

    int peek();
    bool is_empty() const;
    void push(int);
    int pop();
    int popAt(int);

  private:
    vector<stack> vecS;
    int maxsize;
    int indexS;

};

setOfStacks::setOfStacks(int threshold) {
  maxsize = threshold;
  stack s (maxsize);
  vecS.push_back(s);
  indexS = 0;
}

bool setOfStacks::is_empty() const {
  return indexS == 0 && vecS[indexS].is_empty();
}

int setOfStacks::pop() {
  if (is_empty()) {
    cout << "Stack is empty no data to pop\n";
    exit(EXIT_FAILURE);
  }
  return vecS[indexS].is_empty() ?  vecS[--indexS].pop() : vecS[indexS].pop();
}

void setOfStacks::push(int item){
  if (vecS[indexS].is_full()) {
    stack s (maxsize);
    vecS.push_back(s);
    vecS[++indexS].push(item);
  }
  else vecS[indexS].push(item);
}

int setOfStacks::popAt(int index){
  return vecS[index].pop();
}

#endif //CHAPTER3_SETOFSTACKS_HPP
