#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

class DSU {
  vector<int> parent;
  vector<int> rank;

 public:
  DSU(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  };

  int find(int x) {
    if (x == parent[x]) {
      return x;
    }
    return parent[x] = find(parent[x]);
  };

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (rank[x] < rank[y]) {
        swap(x, y);
      }
      parent[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  };
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<tuple<int, int, int> > edges;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_tuple(w, u, v));
  }

  sort(edges.begin(), edges.end());

  int w = 0;
  DSU dsu(N);
  for (auto e : edges) {
    if (dsu.find(get<1>(e)) != dsu.find(get<2>(e))) {
      dsu.unite(get<1>(e), get<2>(e));
      w += get<0>(e);
    }
  }
  cout << w << "\n";

  return 0;
}