/**
 *    author:  jubair7
 *    created: 15.09.2024 08:51:30
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
    cin >> m >> n;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<vector<long long>>> f(n + 1, vector<vector<long long>>(n * 9 + 1, vector<long long>(m + 1, 0)));
    for (int i = 1; i <= m; i++) {
      f[1][a[i]][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int sum = 1; sum <= 9 * n; sum++) {
        for (int j = 1; j <= m; j++) {
          if (a[j] <= sum) {
            for (int k = max(1, j - 2); k <= min(m, j + 2); k++) {
              if (abs(a[k] - a[j]) <= 2) {
                f[i][sum][j] += f[i - 1][sum - a[j]][k];
              }
            }
          }
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= 9 * n; i++) {
      for (int j = 1; j <= m; j++) {
        ans += f[n][i][j];
      }
    }
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}
