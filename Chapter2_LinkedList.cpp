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
l.insert_begining(1);
l.insert_begining(2);
l.insert_end(2);
// l.display();
// l.removeDups();
l.display();

HashTable* ht= createTable(50);
//(*ht).print_table();
struct Node** temp = (struct Node**) malloc(sizeof(struct Node));
temp = &(l.head);
(*ht).ht_insert((*temp)->data, 1);
(*ht).print_table();
cout << "\n\n";
(*temp) = (*temp)->next;
(*ht).ht_insert((*temp)->data, 1);
(*ht).print_table();
cout << "\n\n";
// while ((*temp) != NULL) {
//   cout << (*temp)->data;
//   if ((*ht).ht_search((*temp)->data) == 1) {
//     l.deleteNode(*temp);
//   }
//   else (*ht).ht_insert((*temp)->data, 1);
//   *temp = (*temp)->next;
// }
//
// l.display();





  return 0;
}
