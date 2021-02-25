#ifndef CHAPTER3_STACK_HPP
#define CHAPTER3_STACK_HPP

#include<iostream>
#include<vector>
using namespace std;
class stack {
  public:
    stack(int);
    stack(const stack&);
    ~stack();

    int peek();
    void push(int);
    int pop();


    bool is_empty() const; //const at the end means the function cannot change object members
    bool is_full() const;//const function:reading of a class variables is ok inside of the function but writing inside of this function will cause an error
    int capacity() const;
    int size() const;
    int min_element() const;

    friend ostream& operator <<(ostream&, const stack&);
  private:
    int* arr;
    int top;
    int maxsize;
    int min;
    vector<int> min_elements;
};

stack::stack(int size) {
  arr = new int[size];
  maxsize = size;
  top = -1;
}

stack::stack(const stack& s){
  arr = new int[s.maxsize]; //The new expression attempts to allocate storage and then attempts to construct and initialize either a single unnamed object, or an unnamed array of objects in the allocated storage.
  maxsize = s.maxsize;
  top = s.top;
}

stack::~stack() {
  delete[] arr;//The delete [] operator deallocates memory and calls destructors for an array of objects created with new [].
}

int stack::peek() {
  if(is_empty()) {
    cout << "Stack is empty, no element to be popped\n";
    exit(EXIT_FAILURE);
  }
  return arr[top];
}

void stack::push(int item) {
  if (is_full()) {
    cout << "Stack is already full, no space for new data\n";
    exit(EXIT_FAILURE);
  }
  if (is_empty()) {
    min = item;
    min_elements.push_back(item);
  }
  top += 1;
  arr[top] = item;
  if (item < min) {
    min = item;
    min_elements.push_back(item);
  }
}

int stack::pop() {
  if(is_empty()) {
    cout << "Stack is empty, no element to be popped\n";
    exit(EXIT_FAILURE);
  }
  cout << "popping" << peek() << endl;
  top -= 1;
  return arr[top];
  if (arr[top] == min_elements[min_elements.size()-1]) {
    min_elements.pop_back();
  }
}

bool stack::is_empty() const {
  return top == -1;
}

bool stack::is_full() const{
  return (top +1) == maxsize;
}

int stack::capacity() const {
  return maxsize;
}

int stack::size() const {
  return top + 1;
}

int stack::min_element() const{
  int len = min_elements.size();
  return min_elements[len-1];
}

#endif //  CHAPTER3_STACK__HPP
