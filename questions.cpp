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



//Q6.2
string pick(double p) {
  if (3*p*p - 2*p*p*p - p <0) return "Game 1";
  else if (3*p*p - 2*p*p*p - p > 0) return "Game 2";
  else return "Game1 and Game2 have the same probability\n";
}

//Q12.1Last K Lines: Write a method to print the last Klines of an input file
//using C++.
string printK(int k, string s) {
  int size_line = 0;
  for (auto c : s) {
    if(c == '\n') size_line += 1;
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
*/

//Q1.5




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
