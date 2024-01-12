/*
Author: jubair7
Date: 12/1/24
*/
#include<bits/stdc++.h>
using namespace std;

const int MX = 1e5+1;

/*
* dp[i][j] = maximum value can get either taking the ith element
* or skipping the element and take the next element with the same weight.
* dp[i][j] = max of dp[i-1][j] or (price[i] + dp[i-1][j-weight]).
* dp[0][i...x] = because we cannot take any element if nothing left.
*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  int pages[n+1], price[n+1];
  for (int i = 1; i<=n; i++) {
    cin >> price[i];
  }
  for (int i = 1; i<=n; i++) {
    cin >> pages[i];
  } 
  vector<vector<int>> dp(n+1, vector<int>(MX));
  for (int i = 0; i<=x; i++) {
    dp[0][i] = 0;
  }
  for(int i = 1; i<=n; i++) {
    for (int j = 1; j<=x; j++) {
      if (j >= price[i]) {
        dp[i][j] = max(dp[i-1][j], pages[i]+dp[i-1][j-price[i]]);
      } else {
        dp[i][j] = dp[i-1][j];
      } 
    }
  }
  cout << dp[n][x] << '\n';
}