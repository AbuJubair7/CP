// dp[i][j] = maximum value of dp[i-1][j] or dp[i-2][j-1]
// dp[i][j] = if j <= i/2 then got to dp[i-1][j] and dp[i-2][j-1]
// or just go dp[i-2][j-1] (transition)
// dp[1][1] = a[1] as base case
// one small edge is if the greatest sell of lies on either 1 or n
// then we must use two DP to check on both side. To achive this we need to
// use 2 array and decrease either side from both array. 
/*
Author: jubair7
Date: 5/7/24
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
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> a2(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a2[i] = a[i];
    }
    a[n] -= a[1];
    a2[1] -= a2[n];
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    vector<vector<int>> f2(n + 1, vector<int>(n + 1));
    f[1][1] = a[1];
    f2[1][1] = a2[1];
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= (i + 1) / 2; j++) {
        if (j <= i / 2) {
          f[i][j] = max(f[i-1][j], f[i-2][j-1] + a[i]);
          f2[i][j] = max(f2[i-1][j], f2[i-2][j-1] + a2[i]);
        } else {  
          f[i][j] = f[i-2][j-1] + a[i]; 
          f2[i][j] = f2[i-2][j-1] + a2[i];
        }
      }
    }
    int ans = -1;
    for (int i = 1; i <= n/2; i++) {
      ans = max(ans, f[n][i]);
      ans = max(ans, f2[n][i]);
    }
    cout << "Case " << ++tCase << ": " << ans << '\n'; 
  }
  return 0;
}
