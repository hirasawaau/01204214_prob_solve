#include <bits/stdc++.h>

using namespace std;

int main() {
  set<int> s;
  vector<int> r;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    r.push_back(x);
  }

  for (auto i = r.begin(); i != r.end(); i++) {
    s.insert(*i);
    for (auto j = r.end(); j != i; j--) {
      int sum = accumulate(i, j, 0);
      s.insert(sum);
    }
  }
  cout << s.size() << endl;
}