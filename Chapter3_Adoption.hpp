
class Animal {
public:
  friend class Queue;
  Cat() = default;
  Cat(string s) : ID(s) { }
  Cat(const Queue &);
  ~Cat();
  string name() {return ID;}
  string aEnqueue();
  string aDequeue();
  string qDequeueCat(Cat);
  string EnqueueCat(Cat);
  string EnqueueDog(Dog);
  string DequeueDog(Dog);

private:
  string ID;
  unsigned int age;
};

class Dog {
public:
  friend class Queue;
  Dog() = default;
  Dog(string s) : ID(s) { }
  Dog(const Queue &);
  ~Dog();
  string ID;
  unsigned int age;
};
