#include <iostream>
#include <vector>

using namespace std;

bool isBi(vector<int> a[], int v, vector<bool>& visited, vector<int>& c) {
  for (int u : a[v]) {
    if (!visited[u]) {
      visited[u] = true;
      c[u] = !c[v];
      if (!isBi(a, u, visited, c)) {
        return false;
      }
    } else if (c[u] == c[v]) {
      return false;
    }
  }

  return true;
}

int main() {
  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int N, M;
    cin >> N >> M;
    vector<int> a[N + 1];
    for (int j = 0; j < M; j++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }

    vector<bool> visited(N + 1);
    visited[1] = true;
    vector<int> c(N + 1);
    c[1] = 0;

    if (isBi(a, 1, visited, c)) {
      cout << "yes"
           << "\n";
    } else {
      cout << "no"
           << "\n";
    }
  }
}