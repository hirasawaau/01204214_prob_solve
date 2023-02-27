#include <stdio.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Graph {
 public:
  vector<int> G[200];
  int N, K;
  int dest = 0;
  void addEdge(int u, int v) {
    auto it = find(G[u].begin(), G[u].end(), v);
    if (u == v) {
      return;
    }
    if (it != G[u].end()) {
      return;
    }
    G[u].push_back(v);
    G[v].push_back(u);
  };

  void showGraph() {
    for (int i = 1; i <= this->N; i++) {
      cout << i << ": ";
      for (auto j : G[i]) {
        cout << j << " ";
      }
      cout << "\n";
    }
  };

  vector<int> bfs(int src) {
    vector<int> depth(this->N + 1, INT_MAX);
    queue<int> q;
    int dis = 0;
    q.push(src);

    while (!q.empty()) {
      int popped = q.front();
      q.pop();
      dis++;
      for (auto v : G[popped]) {
        if (depth[v] == INT_MAX) {
          depth[v] = dis;
          q.push(v);
        }
      }
    }

    return depth;
  }
};

int main() {
  int R, C, A, B, X, Y;
  cin >> R >> C >> A >> B >> X >> Y;
  int Map[R][C];
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> Map[r][c];
    }
  }

  Graph g;

  g.N = R * C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (i + 1 < R && Map[i + 1][j] != Map[i][j]) {
        g.addEdge(Map[i][j], Map[i + 1][j]);
      }
      if (j + 1 < R && Map[i][j + 1] != Map[i][j]) {
        g.addEdge(Map[i][j], Map[i][j + 1]);
      }
    }
  }

  int src = Map[A][B];
  int dest = Map[X][Y];

  vector<int> d = g.bfs(src);

  cout << d[dest];
  return 0;
}