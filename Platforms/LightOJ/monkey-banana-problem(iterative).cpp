/*
Author: jubair7
Date: 9/11/23
*/

#include <bits/stdc++.h>
using namespace std;

int mx = (100*(100+1)/2) * 2;

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
        int tot = ((n*(n+1))/2) * 2 - n;
        int ind = 1;
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=i; j++) cin >> arr[ind++];
        }
        for (int i = n-1; i>=1; i--) {
            for (int j = 1; j<=i; j++) cin >> arr[ind++];
        }
    	int dp[mx][3];
    	dp[tot][0] = arr[tot];
        ind = 1;
        int l = 2, r = 2;
        for (int i = 1; i<n; i++) {
            l = r, r = l+1;
            for (int j = 1; j<=i; j++) {
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
        for (int i = tot-1; i>=1; i--) {
        	int mx = 0;
        	for (auto k : adj[i])
        		mx = max(dp[k][0], mx);
        	dp[i][0] = arr[i] + mx; 
        }   
        cout << "Case " << tCase++ << ": " <<  max(dp[1][0], arr[1]) << '\n';
    }
    return 0;   
}
