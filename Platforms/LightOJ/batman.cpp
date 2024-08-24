/**
 *    author:  jubair7
 *    created: 24.08.2024 11:16:26
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
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    int m = b.size();
    int l = c.size();
    vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(m + 1, vector<int>(l + 1, 0)));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int k = 1; k <= l; k++) {
          if (a[i-1] == b[j-1] and b[j-1] == c[k-1]) {
            f[i][j][k] = 1 + f[i-1][j-1][k-1];
            continue;
          }
          f[i][j][k] = max({f[i-1][j][k], f[i][j-1][k], f[i][j][k-1]});
        }
      }
    }
    cout << "Case " << ++tCase << ": " << f[n][m][l] << '\n';
  }
  return 0;
}
