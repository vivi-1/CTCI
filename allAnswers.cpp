#include<iostream>
#include<vector>
using namespace std;


//Q1.1
bool unique_s(const string &s) {
  bool result = true;
  int size = s.length();
  if (size > 128) result = false;
  for (int i=0; i != size; ++i) {
    if (count(s.begin(),s.end(), s[i]) != 1) result = false;
  }
  return result;
}

//Q1.2
bool permutation(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) return false;
    else {
      for (int i = 0; i != s1.length(); i++) {
        if (count(s1.begin(), s1.end(), s1[i]) == count(s2.begin(), s2.end(), s1[i]))
          return true;
        else return false;
      }
    }
}

//Q1.3
void replace(string& s, int cnt) {
  for (int i=0; i != cnt; ++i) {
    if (isspace(s[i])) s.replace(i,1,"%20");
  }
}

//Q1.4
bool purpalin(string& s) {
  int len = s.length();
  int temp;
  bool result =  true;
  if (len%2 == 0) {
    for (int i = 0; i!= len; ++i) {
      temp = count(s.begin(), s.end(), s[i]);
      switch (temp%2){
        case 1: result = false; break;
      }
    }
  }
  else{
    int cnt = 0;
    for (int i = 0; i!= len; ++i) {
      temp = count(s.begin(), s.end(), s[i]);
      if (temp%2 != 0) cnt += 1;
    }
    if (cnt >1) result = false;
  }
  return result;
}


//Q1.5
bool one_edit(string &s1, string &s2) {
  int len1 = s1.length(), len2 = s2.length(), diff = len1 - len2;
  bool result = false;
  if (s1 == s2) result = true;
  else {
    if (diff == 0) {
      int cnt = 0;
      for (int i = 0; i != len1; ++i) {
        if (s1[i] == s2[i]) cnt += 1;
      }
      if (cnt == len1 - 1) result = true;
    }
    else if (diff == 1) {
      int cnt = 0;
      for (int i = 0; i != len1; ++i) {
        if (s1[i] != s2[i]) {
          s1.erase(i, 1);
          cnt += 1;
          break;
        }
      }
      if (cnt == 1 && s2 == s1) result = true;
    }
    else if (diff == -1) {
      int cnt = 0;
      for (int i = 0; i != len2; ++i) {
        if (s1[i] != s2[i]) {
          s2.erase(i, 1);
          cnt += 1;
          break;
        }
      }
      if (cnt == 1 && s2 == s1) result = true;
    }
  }
  return result;
}

//Q1.6
string str_comp(const string& s) {
  string result;
  int cnt = 1;
  int i = 0;
  while(i != s.length()) {
    if (s[i] == s[i+1]) cnt += 1;
    else {
      result.push_back(s[i]);
      result += to_string(cnt);
      cnt = 1;
    }
    ++i;
  }
  if (result.length() <= s.length()) return result;
  else return s;
}


//Q1.7
void transpose(vector<vector<int>> v, const int r, const int c) {
  vector<vector<int>> result(r,vector<int> (c,1));
  for (int i = 0; i != r; ++i) {
    for (int j = 0; j != c; ++j) {
      result[i][j] = v[r-1-j][i];
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}


//Q1.8
void set_to_zero(vector<vector<int>> v) {
  int r = static_cast<int> (v.size());
  int c = static_cast<int> (v[0].size());

  vector<int> row, col;
  cout << "the original vector is: " << endl;
  for (int i = 0; i != r; ++i) {
    for (int j = 0; j != c; ++j) {
      cout << v[i][j] << " ";
      if (v[i][j] == 0) {row.push_back(i); col.push_back(j);}
    }
    cout << "\n";
  }

  sort(row.begin(), row.end());
  row.erase(unique(row.begin(), row.end() ), row.end());

  sort(col.begin(), col.end());
  col.erase(unique(col.begin(), col.end() ), col.end());

  for (auto i : row){
    cout << i << endl;
      for (int n = 0; n != c; ++n) v[i][n] = 0;
    }

  for (auto j : col) {
    for (int n = 0; n != r; ++n) v[n][j] = 0;
  }

  cout << "the transformed vector is: \n";

  for (int i = 0; i != r; ++i) {
    for (int j = 0; j != c; ++j) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

//Q1.9 String Rotation: Assume you have a method isSubstring which checks if one word
//is a substring of another. Given two strings, s1 and s2, write code to check
//if s2 is a rotation of s1 using only one call to isSubstring
//(e.g., waterbottle is a rotation of erbottlewat).
bool is_rotation(const string &s1, const string &s2) {
  if (s1.length() != s2.length()) return false;
  else {
    string s = s1 + s1;
    if (isSubstring(s,s2)) return true;
    else return false;
    }
  }
}



//Q6.2
string pick(double p) {
  if (3*p*p - 2*p*p*p - p <0) return "Game 1";
  else if (3*p*p - 2*p*p*p - p > 0) return "Game 2";
  else return "Game1 and Game2 have the same probability\n";
}

//Q12.1
void PrintLK(char * filename, const int k) {
  std::ifstream file(filename);
  if (file.is_open()) {
      std::string line1, line2;
      int cnt1 = 0, cnt2 = 0;
      while (std::getline(file, line1) && !file.eof()) {
          ++cnt1;
      }
      while (std::getline(file, line2) && !file.eof()) {
          ++cnt2;
          while (cnt2 == cnt1 - k) printf("%s", line2.c_str());
      }
      file.close();
  }
}

//Q12.2
void reverse(char * str) {
  int size = 0;
  while ((*str)!= '\0') {
    ++size;
    ++str;
  }
  str -= 1;
  char c[size+1];
  for (int i=0; i != size && (*str)!= '\0' && str != nullptr; --str, ++i) {
    c[i] = *str;
  }
  str += 1;
  c[size+1] = '\0';
  for (int i = 0 ; i != size; ++str, ++i){
    *str = c[i];
  }
}



int main() {
//Q1.1
/*
string s = "kevin";
cout << unique_s(s) << endl;

//Q1.2
string s1, s2;
while (cin >> s1 >> s2 && (s1!= "end" || s2 != "end") {
  cout << permutation(s1, s2) <<endl;
}



//Q1.3
string s;
while (getline (cin,s)) {
  cout <<s << "orginial\n";
  replace(s, 10);
  cout << s << endl;
}

//Q1.4
string s;
while (cin >> s) cout << purpalin(s) <<endl;


//Q1.5
string s1, s2;
while (cin >> s1 >> s2) {
  cout << one_edit(s1, s2) << endl;
}


//Q1.6

string s1;
while (cin >> s1) cout << str_comp(s1) << endl;


//Q1.7
vector<vector<int>> v = { {1,2,3} , {4,5,6} , {7,8,9}};
transpose(v, 3, 3);


//Q1.8
vector<vector<int>> v = {{0,1,2,3}, {2,4,5,7}, {4,6,3,0}};
set_to_zero(v);
*/



/*
//Q6.1
vector<vector <double>> vlight(19, {1,1,1,1,1});
vector<double> vheavy{1.1, 1.1, 1.1, 1.1, 1.1};
vlight.push_back(vheavy);
double sum = 0;
for (int i = 0; i != 20; ++i) {
  sum += (vlight[i][0]*(i+1));
  cout << vlight[i][0]<< endl;
}
cout << sum<< endl;
int result = (sum - 210)/0.1;
cout << "The heavy jar is the " << result << "th\n";


//Q6.2

double p = 0.3;
cout << pick(p) << endl;

//Q6.3 Dominos: There is an 8x8 chessboard in which two diagonally opposite
//corners have been cut off. You are given 31 dominos, and a single domino can
//cover exactly two squares. Can you use the 31 dominos to cover the entire
//board? Prove your answer (by providing an example or showing why it's impossible).
//It is impossible.
//Imagine an 8*8 chessboard. It has blocks with two colors, 32 grey and 32 black(1:1).
//A domino covers two blocks which must be adjecent to each other. Adjecent
//blocks must include a black and a grey block. Two corners have the same color,
// so after corners are cut, there would be 30 grey and 32 black(or 32 grey and 30 black).
// which doesn't match with domino's covering pattern which is grey: black = 1:1.


//Q6.4 Ants on a Triangle: There are three ants on different vertices of a
//triangle. What is the probability of collision (between any two or all of them)
//if they start walking on the sides of the triangle? Assume that each ant
//randomly picks a direction, with either direction being equally likely to be
//chosen, and that they walk at the same speed. Similarly, find the probability
//of collision with n ants on an n-vertex polygon.

// it would be easier to calculate the probability of NOT collision: p(not collision).
// And p(collision) = 1 - p(not collision)
// the only two scenerios that they don't collide is all of them go along one
// direction(either all go clockwise or all go anti-clockwise).
// p(not collision) = (1/2)^3 = 1/8; p(collision) = 1 - p(not collision) = 7/8

//Q6.5 Jugs of Water: You have a five-quart jug, a three-quart jug, and an
//unlimited supply of water (but no measuring cups). How would you come up with
//exactly four quarts of water? Note that the jugs are oddly shaped, such that
//filling up exactly "half" of the jug would be impossible.

//4 = 5-1 or 4 = 3 + 1. So to get 4 quarts of water, we need to get 1 quart somehow.
//1 = 3-(5-3) 4 steps, (5-1) add one more step to 5 steps


//Q6.6 Blue-Eyed Island: A bunch of people are living on an island, when a
//visitor comes with a strange order: all blue-eyed people must leave the island
// as soon as possible. There will be a flight out at 8:00pm every evening.
//Each person can see everyone else's eye color, but they do not know their own
//(nor is anyone allowed to tell them). Additionally, they do not know how many
//people have blue eyes, although they do know that at least one person does.
//How many days will it take the blue-eyed people to leave?

//number of blue-eyed people(BEP):
//One: On 1st night, the BEP look around and see no one else is BEP.
//So he understands that herself/himself is BEP. He leaves on the 1st night.

//Two: 1st night, two BEP (A and B) saw each other. A assumes that B leaves
//tonight while B assumes that A leaves tonight. So none of them leave tonight.
// 2nd day, A sees that B didn't go and B sees that A didn't go. So A and B both
// know that they themselves are BEP. They both leave on the 2nd night.
//...
//n: all the BEPs will leave on the 'n'th night.

//Q6.7 The Apocalypse: In the new post-apocalyptic world, the world queen is
//desperately concerned about the birth rate. Therefore, she decrees that all
//families should ensure that they have one girl or else they face massive fines.
// If all families abide by this policy-that is, they have continue to have
//children until they have one girl, at which point they immediately stop-what
//will the gender ratio of the new generation be? (Assume that the odds of
//someone having a boy or a girl on any given pregnancy is equal.) Solve this
//out logically and then write a computer simulation of it.


*/





/*
//Q12.1 Last K Lines: Write a method to print the last Klines of an input file
//using C++.

//Q12.2 implement a function void reverse(char * str) in C or C++ which reverses
//a null-terminated string
char cstring1[] = {"wei"};
char cstring2[4] = {'w', 'e', 'i'};
char cstring3[4] = {"wei"};
char cstring4[4] = {'w', 'e', 'i', '\0'};

reverse(cstring1);
reverse(cstring2);
reverse(cstring3);
reverse(cstring4);
cout << cstring1 << " " << cstring2  << " " << cstring3  << " " << cstring4 << endl;

*/

//Q12.3 Hash Table vs STL Map: Compare and contrast a hash table and an STL
//map. How is a hash table implemented? If the number of inputs is small, which
//data structure options can be used instead of a hash table?




}
