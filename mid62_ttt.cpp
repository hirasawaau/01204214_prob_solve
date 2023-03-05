#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Graph {
 private:
  vector<int> a[20000];
  vector<bool> visited;
  vector<int> c;

 public:
  void addEdge(pair<int, int>& p) {
    a[p.first].push_back(p.second);
    a[p.second].push_back(p.first);
  };

  bool isBi(int v) {
    for (int u : a[v]) {
      if (!visited[u]) {
        visited[u] = true;
        c[u] = !c[v];
        if (!isBi(u)) {
          return false;
        }
      } else if (c[u] == c[v]) {
        return false;
      }
    }

    return true;
  }

  Graph() {
    this->visited = vector<bool>(1001, false);
    this->c = vector<int>(1001);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > m;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    pair<int, int> p = make_pair(u, v);
    m.push_back(p);
  }

  for (int i = 0; i < M; i++) {
    Graph g;
    for (int j = 0; j < M; j++) {
      if (i != j) {
        g.addEdge(m[j]);
      }
    }
    bool isBi = g.isBi(1);
    if (isBi) {
      cout << m[i].first << " " << m[i].second << "\n";
    }
  }
  return 0;
}