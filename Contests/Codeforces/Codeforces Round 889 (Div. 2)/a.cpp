/*
Author: jubair7
Date: 29 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int de = 0;
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            if(x == i) de++;
        }
        int ans = 0;
        while(de > 0){
            de-=2;
            ans++; 
        }
        cout << ans << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}