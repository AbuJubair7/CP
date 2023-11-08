/*
Author: jubair7
Date: 15 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int win = 1;
        if(c % 2 == 1 and a == b){
            cout << "First\n";
        }else if(c % 2 == 0 and a == b)
            cout << "Second\n";
        else if(a > b) cout << "First\n";
        else cout << "Second\n";
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}