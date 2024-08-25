/**
 *    author:  jubair7
 *    created: 25.08.2024 09:38:51
**/
// https://www.spoj.com/problems/PR003004/
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
    long long a, b;
    cin >> a >> b;
    a--;
    string s = to_string(a);
    string ss = to_string(b);
    int n = a < 0 ? 0 : s.size(); 
    int m = ss.size();
    vector<vector<vector<long long>>> f(n + 1, vector<vector<long long>>(2, vector<long long>(9 * n + 1))), ff(m + 1, vector<vector<long long>>(2, vector<long long>(9 * m + 1)));
    f[0][0][0] = 1;
    ff[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      int val = s[i-1] - '0';
      for (int sum = 0; sum <= 9 * n; sum++) {
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
    for (int i = 1; i <= m; i++) {
      int val = ss[i-1] - '0';
      for (int sum = 0; sum <= 9 * m; sum++) {
        for (int digit = 0; digit < val; digit++) {
          if (sum - digit >= 0) {
            ff[i][1][sum] += ff[i-1][0][sum - digit];
          }
        }
        for (int digit = 0; digit < 10; digit++) {
          if (sum - digit >= 0) {
            if (digit == val) {
              ff[i][0][sum] = ff[i - 1][0][sum - digit];
            }
            ff[i][1][sum] += ff[i-1][1][sum - digit];
          }
        }
      }
    }
    long long low = 0, high = 0;
    for (int i = 1; i <= 9 * n; i++) {
      low += (1ll * f[n][0][i] + f[n][1][i]) * i;
    }
    for (int i = 1; i <= 9 * m; i++) {
      high += (1ll * ff[m][0][i] + ff[m][1][i]) * i;
    }
    cout << high - low << '\n';
  }
  return 0;
}
