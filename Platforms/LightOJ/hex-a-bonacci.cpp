/**
 *    author:  jubair7
 *    created: 17.09.2024 15:25:38
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
    vector<long long> f(10000 + 10);
    int mod = 10000007;
    for (int i = 0; i < 6; i++) {
      cin >> f[i];
      f[i] %= mod;
    }
    cin >> n;
    for (int i = 6; i <= n; i++) {
      for (int j = 1; j <= 6; j++) {
        f[i] = (f[i] % mod + f[i - j] % mod) % mod;
      }
    }
    cout << "Case " << ++tCase << ": " << f[n] << '\n';
  }
  return 0;
}
