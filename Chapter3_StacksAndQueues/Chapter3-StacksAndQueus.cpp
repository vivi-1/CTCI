#include<iostream>
#include<vector>
using namespace std;
#include "Chapter3_Stack.hpp"
#include "Chapter3_setOfStacks.hpp"
#include "Chapter3_MyQueue.hpp"
#include "Chapter3_Queue_arr.hpp"
//#include "Chapter3_Queue_linkedList.hpp"
#include "Chapter3_Adoption.hpp"

int main(){
//Q3.1 Three in One: Describe how you could use a single array to implement
//three stacks.
//Stack a,b and c
//Fixed space for each stack:
//Array index:   0      1      2      3    4     5     6     7     8   ...m
//Stack element: a[0]  b[0]   c[0]  a[1]  b[1]  c[1]  a[2]  b[2]  c[2] ...a[n]
//Stack "a" a[i] takes up position 0+3i in the array
//Stack "b" b[i] takes up position 1+3i in the array
//Stack "c" c[i] takes up position 2+3i in the array

//Flexible spaces for each stack:
//


//Q3.2 Stack Min: How would you design a stack which, in addition to push and
//pop, has a function min which returns the minimum element? Push, pop and min
//should all operate in 0(1) time.
//Please refer to Chapter3_stack.cpp
stack s1(10);
if (s1.is_empty()) cout << "Empty stack\n";
s1.push(8);
s1.push(5);
s1.push(10);
s1.push(0);
s1.push(4);
if (!s1.is_full()) cout << "Not full\n";
cout << "size:" << s1.size() << ", capacity:" << s1.capacity() << " ,min value: "
       << s1.min_element() <<endl;
s1.pop();
s1.pop();
s1.pop();

cout << "size:" << s1.size() << ", capacity:" << s1.capacity() << " ,min value: "
      << s1.min_element() <<endl;

s1.push(0);
s1.push(7);
s1.push(9);
s1.push(11);
s1.push(2);
s1.push(3);
s1.push(6);
s1.push(-1);
//s1.push(32);
if (s1.is_full()) cout << "full\n";
cout << "size:" << s1.size() << ", capacity:" << s1.capacity() << " ,min value: "
      << s1.min_element() <<endl;
s1.~stack ();


//Q3.3 Stack of Plates: Imagine a (literal) stack of plates. If the stack gets
//too high, it might topple. Therefore, in real life, we would likely start a
//new stack when the previous stack exceeds some threshold. Implement a data
//structure SetOfStacks that mimics this. SetOfStacks should be composed of
//several stacks and should create a new stack once the previous one exceeds
//capacity. SetOfStacks. push () and SetOfStacks. pop () should behave identically
//to a single stack (that is, pop ( ) should return the same values as it would
//if there were just a single stack).
//FOLLOW UP
//Implement a function popAt(int index)which performs a pop operation on a
//specific sub-stack.
setOfStacks s2(4);
cout << s2.threshold() << endl;
if (s2.is_empty()) cout << "empty\n";
s2.push(1);
cout << s2.peek() << endl;
s2.push(2);
cout << s2.peek() << endl;
s2.push(3);
cout << s2.peek() << endl;
if (!s2.currentS().is_full()) cout << s2.stackIndex() << "not full yet\n";
s2.pop();
cout << s2.peek() << endl;
s2.push(4);
s2.push(5);
if (s2.currentS().is_full()) cout << s2.stackIndex() << "full\n";
cout << s2.stackIndex() << endl;
s2.push(6);
s2.push(7);
cout << s2.peek() << " " << s2.stackIndex() << endl;

//Q3.4 Queue via Stacks: Implement a MyQueue class which implements a queue
//using two stacks.
//Please check my Chapter3_MyQueue.hpp
stack s3(5);
s3.push(1);
s3.push(2);
s3.push(3);
s3.push(4);
s3.push(5);
s3.print();
sort_smallTop(s3);
s3.print();
//Q3.5 Sort Stack: Write a program to sort a stack such that the smallest items
//are on the top. You can use an additional temporary stack, but you may not
//copy the elements into any other data structure (such as an array). The stack
//supports the following operations: push, pop, peek, and isEmpty.
//Please check the friend function:stack sort_smallTop(stack s) in Chapter3_Stack.hpp


//Q3.6 Animal Shelter: An animal shelter, which holds only dogs and cats,
//operates on a strictly"first in, first out" basis. People must adopt either
//the "oldest" (based on arrival time) of all animals at the shelter, or they
//can select whether they would prefer a dog or a cat (and will receive the
//oldest animal of that type). They cannot select which specific animal they
//would like. Create the data structures to maintain this system and implement
//operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may
//use the built-in LinkedList data structure.
//Please check my Chapter3_Adoption.hpp, Chapter3_Queue_linkedList.hpp and
//Chapter3_Queue_arr.hpp
Animal a;
a.aEnqueue("01", "Cat");
a.aEnqueue("02", "Dog");
a.aEnqueue("03", "Cat");
a.aEnqueue("04", "Cat");
a.aEnqueue("05", "Cat");
a.aEnqueue("06", "Dog");
a.aEnqueue("07", "Dog");
a.print();
a.aDequeue();
a.print();
a.aDequeue();
a.DequeueDog();
a.print();


  return 0;
}
