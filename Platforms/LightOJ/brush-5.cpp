/**
 *    author:  jubair7
 *    created: 03.10.2024 22:21:20
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
    }
    int inf = 1e9;
    vector<int> dis(n + 1, inf);
    auto dijkstra = [&] (int s) -> void {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      dis[s] = 0;
      pq.push({0, 1});
      while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (dis[u] < w) continue;
        for (auto [v, cost] : graph[u]) {
          if (dis[v] > w + cost) {
            dis[v] = w + cost;
            pq.push({dis[v], v});
          }
        }
      }
    };
    dijkstra(1);
    if (dis[n] != inf) {
      cout << "Case " << ++tCase << ": " << dis[n] << '\n';
      continue;
    }
    cout << "Case " << ++tCase << ": " << "Impossible"<< '\n';
  }
  return 0;
}
