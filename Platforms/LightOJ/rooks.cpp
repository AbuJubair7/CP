/**
 *    author:  jubair7
 *    created: 20.08.2024 02:47:55
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
    int n, k;
    cin >> n >> k;
    vector<long long> f(n + 1);
    for (int i = 0; i <= n; i++) {
      f[i] = 1;
    }
    for (int rock = 1; rock <= k; rock++) {
      vector<long long> ff(n + 1);
      for (int row = rock; row <= (n - k + rock); row++) {
        ff[row] = ff[row-1] + (f[row-1] * (n - rock+1));
      }
      f = ff;
    }
    cout << "Case " << ++tCase << ": " << f[n] << '\n';
  }
  return 0;
}
