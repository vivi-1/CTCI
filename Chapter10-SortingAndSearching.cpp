#include<iostream>
#include<vector>
using namespace std;

//Q10.1 Sorted Merge: You are given two sorted arrays, A and B, where A has a
// large enough buffer at the end to hold B. Write a method to merge B into A in
// sorted order.
//BigO notation: Best case O(nlogN) Average case O(nlogN) Worst case O(N^2)
vector<int> SortedMerge(vector<int> v1, vector<int> v2) {
  v1.insert(v1.end(), v2.begin(), v2.end());
  sort(v1.begin(), v1.end());
  return v1;
}

//Q10.2 Group Anagrams: Write a method to sort an array of strings so that all
//the anagrams are next to each other.
class HashTable{
private:
  vector<string> *table;
  int size_of_vector;
  int getHash(string key) {
    return 
  }
}


vector<int> SortAnagrams(vector<string> v) {
  vector<string> tempV;
  for (auto i : v) {
    temp = i;
    sort(temp.begin(), temp.end());
    tempV.push_back(i);

  }

}

int main(){
/*
//Q10.1
  vector<int> v1 = {1, 2, 3, 4, 5, 6};
  vector<int> v2 = {4, 5, 6, 7, 8, 9};
  v1 = SortedMerge(v1, v2);
  for(int i = 0; i!= v1.size(); i++) cout << v1[i] << endl;
*/


  return 0;
}
