/*
Author: jubair7
Date: 2/11/23
*/
#include <bits/stdc++.h>
using namespace std;

int n1, n2, k1, k2;
int dp[105][105];

int goriber_dp(int totMan, int totHorse, int manTaken, int horseTaken, int ind) {
    cout << "ind: " << ind << " man->" << totMan << " horse->" << totHorse << '\n';
    if (ind == n1+n2) {
        return 1;
    }
    if (dp[ind][totMan] != -1) {
        return dp[ind][totMan];
    }
    dp[ind][totMan-1] = 0;
    dp[ind][totMan] = 0;
    if (totMan-1 >= 0 and manTaken+1 <= k1)
        dp[ind][totMan-1] = goriber_dp(totMan-1, totHorse, manTaken+1, 0, ind+1);
    if (totHorse-1 >= 0 and horseTaken+1 <= k2)
        dp[ind][totMan] = goriber_dp(totMan, totHorse-1, 0, horseTaken+1, ind+1);
    cout << "res: " << ind << ' ' << dp[ind][totMan-1] << ' ' << dp[ind][totMan] << '\n'; 
    return dp[ind][totMan] + dp[ind][totMan-1]; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof dp);
    goriber_dp(n1, n2, 0, 0, 0);
    cout << dp[0][n1] + dp[0][n1-1] << '\n';
    return 0;   
}