#include <bits/stdc++.h>

using namespace std;

typedef vector<int>::iterator iter_vector;
vector<int> createVector(int n) {
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  return v;
}

int main() {
  int n = 0;
  cin >> n;

  vector<int> v = createVector(n);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    int pos_1_value;

    for (iter_vector j = v.begin(); j != v.end(); j++) {
      if (*j == a) {
        pos_1_value = a;
        v.erase(j);
        break;
      }
    }

    // for (iter_vector i = v.begin(); i != v.end(); i++) {
    //   cout << *i << " ";
    // }

    for (iter_vector j = v.begin(); j != v.end(); j++) {
      if (*j == b) {
        v.insert(++j, pos_1_value);
        break;
      }
    }

    for (iter_vector i = v.begin(); i != v.end(); i++) {
      cout << *i << " ";
    }

    cout << "\n";
  }

  for (iter_vector i = v.begin(); i != v.end(); i++) {
    cout << *i << " ";
  }
}