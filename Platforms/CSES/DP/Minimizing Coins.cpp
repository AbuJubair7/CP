/*
Author: jubair7
Date: 18/11/23
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  int dp[mx] = {0};
  for (int i = 0; i<n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  dp[0] = 0;
  for (int i = 1; i<=x; i++) {
    int mn = INT_MAX;
    dp[i] = -1;
    for (int j = 0; j<n and arr[j] <= i; j++) {
      mn = min(dp[i-arr[j]] == -1 ? INT_MAX : dp[i-arr[j]], mn);
    }
    if (mn != INT_MAX) {
      dp[i] = mn+1;
    }
  }
  cout << dp[x] << '\n';
}