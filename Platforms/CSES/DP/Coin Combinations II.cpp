/*
Author: jubair7
Date: 2/12/23
*/
 
/*
dp[i][j] = how many ways to get sum j by taking coin i or by skipping coin i
and starting from i+1
base case dp[i][0] = 1; by skipping coin i
also dp[0][j] = 0; because we have no coin
*/
#include <bits/stdc++.h>
using namespace std;
 
const int mx = 1e6+10;
const int MOD = 1e9+7;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> arr(n+1);
  for (int i = 1; i<=n; i++) cin >> arr[i];
  int dp[n+1][x+1] = {0};
  for (int i = 1; i<=n; i++) {
    for (int j = 0; j<=x; j++) {
      if (j == 0) {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] = ((arr[i] <= j ? dp[i][j-arr[i]] : 0) + (i-1 <= 0 ? 0 : dp[i-1][j])) % MOD ;
    }
  }
  cout << dp[n][x] << '\n';
}