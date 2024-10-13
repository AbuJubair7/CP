/**
 *    author:  jubair7
 *    created: 13.10.2024 15:30:19
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
    vector<int> max_path(n + 1, inf);
    auto dijkstra = [&] (int s) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      max_path[s] = 0;
      pq.push({0, s});
      while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        for (auto [v, c] : graph[u]) {
          if (max(c, w) < max_path[v]) {
            max_path[v] = max(c, w);
            pq.push({max(c, w), v});
          }
        }
      }
    };
    int s;
    cin >> s;
    dijkstra(s);
    cout << "Case " << ++tCase << ":" << '\n';
    for (int i = 0; i < n; i++) {
      if (max_path[i] != inf) cout << max_path[i] << '\n';
      else cout << "Impossible" << '\n';
    }
  }
  return 0;
}
