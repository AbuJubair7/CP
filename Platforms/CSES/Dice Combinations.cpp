/*
Author: jubair7
Date: 14/11/23
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int dp[n+1][1];
    dp[1][0] = 1;
    dp[2][0] = 2;
    for (int i = 3; i<=n; i++) {
        int tot = 0;
        for (int j = 1; j<=min(i-1, 6); j++) {
            tot  = tot % mod + dp[i-j][0] % mod;
            tot %= mod;
        }
        if (i <= 6) tot++;
        tot %= mod;
        dp[i][0] = tot;
    }
    cout << dp[n][0] << '\n';
    return 0;   
}
