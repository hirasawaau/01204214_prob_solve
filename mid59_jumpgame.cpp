#include <bits/stdc++.h>
#define MAX_ARRAY 20
using namespace std;

int Travel[MAX_ARRAY][MAX_ARRAY];
int n, k;

int r = 1;
bool isTravel(int x, int y) {
  if (y + 1 < n && Travel[x][y + 1] - Travel[x][y] <= k) {
    if (isTravel(x, y + 1)) return true;
  }
  if (x == n - 1 && y == n - 1) return true;
  if (x + 1 < n && Travel[x + 1][y] - Travel[x][y] <= k) {
    if (isTravel(x + 1, y)) return true;
  }

  //   if (x - 1 >= 0 && Travel[x - 1][y] - Travel[x][y] < k) {
  //     cout << "Condition 3"
  //          << "\n";
  //     if (isTravel(x - 1, y)) return true;
  //   }
  //   if (y - 1 >= 0 && Travel[x][y - 1] - Travel[x][y] < k) {
  //     cout << "Condition 4"
  //          << "\n";
  //     if (isTravel(x, y - 1)) return true;
  //   }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  //   cout << k << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> Travel[i][j];
    }
  }

  isTravel(0, 0) ? cout << "yes"
                        << "\n"
                 : cout << "no"
                        << "\n";
  return 0;
}