/*
Author: jubair7
Date: 12 Oct 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while(tt--){
        int n, m;
        cin >> n >> m;
        string x, y;
        cin >> x >> y;
        int ans = 0;
        while (x.length() < y.length()+100 and x.find(y) == string::npos) {
            x += x;
            ans++;
        }
        if (x.find(y) != string::npos) cout << ans << '\n';
        else cout << -1 << '\n';
    }
  return 0;
}