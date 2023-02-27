#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> bowls;
  int n;
  cin >> n;

  for(int i=0 ; i<n ; i++) {
    int x;
    cin >> x;
    bowls.push_back(x);
  }

  sort(bowls.begin(), bowls.end());
  int groups = 0;
  int attempts = 0;
  int index = bowls[n-1];
  for(int i=n-1 ; i>=0 ; i--) {
    if(bowls[i] != index) {
      index = bowls[i];
      attempts = 0;
    }
    attempts++;
    if(attempts > groups){
      groups++;
    }
  }


  cout << groups << endl;
  return 0;
}
