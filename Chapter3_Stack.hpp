#ifndef CHAPTER3_STACK_HPP
#define CHAPTER3_STACK__HPP

#include<iostream>
#include<vector>
using namespace std;
class stack {
  public:
    stack(int);
    stack(const stack&);
    -stack()

    void push(int);
    int pop();

    bool empty() const; //const at the end means the function cannot change object members
    bool full() const;//const function:reading of a class variables is ok inside of the function but writing inside of this function will cause an error

    int capacity() const;
    int size() const;


}


#endif //  CHAPTER3_STACK__HPP
