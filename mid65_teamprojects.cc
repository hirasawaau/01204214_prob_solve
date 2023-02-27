#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Graph {
 public:
  int colors[200000];
  vector<int> G[200000];
  int N, K;
  void addEdge(int u, int v);

  void setColors() {
    for (int i = 1; i <= this->N; i++) {
      if (G[i].size() >= K) {
        colors[i] = 2;
      }
    }
  }

  bool isBipartite(int src);

  Graph(int n, int k);

  void showGraph() {
    for (int i = 1; i <= this->N; i++) {
      cout << i << ": ";
      for (auto j : G[i]) {
        cout << j << " ";
      }
      cout << "\n";
    }
  };

  void reductGraph() {
    int start = 2;
    for (int i = 1; i <= N; i++) {
      if (G[i].size() >= K) {
        colors[i] = ++start;
      }
    }
  }

  void showColor() {}
};

Graph::Graph(int n, int k) {
  this->N = n;
  this->K = k;

  for (int i = 1; i <= N; i++) {
    colors[i] = -1;
  }
}

void Graph::addEdge(int u, int v) {
  this->G[u].push_back(v);
  this->G[v].push_back(u);
}

bool Graph::isBipartite(int src) {
  if (this->colors[src] < 0) {
    this->colors[src] = 1;
  }
  queue<int> q;
  q.push(src);
  vector<pair<int, int> > results;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : G[u]) {
      if (v == u) {
        return false;
      }
      if (colors[v] == -1) {
        if (colors[u] <= 1) {
          colors[v] = 1 - colors[u];
        }
        q.push(v);
      } else if (colors[u] == colors[v]) {
        // cout << "B " << u << "," << v << "\n";

        // cout << "\n";
        return false;
      }
    }
  }

  return true;
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  Graph g(N, K);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }
  //   g.showGraph();
  g.reductGraph();
  cout << (g.isBipartite(1) ? "yes" : "no") << "\n";
  return 0;
}