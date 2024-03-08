/*
Author: jubair7
Date: 4/3/24
*/
#include<bits/stdc++.h>
 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  int tCase = 1;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n+1);
    long long sum = 0;
    for (int i = 1; i<=n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    vector<vector<int>> adj(n+1);
    map<pair<int, int>, string> mp;
    for (int i = 1; i<n; i++) {
      int u, v;
      string x;
      cin >> u >> v >> x;
      adj[u].push_back(v);
      adj[v].push_back(u); 
      mp[{u, v}] = x;
    }
    vector<long long> tot(n+1);
    function<long long(int, int)> Dfs = [&](int p, int u) {
      long long curr = a[u];
      for (auto v : adj[u]) {
        if (v != p) {
          curr += Dfs(u, v);
        }
      }
      tot[u] = curr;
      return curr;
    };
    Dfs(-1, 1);
    string ans = "zzzzzzzzzz";
    long long val = LONG_LONG_MAX;
    for (auto [x, y] : mp) {
      int u = x.first , v = x.second;
      if (tot[u] < tot[v]) swap(u, v);
      long long a = tot[v];
      long long b = sum-a;
      long long dis = abs(a-b);
      if (dis < val or (dis == val and y <= ans)) {
          val = dis;
          ans = y;
      }
    }
    cout << "Case " << tCase++ << ": " << (n == 1 ? "" : ans) << '\n';
  }
}