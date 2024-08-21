/*
Author: jubair7
Date: 7/6/24
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
  int tCase = 1;
  while (tt--) {
    int n, r, s, d;
    cin >> n >> r;
    vector<int> adj[n + 7];
    for (int i = 0; i < r; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> start(n + 7);
    vector<int> end(n + 7);
    function<void(int, bool)> Bfs = [&] (int p, bool first) {
      vector<bool> visited(n);
      queue<int> q;
      q.push(p);
      visited[p] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
          if (!visited[v]) {
            visited[v] = true;
            if (first) {
              start[v] = start[u] + 1;
            } else {
              end[v] = end[u] + 1;
            }
            q.push(v);
          }
        }
      }
    };
    cin >> s >> d;
    Bfs(s, true);
    Bfs(d, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, start[i] + end[i]);
    }
    cout << "Case " << tCase++ << ": " <<  ans << '\n';
  }
  return 0;
}
