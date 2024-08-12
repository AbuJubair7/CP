/**
 *    author:  jubair7
 *    created: 12.08.2024 13:02:53
**/
// how many N length numbers are there which has every digit at least once?
// No leading zero are allowed 
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
    int n;
    cin >> n;
    vector<vector<long long>> f(n + 1, vector<long long>((1 << 10) + 7, 0));
    for (int i = 1; i < 10; i++) {
      f[1][1 << i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int mask = 1; mask < (1 << 10); mask++) {
        for (int j = 0; j < 10; j++) {
          if (f[i-1][mask] != 0) {
            f[i][mask | (1 << j)] += f[i-1][mask];
          }
        }
      }
    }
    cout << f[n][(1 << 10) - 1] << '\n';
  }
  return 0;
}
