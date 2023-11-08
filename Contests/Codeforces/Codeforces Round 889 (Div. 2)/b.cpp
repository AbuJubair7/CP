/*
Author: jubair7
Date: 5 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        map<char, vector<int>> mp;
        char ch = '$';
        for(int i = 0; i<n; i++) mp[s[i]].push_back(i+1);
        if(mp.size() == 1) cout << 0 << '\n';
        else{
            int dis = INT_MAX;
            for(auto p : mp){
                vector<int> v = p.second;
                int tmp = v[0]-1;
                for(int i = 1; i<v.size(); i++) tmp = max(tmp, v[i]-v[i-1]-1);
                tmp = max(tmp, n-v[v.size()-1]);
                dis = min(tmp, dis);
            }
            if(dis == 1) cout << 1 << '\n';
            else{
                int ans = 0;
                while(dis > 2){
                    dis /= 2;
                    ans++;
                }
                ans += dis;
                cout << ans << '\n';
            }       
        }
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}