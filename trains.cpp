#include <bits/stdc++.h>

using namespace std;

int main() {
  list<int> chan[100000];
  int n;
  cin >> n;
  for (int k = 0; k < n; k++) {
    char c;
    cin >> c;
    switch (c) {
      case 'N': {
        long X;
        int i;
        cin >> X >> i;
        chan[i - 1].push_back(X);
        break;
      }
      case 'M': {
        int i, j;
        cin >> i >> j;
        chan[j - 1].splice(chan[j - 1].end(), chan[i - 1]);

        break;
      }
    }
  }

  for (int i = 0; i < 100000; i++) {
    for (auto j = chan[i].begin(); j != chan[i].end(); j++) {
      cout << *j << "\n";
    }
  }
}