/**
 *    author:  jubair7
 *    created: 13.08.2024 09:14:05
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
    vector<pair<int, int>> gold;
    vector<string> grid(n); 
    for (int i = 0; i < n; i++) {
      cin >> grid[i];
    }
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'x' or grid[i][j] == 'g') {
          gold.emplace_back(i, j);
          start = {i, j};
        }
      }
    }
    auto dis = [&](pair<int, int> p1, pair<int, int> p2) {
      return max(abs(p1.first - p2.first), abs(p1.second - p2.second));
    };
    n = gold.size();
    int inf = 1e9;
    vector<vector<int>> f((1 << 16) + 7, vector<int>(n + 1, inf));
    f[1][0] = 0;
    for (int mask = 3; mask < (1 << n); mask += 2) {
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          for (int j = 0; j < n; j++) {
            if (i != j and (mask & (1 << j))) {
              f[mask][i] = min(f[mask][i], f[mask ^ (1 << i)][j] + dis(gold[i], gold[j]));
            }
          }
        }
      }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
      ans = min(ans, f[(1 << n) - 1][i] + dis(gold[0], gold[i]));
    }
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}
