/*
Author: jubair7
Date: 11/7/24
*/
#include<bits/stdc++.h>
 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<bool> visited(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(2));
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    auto Dfs = [&](auto&& self, int u) -> void {
      visited[u] = true;
      f[u][1] = 1;
      f[u][0] = 0;
      for (int v : g[u]) {
        if (!visited[v]) {
          self(self, v);
          f[u][0] += max(f[v][0], f[v][1]);
          f[u][1] += f[v][0];
        }
      }
    };
    int ans = 0;
    for (int i = 1 ; i <=n; i++) {
      if (!visited[i]) {
        Dfs(Dfs, i);
        ans += max(f[i][0], f[i][1]);
      }
    }
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}
