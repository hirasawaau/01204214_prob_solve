#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  vector<int> m;

  m.push_back(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m.push_back(x);
  }
  int _n = 0;
  vector<int> counts;

  map<int, bool> visited;

  for (int i = 1; i <= n; i++) {
    int S = i;
    int start = m[i];
    int end = m[start];

    int count = 1;
    // cout << "I: " << i << "\n";

    while (1) {
      //   cout << "Start " << start << " End " << end << "\n";
      if (start == S || visited[start]) {
        counts.push_back(count);
        break;
      }
      visited[start] = true;
      start = end;
      end = m[start];
      count++;
    }
  }

  int max = 0;

  for (int i = 0; i < counts.size(); i++) {
    if (counts[i] > max) {
      max = counts[i];
    }
  }
  cout << max << "\n";

  return 0;
}