#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Cat;
class Dog;
class Queue {
public:
  friend class Cat;
  friend class Dog;
  //constructors:
  Queue() = default;
  Queue(string s) : ID(s) { }
  Queue(const Queue &);
  ~Queue();
  //member functions
  string name() {return ID;}
  string Enqueue();
  string Dequeue();
  string qDequeueCat(Cat);
  string EnqueueCat(Cat);
  string EnqueueDog(Dog);
  string DequeueDog(Dog);

private:
  string ID;
  unsigned int age;
};

class Cat {};
class Dog {};
