#include<iostream>
#include <string>
#include "Chapter3_Queue_linkedList.hpp"
using namespace std;

class Animal {
public:
  Animal() = default;

  Animal(string s, string t) : ID(s), CatOrDog(t) {
    if (t == "Cat") Cat.Enqueue(name());
    if (t == "Dog") Dog.Enqueue(name());
    All.Enqueue(name());}
  Animal(const Animal &);
  ~Animal();
  llQueue Cat;
  llQueue Dog;
  llQueue All;

  string name() {return ID;}
  string type() {return CatOrDog;}
  void aEnqueue(string);
  string aDequeue();
  string DequeueCat();
  string DequeueDog();

private:
  string ID;
  string CatOrDog;
  unsigned int age;

};


Animal::Animal(const Animal & a) {
  Cat = a.Cat;
  Dog = a.Dog;
  All = a.All;
}

void Animal::aEnqueue(string item){
  if (type() == "Cat") Cat.Enqueue(name());
  if (type() == "Dog") Dog.Enqueue(name());
  All.Enqueue(name());
}

string Animal::aDequeue(){
  if (All.is_empty()) {
    cout << "No animal to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  return All.Dequeue();
}

string Animal::DequeueCat(){
  if (Cat.is_empty()) {
    cout << "No cat to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  return Cat.Dequeue();
}


string Animal::DequeueDog(){
  if (Dog.is_empty()) {
    cout << "No dog to be dequeued \n";
    exit(EXIT_FAILURE);
  }
  return Dog.Dequeue();
}
