/**
 *    author:  jubair7
 *    created: 02.10.2024 11:42:21
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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
    }
    vector<int> dis_root(n), dis_last(n), dis_last_last(n);
    vector<bool> visited(n, false);
    int node = 0;
    int val = 0;
    auto Dfs = [&](auto&& self, int u, int cost, vector<int> &d) -> void {
      visited[u] = true;
      for (auto [v, w] : graph[u]) {
        if (!visited[v]) {
          self(self, v, cost + w, d);
        }
      }
      if (cost > val) {
        node = u;
        val = cost;
      }
      d[u] = cost;
    };
    Dfs(Dfs, 0, 0, dis_root);
    visited.clear();
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    Dfs(Dfs, node, 0, dis_last);
    visited.clear();
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    Dfs(Dfs, node, 0, dis_last_last);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = max({dis_root[i], dis_last[i], dis_last_last[i]});
    }
    cout << "Case " << ++tCase << ":\n";
    for (int i = 0; i < n; i++) {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}
