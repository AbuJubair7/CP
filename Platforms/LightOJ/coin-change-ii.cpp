/**
 *    author:  jubair7
 *    created: 22.08.2024 16:13:58
**/
// using contribution technique
// base case dp[i][0] = 1 (becasue we can take the whole sum so far)
// dp[i][j] = we can skip the ith step and take the sum or we can contribute
// i to make sum j. so dp[i][j] = d[i-1][j] + d[i][j - a[i]].
// tansition -> dp[i-1][j] + dp[i][j - a[i]]
// every dp[i][i - a[i]] is always summed up with the previous and current state
// becasue the sum is going 1 to k.
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
    for (int i = 1; i <= n; i++) {  
      cin >> a[i];
    }
    vector<int> f(k + 1);
    int mod = 100000007;
    for (int i = 1; i <= n; i++) {
      vector<int> ff(k + 1);
      ff[0] = 1;
      for (int j = 1; j <= k; j++) {
        ff[j] = f[j] % mod;
        if (j >= a[i]) {
          ff[j] += (ff[j - a[i]]) % mod;
        }
      }
      f = ff;
    }
    cout << "Case " << ++tCase << ": " << f[k] % mod << '\n';
  }
  return 0;
}
