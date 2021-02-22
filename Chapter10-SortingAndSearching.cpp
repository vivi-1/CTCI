#include<iostream>
#include<vector>
using namespace std;

//Q10.1 Sorted Merge: You are given two sorted arrays, A and B, where A has a
// large enough buffer at the end to hold B. Write a method to merge B into A in
// sorted order.
//BigO notation: Best case O(nlogN) Average case O(nlogN) Worst case O(N^2)
vector<int> SortedMerge(vetor<int> v1, vector<int> v2) {
  v1.insert(v1.end(), v2.begin(), v2.end());
  sort(v1.begin(), v.end());
}

int main(){



  return 0;
}
