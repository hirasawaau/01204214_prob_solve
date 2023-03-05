/*
Uncompleted
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  unordered_map<char, int> a;
  a['N'] = 0;
  a['E'] = 1;
  a['S'] = 2;
  a['W'] = 3;
  int currentDirection = 0;
  string ans;
  for (int i = 0; i < s.length(); i++) {
    char direction = s.at(i);
    if (a[direction] == currentDirection) {
      ans.append("F");
    } else {
      int diff = currentDirection - a[direction];
    }
    return 0;
  }