// dp[i][j] = minimum operations required when first string has length i
// and second string has length j
// dp[i][j] = dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
// dp[0][i] and dp[i][0] = i
/*
Author: jubair7
Date: 25/7/24
*/
#include<bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int tt;
  tt = 1;
  int tCase = 0;
  while (tt--) {
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      f[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
      f[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i-1] == b[j-1]) {
          f[i][j] = f[i-1][j-1];
        } else {
          f[i][j] = min({f[i-1][j] + 1, f[i][j-1] + 1, f[i-1][j-1] + 1});
        }
      }
    }
    cout << f[n][m] << '\n';
  }
  return 0;
}