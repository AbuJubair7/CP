/**
 *    author:  jubair7
 *    created: 25.08.2024 09:38:51
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
  while (tt--) {
    int x, k;
    cin >> x >> k;
    string s = to_string(x);
    int n = s.size(); 
    vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(2, vector<int>(k + 1)));
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      int val = s[i-1] - '0';
      for (int sum = 0; sum <= k; sum++) {
        for (int digit = 0; digit < val; digit++) {
          if (sum - digit >= 0) {
            f[i][1][sum] += f[i-1][0][sum - digit];
          }
        }
        for (int digit = 0; digit < 10; digit++) {
          if (sum - digit >= 0) {
            if (digit == val) {
              f[i][0][sum] = f[i - 1][0][sum - digit];
            }
            f[i][1][sum] += f[i-1][1][sum - digit];
          }
        }
      }
    }
    cout << f[n][1][k] + f[n][0][k] << '\n';
  }
  return 0;
}
