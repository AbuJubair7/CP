/**
 *    author:  jubair7
 *    created: 10.10.2024 17:15:10
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
    vector<vector<int>> graph(n + 1);
    map<pair<int, int>, int> cost;
    for (int i = 0; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back(v);
      graph[v].push_back(u);
      cost[{u, v}] = w;
    }
    int s1 = graph[1][0];
    int s2 = graph[1][1];
    vector<bool> visited(n + 1);
    visited[1] = true;
    auto Dfs = [&] (auto&& self, int u) -> int {
      visited[u] = true;
      int c = 0;
      for (auto v : graph[u]) {
        if (!visited[v]) {
          c += cost[{v, u}];
          c += self(self, v);
        }
      }
      return c;
    };
    int c1 = cost[{s1, 1}] + Dfs(Dfs, s1) + cost[{1, s2}];
    visited.clear();
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    visited[1] = true;
    int c2 = cost[{s2, 1}] + Dfs(Dfs, s2) + cost[{1, s1}];
    cout << "Case " << ++tCase << ": " << min(c1, c2) << '\n';
  }
  return 0;
}
