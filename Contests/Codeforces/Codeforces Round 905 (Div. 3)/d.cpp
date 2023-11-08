/*
Author: jubair7
Date: 25/10/23
*/

#include <bits/stdc++.h>
using namespace std;

const int tot = 1e5+123;
long long dp[tot] = {0};

long long goriber_dp(int arr[], int n, int i, int taken, int mx) {
    if (i > n) return INT_MAX;
    if (dp[i] != 0) return dp[i];
    long long dis = max(max(arr[i-1], arr[i]), arr[i+1]);
    if (arr[i] <= arr[i-1] or arr[i] <= arr[i+1])
        dp[i] = abs(arr[i]-(dis+1));
    if (i == n-2) {
        dp[i] += goriber_dp(arr, n, i+2, taken+1, mx);
        return dp[i];
    }
    if (i == n or i == n-1) return dp[i];
    int d = n-(i+3)+1;
    if (ceil(d/2.0f)+ taken >= mx) dp[i] += min(goriber_dp(arr, n, i+2, taken+1, mx), goriber_dp(arr, n, i+3, taken+1, mx)); 
    else dp[i] += goriber_dp(arr, n, i+2, taken+1, mx);
    return dp[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while (tt--) {
        int n;
        cin >> n;
        int arr[n+1] = {0};
        memset(dp, 0, sizeof dp);
        for (int i = 1; i<=n; i++) {
            cin >> arr[i];
            dp[i] = 0;
        }
        long long ans = 0;
        int k = ceil((n-2)/2.0f);
        goriber_dp(arr, n-1, 2, 1, k);
        int dis = max(arr[3-1], max(arr[3], arr[3+1]));
        if (arr[3] <= arr[3-1] or arr[3] <= arr[3+1])
            dp[3] = abs(arr[3] - (dis+1));
        if (n&1) {
            ans = dp[2];
        } else if (n-2 == 2) {
            ans = min(dp[2], dp[3]);
        } else {
            if (6 <= n-1) {
                int d = ((n-1) - 6) + 1;
                if (ceil(d/2.0f)+1 >= k) {
                    dp[3] += min(dp[5], dp[6]);
                } dp[3] += dp[5];
            }
            else 
                dp[3] += dp[5];
            ans = min(dp[2], dp[3]);
        } 
        cout << ans << '\n';
    }
    return 0;   
}