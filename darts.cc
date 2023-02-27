#include<iostream>
#include<cmath>
using namespace std;

double len(int x , int y){
  return sqrt(x*x + y*y);
}

int getScore(double l){
  if(l <= 2) return 5;
  if(l <= 4) return 4;
  if(l <= 6) return 3;
  if(l <= 8) return 2;
  if(l <= 10) return 1;
  return 0;
}

int main() {
  int score = 0;
  int n;
  cin >> n;
  for(int i=0 ; i<n ; i++){
    int x,y;
    cin >> x >> y;
    score += getScore(len(x,y));
  }

  cout << score << endl;
  return 0;
}
