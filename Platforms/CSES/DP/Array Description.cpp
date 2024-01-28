/*
Author: jubair7
Date: 28/1/24
*/

/*
* dp[i][j] = number of ways to get 'j' when i-1 state has j/j-1/j+1.
* dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1].
* dp[i][a[i]] = 1 {where a[i] != 0}.
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
  vector<vector<long long>> dp(n, vector<long long>(m+1));
  if (a[0] != 0) {
    dp[0][a[0]] = 1;
  } else {
    for (int i = 1; i<=m; i++) {
      dp[0][i] = 1;
    }
  }
  long long ans = 0;
  for (int i = 1; i<n; i++) {
    if (a[i] != 0) {
      if(a[i] == 1 and a[i] < m) {
          dp[i][a[i]] = (dp[i-1][a[i]]%MOD + dp[i-1][a[i]+1] % MOD) % MOD;
      } else if(a[i] == m and a[i] > 1){
          dp[i][a[i]] = (dp[i-1][a[i]]%MOD + dp[i-1][a[i]-1] % MOD) % MOD;
      } else if (a[i] > 1 and a[i] < m){
          dp[i][a[i]] = (dp[i-1][a[i]]%MOD + dp[i-1][a[i]-1] % MOD + dp[i-1][a[i]+1] % MOD) % MOD;
      } else {
          dp[i][a[i]] = dp[i-1][a[i]] % MOD;
      }
    } else {
      for (int j = 1; j<=m; j++) {
        if(j == 1 and j < m) {
          dp[i][j] = (dp[i-1][j] % MOD + dp[i-1][j+1] % MOD) % MOD;
        } else if(j == m and j > 1){
          dp[i][j] = (dp[i-1][j] % MOD + dp[i-1][j-1] % MOD) % MOD;
        } else if (j > 1 and j < m){
          dp[i][j] = (dp[i-1][j] % MOD + dp[i-1][j+1] % MOD + dp[i-1][j-1] % MOD) % MOD;
        } else {
          dp[i][j] = dp[i-1][j] % MOD;
        }
      }
    }
  }
  for (int i = 1; i<=m; i++) {
    if (dp[n-1][i] != 0) {
      ans = (dp[n-1][i] % MOD + ans % MOD) % MOD;
    }
  }
  cout << ans << '\n';
}