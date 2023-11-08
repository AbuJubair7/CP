/*
Author: jubair7
Date: 8/11/23
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = ((100 * (100+1))/2) * 2;

int dp[mx][3] = {0};

int goriber_dp(int i, int arr[], vector<int> adj[]) {
    if (adj[i].size() == 0) return arr[i];
    if (dp[i][0] != -1) return dp[i][0];
    if (adj[i].size() == 2) {
        int val1 = goriber_dp(adj[i][0], arr, adj);
        int val2 = goriber_dp(adj[i][1], arr, adj);
        dp[i][0] = max(val1, val2);
    } else {
        dp[i][0] = goriber_dp(adj[i][0], arr, adj);
    }
    return dp[i][0] += arr[i];
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
        int arr[mx+10];
        vector<int> adj[mx];
        dp[1][0] = 0;
        int ind = 1;
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=i; j++) cin >> arr[ind++];
        }
        for (int i = n-1; i>=1; i--) {
            for (int j = 1; j<=i; j++) cin >> arr[ind++];
        }
        ind = 1;
        int l = 2, r = 2;
        for (int i = 1; i<n; i++) {
            l = r, r = l+1;
            for (int j = 1; j<=i; j++) {
                dp[ind][0] = -1;
                adj[ind].push_back(l);
                adj[ind].push_back(r);
                ind++;
                l++;
                r++;
            }
        }
        for (int i = n; i>1; i--) {
            r = l+1;
            for (int j = 1; j<=i; j++) {
                dp[ind][0] = -1;
                if (j == 1) adj[ind].push_back(r);
                else if (j == i) adj[ind].push_back(l);
                else {
                    adj[ind].push_back(l);
                    adj[ind].push_back(r);
                }
                ind++;
                l++;
                r++;
            }
            l--;
        }   
        goriber_dp(1, arr, adj);
        cout << "Case " << tCase++ << ": " <<  max(dp[1][0], arr[1]) << '\n';
    }
    return 0;   
}
