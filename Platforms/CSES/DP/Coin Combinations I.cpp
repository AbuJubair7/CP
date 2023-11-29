/*
Author: jubair7
Date: 29/11/23
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+10;
const int mod = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  for (int i = 0; i<n; i++) cin >> arr[i];
  int dp[mx] = {0};
  dp[0] = 1;
  for (int i = 0; i<=x; i++) {
    if (dp[i] > 0) {
      for (auto coin : arr) {  
        if (i+coin <= x) {
          dp[i+coin] = (dp[i] % mod + dp[i+coin] % mod) % mod;
        }
      }
    }
  }
  cout << dp[x] << '\n';
}