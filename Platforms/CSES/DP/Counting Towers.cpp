/*
Author: jubair7
Date: 10/2/24
*/
#include<bits/stdc++.h>
 
using namespace std;

/*
* dp[i][0] = number of ways to make the tower such that there is 1*1 blocks
* is trying to push up
* dp[i][1] = number of ways to make the tower such that there is 1*2 block
* is trying to push up
*
* dp[i][0] = (4*dp[i-1][0] + dp[i-1][1])
* dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])
*
* dp[0][0] = 1 // one way to push 1*1 blocks from base
* dp[0][1] = 1 // one way to push 1*2 block from base
*/ 

const int MOD = 1e9+7;
vector<vector<int>> dp(1e6+1, vector<int>(2));
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
      dp[i][0] = (4ll * dp[i-1][0] + dp[i-1][1]) % MOD;
      dp[i][1] = (2ll * dp[i-1][1] + dp[i-1][0]) % MOD;
    }
    cout << (dp[n-1][0] + dp[n-1][1]) % MOD << '\n';
  }
}