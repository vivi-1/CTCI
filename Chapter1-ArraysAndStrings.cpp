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


//Q1.7

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
return 0;
}
