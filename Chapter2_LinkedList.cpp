#include<iostream>
#include"Chapter2_LinkedList.hpp"
#include"Chapter2_HashTable.hpp"
using namespace std;

int main(){
//Q2.1 Remove Dups:Write code to remove duplicates from an unsorted linked list.
//Please check my Chapter2_LinkedList.hpp and the class function removeDups.
LinkedList l;
l.insert_end(0);
l.insert_end(1);
l.insert_end(2);
l.insert_end(3);
l.insert_begining(-1);
l.insert_begining(-2);
l.insert_end(-2);
l.display();
l.removeDups();
l.display();



  return 0;
}
