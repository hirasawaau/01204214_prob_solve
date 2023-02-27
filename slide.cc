#include <iostream>
using namespace std;

int main() {
  int n;
  int count = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int pk;
  for (int i = 0; i < n; i++) {
    pk = a[i];
    for (int j = i + 1; j < n; j++) {
      if (pk < a[j]) {
        count++;
      }
    }
  }

  cout << count;
  return 0;
}