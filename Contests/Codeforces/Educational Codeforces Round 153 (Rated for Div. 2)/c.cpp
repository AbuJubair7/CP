/*
Author: jubair7
Date: 21 Aug 2023
*/

#include <bits/stdc++.h>
 
using namespace std;

int ans = 0;

void f(string s, int n, int pos, int dp[], int visited[]){
    if(pos >= n-1) return;
    else if(visited[pos] == 1) return;
    visited[pos] = 1;
    int ind = s.find(s[pos], pos+1);
    if(ind == string::npos){
        f(s, n, pos+1, dp, visited);
        dp[pos] = dp[pos+1];
        //cout << "heree: " << pos+1 << '\n';
    }else{
        //cout << "taking: " << s[pos] << "->" << ind << '\n';
        f(s, n, ind+1, dp, visited);
        f(s, n, pos+1, dp, visited);
        if(ind+1 < n)
            dp[pos] = max(dp[ind+1], dp[pos+1]);
        else dp[pos] = dp[pos+1];
        // dp[pos][1] += 2;
        if(dp[ind+1] >= dp[pos+1])
            dp[pos] += 2;
        //cout << ind+1 << " " << pos+1 << '\n';
        //cout << "tot-->" << dp[ind+1] << ", " << dp[pos+1] << '\n';
        //cout << "score: " << s[pos] << "->" <<  dp[pos] << '\n';
    }
    ans = max(ans, dp[pos]);
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int visited[s.length()];
        int dp[s.length()+12] = {0};
        memset(dp, 0, sizeof dp);
        memset(visited, 0, sizeof visited);
       // for(int i = 0; i<s.length(); i++) cout << dp[i] << '\n';
        //cout << dp[0] << '\n';
        ans = 0;
        f(s, s.length(), 0, dp, visited);
        cout << s.length()-ans << '\n';
        //cout << ans << '\n';
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}