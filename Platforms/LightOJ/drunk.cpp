/**
 *    author:  jubair7
 *    created: 16.09.2024 01:39:29
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
    int m;
    cin >> m;
    set<string> drinks;
    map<string, vector<string>> graph;
    map<string, int> col;
    bool ok = true;
    for (int i = 0; i < m; i++) {
      string u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      drinks.insert(u);
      drinks.insert(v);
      col[u] = -1;
      col[v] = -1;
    }
    auto Dfs = [&](auto&& self, string u) {
      if (!ok) return;
      col[u] = 0;
      for (auto v : graph[u]) {
        if (col[v] == -1) {
          self(self, v);
        } else if (col[v] == 0) {
          ok = false;
          return;
        }
      }
      col[u] = 1;
    };
    for (auto i : drinks) {
      if (col[i] == -1) {
        Dfs(Dfs, i);
      }
    }
    cout << "Case " << ++tCase << ": " << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}
