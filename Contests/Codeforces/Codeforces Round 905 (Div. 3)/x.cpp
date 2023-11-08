/*
Author: jubair7
Date: 28/10/23
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8;
int dp[205][205] = {0};
int n1, n2, k1, k2;

void goriber_dp( int man, int horse, int manTaken, int horseTaken, int ind) {
    if (ind > n1+n2) return;
    if (dp[ind][1][man] != -1 and dp[ind][2][horse] != -1)
        return;
    if (ind == n1+n2) {
        if (man + 1 <= n1 and manTaken+1 <= k1)
            dp[ind][1][man+1]
    }
    if (man + 1 <= n1 and manTaken+1 <= k1) {
        man++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n1 >> n2 >> k1 >> k2;
    if (abs(n1/k1 - n2/k2) > 1) cout << 0 << '\n';
    else {
        memset(dp, -1, sizeof dp);

        goriber_dp(0, 0, 0, 0, 1);
        for (int i = 1; i<=n1+n2; i++) {
            for (int j = 1; j<=2; j++)
                cout << dp[i][j] << ' ';
            cout << '\n';
        }
        long long ans = dp[1][1] + dp[1][2] - 1;
        cout << ans << '\n';
        cout << (ans * 2) % mod +1 << '\n';
    }
    return 0;   
}