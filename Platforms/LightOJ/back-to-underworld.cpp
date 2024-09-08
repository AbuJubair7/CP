/**
 *    author:  jubair7
 *    created: 08.09.2024 12:10:27
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
  const int mx = 2e5 + 1;
  while (tt--) {
    int n;
    cin >> n;
    set<int> node;
    vector<vector<int>> graph(mx);
    vector<int> color(mx, -1);
    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;
      node.insert(u);
      node.insert(v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    auto Bfs = [&](int s) -> int {
      int vamp = 0;
      int lyk = 0;
      queue<int> q;
      q.push(s);
      color[s] = 1;
      vamp++;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : graph[u]) {
          if (color[v] == -1) {
            color[v] = 1 - color[u];
            q.push(v);
            if (color[v] == 0) {
              lyk++;
              continue;
              
            }
            vamp++;
            
          }
        }
      }
      return max(vamp, lyk);
    };
    int ans = 0;
    for (auto u : node) {
      if (color[u] == -1) {
        ans +=  Bfs(u);
      }
    }
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}
