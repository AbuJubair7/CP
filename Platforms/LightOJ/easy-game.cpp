/**
 *    author:  jubair7
 *    created: 07.10.2024 21:38:38
**/
// dp[i][j] = maximum difference I can make from sub array i to j
// dp[i][j] = d[i][i + k], dp[j - k][j] [i + k <= j and j - k >= i];
// dp[i][i] = a[i];
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      a[i] = a[i - 1] + x;
    }
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int len = 1; len <= n; len++) {
      for (int i = 1, j = i + len - 1; j <= n; i++, j++) {
        f[i][j] = a[j] - a[i - 1];
        for (int k = i; k < j; k++) {
          int val = max(a[k] - a[i - 1] - f[k + 1][j], a[j] - a[k] - f[i][k]);
          f[i][j] = max(f[i][j], val);
        }
      }
    }
    cout << "Case " << ++tCase << ": " << f[1][n] << '\n';
  }
  return 0;
}
