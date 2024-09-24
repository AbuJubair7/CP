/**
 *    author:  jubair7
 *    created: 24.09.2024 16:30:47
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
    vector<bool> visited(n + 1, false);
    vector<int> flow(n + 1);
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
    }
    auto Dfs = [&](auto&& self, int u) -> int {
      visited[u] = true;
      int go = 0;
      for (auto v : graph[u]) {
        if (!visited[v]) {
          go += self(self, v);
        }
      }
      visited[u] =  false;
      flow[u] = go + 1;
      return flow[u];
    };
    int ans = 1;
    int cnt = -1;
    for (int i = 1; i <= n; i++) {
      if (!flow[i]) {
        flow[i] = Dfs(Dfs, i);
        if (flow[i] > cnt) {
          cnt = flow[i];
          ans = i;
        }
      }
    }
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}
