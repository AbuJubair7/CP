/**
 *    author:  jubair7
 *    created: 12.08.2024 16:11:18
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
    vector<int> a(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    vector<long long> f(k + 1);
    int mod = 100000007;
    for (int i = 1; i <= n; i++) {
      vector<long long> ff(k + 1);
      f[0] = 1;
      for (int j = 1; j <= k; j++) {
        for (int cnt = 0; cnt <= c[i] and j - cnt * a[i] >= 0; cnt++) {
          ff[j] += (f[j - cnt * a[i]]) % mod;
        }
      }
      f = ff;
    }
    cout << "Case " << ++tCase << ": " << f[k] % mod << '\n';
  }
  return 0;
}
