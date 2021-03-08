#include<iostream>
#include <string>
#include "Chapter3_Queue_linkedList.hpp"
using namespace std;

class Animal {
public:
  Animal() = default;

  Animal(string s, string t) : ID(s), CatOrDog(t) {
    if (t == "Cat") Cat.Enqueue(s,t);
    if (t == "Dog") Dog.Enqueue(s,t);
    All.Enqueue(s,t);}
  Animal(const Animal &);

  llQueue Cat;
  llQueue Dog;
  llQueue All;

  string name() {return ID;}
  string type() {return CatOrDog;}

  void aEnqueue(string, string);
  string aDequeue();
  string DequeueCat();
  string DequeueDog();
  void print();

private:
  string ID;
  string CatOrDog;
};

Animal::Animal(const Animal & a) {
  Cat = a.Cat;
  Dog = a.Dog;
  All = a.All;
}

void Animal::aEnqueue(string s, string t){
  ID = s;
  CatOrDog = t;
  if (t == "Cat") Cat.Enqueue(s, t);
  if (t == "Dog") Dog.Enqueue(s, t);
  All.Enqueue(s, t);
}

string Animal::aDequeue(){
  if (All.is_empty()) {
    cout << "No animal to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  cout << "DequeueAll: \n";
  vector<string> temp = All.peek();
  All.Dequeue();
  if (temp[1] == "Cat") Cat.Dequeue();
  if (temp[1] == "Dog") Dog.Dequeue();
  return temp[0];
}

string Animal::DequeueCat(){
  if (Cat.is_empty()) {
    cout << "No cat to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  cout << "DequeueCat: \n";
  All.findAndDeleteValue(Cat.peek()[0], Cat.peek()[1]);
  return Cat.Dequeue()[0];
}


string Animal::DequeueDog(){
  if (Dog.is_empty()) {
    cout << "No dog to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  cout << "DequeueDog: \n";
  return Dog.Dequeue()[0];
}

void Animal::print(){
  cout << "Cat:\n";
  Cat.print();
  cout << "Dog:\n";
  Dog.print();
}
