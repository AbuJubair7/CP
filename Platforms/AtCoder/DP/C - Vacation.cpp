/**
 *    author:  jubair7
 *    created: 08.10.2024 10:05:06
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
  tt = 1;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(4));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 3; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<long long>> f(n + 1, vector<long long>(4));
    f[1][1] = a[1][1];
    f[1][2] = a[1][2];
    f[1][3] = a[1][3];
    for (int i = 2; i <= n; i++) {
      int x = a[i][1];
      int y = a[i][2];
      int z = a[i][3];
      f[i][1] = max(f[i - 1][2] + x, f[i - 1][3] + x);
      f[i][2] = max(f[i - 1][1] + y, f[i - 1][3] + y);
      f[i][3] = max(f[i - 1][1] + z, f[i - 1][2] + z);
    }
    cout << max({f[n][1], f[n][2], f[n][3]}) << '\n';
  }
  return 0;
}
