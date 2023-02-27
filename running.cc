#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ulli;

int main() {
  ulli r = 1;
  vector<ulli> v;
  ulli n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    ulli x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  for (ulli i = 1; i < v.size(); i++) {
    if (v[0] * k <= v[i] * (k - 1)) {
      v[i] = -1;
    }
  }

  // for (int i = 2; i <= k; i *= 2) {
  //   for (int j = 0; j < v.size(); j++) {
  //     if (v.at(0) * i <= v.at(j) * (i - 1)) {
  //       v[j] = -1;
  //     }
  //   }
  // }

  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) != -1) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}
