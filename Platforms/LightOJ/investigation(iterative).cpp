/**
 *    author:  jubair7
 *    created: 27.08.2024 21:15:29
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
    int a, b, k;
    cin >> a >> b >> k;
    a--;
    string s = to_string(a);
    int n = s.size();
    auto run = [&] () -> int {
      int ans = 0;
      int f[12][2][100][100] = {0};
      f[0][0][0][0] = 1;
      for (int i = 0; i < n; i++) {
        int val = s[i] - '0';
        for (int sum = 0; sum <= 9 * n; sum++) {
          for (int digit = 0; digit <= 9; digit++) {
            for (int mod = 0; mod < k; mod++) {
              int next_mod = (mod * 10 + digit) % k;
              if (digit == val) {
                f[i + 1][0][sum + digit][next_mod] += f[i][0][sum][mod];
              }
              f[i + 1][1][sum + digit][next_mod] += (f[i][1][sum][mod] + (digit < val ? f[i][0][sum][mod] : 0));
            }
          }
        }
      }
      for (int i = 1; i <= n * 9; i++) {
        if (i % k == 0) {
          ans += (f[n][1][i][0] + f[n][0][i][0]);
        }
      }
      return ans;
    };
    int an = 0;
    if (k == 1) {
      an = b - a;
    } else if (k <= 90) {
      int low = a > 0 ? run() : 0;
      s = to_string(b);
      n = s.size();
      int high = run();
      an = high - low;
    }
    cout << "Case " << ++tCase << ": " << an << '\n';
  }
  return 0;
}