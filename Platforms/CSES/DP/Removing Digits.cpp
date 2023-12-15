/*
Author: jubair7
Date: 15/12/23
*/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6+5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int dp[MX];
  for (int i = 1; i<=19; i++) {
    if (i < 10) {
      dp[i] = 1;
    } else if (i == 10) {
      dp[i] = 2;
    } else {
      dp[i] = 3;
    }
  }
  for (int i = 20; i<=n; i++) {
    int k = i;
    dp[i] = INT_MAX-1;
    while (k > 0) {
      dp[i] = min(dp[i], dp[i - (k%10)] + 1);
      k /= 10;
    }
  }
  cout << dp[n] << '\n';
}