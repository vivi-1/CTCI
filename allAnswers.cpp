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


//Q6.2
string pick(double p) {
  if (3*p*p - 2*p*p*p - p <0) return "Game 1";
  else if (3*p*p - 2*p*p*p - p > 0) return "Game 2";
  else return "Game1 and Game2 have the same probability\n";
}

//Q12.1Last K Lines: Write a method to print the last Klines of an input file
//using C++.
//string printK(int k, string s) {
//  int size_line = 0;
//  for (auto c : s) {
//    if(c == '\n') size_line += 1;
//  }
//}


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
*/

//Q1.8


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

*/

//Q12.Last K Lines: Write a method to print the last Klines of an input file
//using C++.





}
