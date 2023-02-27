#include <array>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

vector<pair<int, int> > G[200000];

int minArr(vector<int>& Q, int* arr, int size) {
  int min = INT_MAX;
  int index;

  for (auto q : Q) {
    if (arr[q] < min) {
      min = arr[q];
      index = q;
    }
  }

  return index;
}
vector<int> shortestPath(int src, int N, int M) {
  priority_queue<Pair, vector<Pair>, greater<Pair> > pq;

  vector<int> dist(N + 1, INT_MAX);

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    auto i = G[u].begin();
    for (; i != G[u].end(); ++i) {
      int v = (*i).first;
      int weight = (*i).second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  return dist;
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    auto U = make_pair(v, w);
    auto V = make_pair(u, w);

    G[u].push_back(U);
    G[v].push_back(V);
  }

  auto dest = shortestPath(1, N, M);
  cout << dest[N];
  return 0;
}