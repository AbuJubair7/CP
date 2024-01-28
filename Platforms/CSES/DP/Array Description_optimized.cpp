/*
Author: jubair7
Date: 28/1/24
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int MOD = 1e9+7;
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i<n; i++) {
    cin >> a[i];
  }
  vector<long long> dp(m+1);
  if (a[0] != 0) {
    dp[a[0]] = 1;
  } else {
    for (int i = 1; i<=m; i++) {
      dp[i] = 1;
    }
  }
  long long ans = 0;
  for (int i = 1; i<n; i++) {
    vector<long long> curr(m+1);
    if (a[i] != 0) {
      if(a[i] == 1 and a[i] < m) {
          curr[a[i]] = (dp[a[i]]%MOD + dp[a[i]+1] % MOD) % MOD;
      } else if(a[i] == m and a[i] > 1){
          curr[a[i]] = (dp[a[i]]%MOD + dp[a[i]-1] % MOD) % MOD;
      } else if (a[i] > 1 and a[i] < m){
          curr[a[i]] = (dp[a[i]]%MOD + dp[a[i]-1] % MOD + dp[a[i]+1] % MOD) % MOD;
      } else {
          curr[a[i]] = dp[a[i]] % MOD;
      }
    } else {
      for (int j = 1; j<=m; j++) {
        if(j == 1 and j < m) {
          curr[j] = (dp[j] % MOD + dp[j+1] % MOD) % MOD;
        } else if(j == m and j > 1){
          curr[j] = (dp[j] % MOD + dp[j-1] % MOD) % MOD;
        } else if (j > 1 and j < m){
          curr[j] = (dp[j] % MOD + dp[j+1] % MOD + dp[j-1] % MOD) % MOD;
        } else {
          curr[j] = dp[j] % MOD;
        }
      }
    }
    dp = curr;
  }
  for (int i = 1; i<=m; i++) {
    if (dp[i] != 0) {
      ans = (dp[i] % MOD + ans % MOD) % MOD;
    }
  }
  cout << ans << '\n';
}