/**
 *    author:  jubair7
 *    created: 17.08.2024 12:07:31
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
    vector<vector<int>> couples(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> couples[i][j];
      }
    }
    vector<long long> f(1 << n, -1);
    for (int i = 0; i < n; i++) {
      f[(1 << i)] = couples[0][i];
    }
    for (int boy = 1; boy < n; boy++) {
      vector<long long> ff(1 << n, -1);
      for (int girl = 0; girl < n; girl++) {
        for (int mask = 1; mask < (1 << n); mask++) {
          if (!(mask & (1 << girl)) or f[mask ^ (1 << girl)] == -1) {
            continue;
          }
          ff[mask] = max(ff[mask], f[mask ^ (1 << girl)] + couples[boy][girl]);
        }
      }
      f = ff;
    }
    cout << "Case " << ++tCase << ": " << *max_element(f.begin(), f.end()) << '\n';
  }
  return 0;
}
