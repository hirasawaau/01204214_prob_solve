#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a[N + 1];
  stack<int> s;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
  }

  int visited[N + 1];
  int in[N + 1];

  vector<int> T;

  for (int i = 0; i < N + 1; i++) {
    in[i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    for (auto u : a[i]) {
      in[u]++;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (in[i] == 0) {
      s.push(i);
    }
  }

  while (!s.empty()) {
    int v = s.top();
    s.pop();

    T.push_back(v);
    for (auto u : a[v]) {
      in[u]--;
      if (in[u] == 0) {
        s.push(u);
      }
    }
  }

  for (auto u : T) {
    cout << u << "\n";
  }

  return 0;
}