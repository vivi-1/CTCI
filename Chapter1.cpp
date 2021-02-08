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
*/





return 0;
}
