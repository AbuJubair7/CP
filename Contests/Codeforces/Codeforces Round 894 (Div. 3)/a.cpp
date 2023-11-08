/*
Author: jubair7
Date: 24 Aug 2023
*/

#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> arr;
        for(int i = 0; i<n; i++){
            string s;
            cin >> s;
            arr.push_back(s);
        }
        if(m < 4) cout << "NO\n";
        else{
            string target = "vika";
            int ind = 0;
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(arr[j][i] == target[ind]){
                        ind++;
                        break;
                    }
                }
                if(ind == 4) break;
            }
            if(ind == 4) cout << "YES\n";
            else cout << "NO" << '\n';
         }
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}