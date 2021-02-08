#include<iostream>
#include<vector>
using namespace std;


//Q6.2
string pick(double p) {
  if (3*p*p - 2*p*p*p - p <0) return "Game 1";
  else if (3*p*p - 2*p*p*p - p > 0) return "Game 2";
  else return "Game1 and Game2 have the same probability\n";
}

int main() {
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




return 0;
}
