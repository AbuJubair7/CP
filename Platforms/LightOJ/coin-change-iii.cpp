/**
 *    author:  jubair7
 *    created: 29.08.2024 15:19:48
**/
// using contribution technique
// dp[j] = whether we can make sum j by using ith item
// transition = if the can contribute the ith coin to make sum j then and dp[j] = 0 
// then dp[j] = dp[j-a[i]] = 1 and cnt[j] will increase by 1;
// base case dp[0] = 1 because we can always make sum j by if a[i] = j

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
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {  
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    vector<int> f(k + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
      vector<int> cnt(k + 1);
      for (int j = 1; j <= k; j++) {
        if (j >= a[i] and f[j] == 0 and f[j - a[i]] != 0 and cnt[j - a[i]] < c[i]) {
          f[j] = f[j - a[i]];
          cnt[j] = cnt[j - a[i]] + 1;
        }
      }
    }
    int ans = accumulate(f.begin() + 1, f.end(), 0);
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}

