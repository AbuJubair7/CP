/*
Author: jubair7
Date: 5/1/24
*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int dp[n+1][n+1];
  for (int i = 1; i<=n; i++) {
    for (int j = 1; j<=n; j++) {
      char ch;
      cin >> ch;
      if (ch == '*') {
        dp[i][j] = 0;
      } else {
        dp[i][j] = -1;
      }
    }
  }
  if (dp[n][n] != 0) dp[n][n] = 1;
  for (int i = n-1; i>=1; i--) {
    if (dp[n][i] != 0) {
      dp[n][i] = dp[n][i+1];
    }
  }
  for (int i = n-1; i>=1; i--) {
    if (dp[i][n] != 0) {
      dp[i][n] = dp[i+1][n];
    }
  }
  for (int i = n-1; i>=1; i--) {
    for (int j = n-1; j>=1; j--) {
      if (dp[i][j] != 0) {
        dp[i][j] = (dp[i+1][j] + dp[i][j+1]) % MOD;
      }
    }
  }
  cout << dp[1][1] << '\n';
}