/**
 *    author:  jubair7
 *    created: 09.09.2024 16:28:22
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
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> cost[i][j];
      }
    }
    const int inf = 1e9;
    vector<long long> f(1 << n, inf);
    f[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) continue;
        long long tot = f[mask ^ (1 << i)] + cost[i][i];
        for (int j = 0; j < n; j++) {
          if (!(mask & (1 << j)) or i == j) continue;
          tot += cost[i][j];
        }
        f[mask] = min(f[mask], tot);
      }
    }
    cout << "Case " << ++tCase << ": " << f[(1 << n) - 1] << '\n';
  }
  return 0;
}
