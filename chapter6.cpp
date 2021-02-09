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









  return 0;
}
