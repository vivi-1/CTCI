#include<iostream>
#include<vector>
#include"Chapter2_LinkedList.hpp"
//#include"Chapter3_LinkedList.hpp"
using namespace std;

int main(){
//Q2.1 Remove Dups:Write code to remove duplicates from an unsorted linked list.
LinkedList l;
l.insert_end(0);
l.insert_end(1);
l.insert_end(2);
l.insert_end(3);
l.insert_begining(-1);
l.insert_begining(-2);
l.insert_end(-2);
l.display();



  return 0;
}
