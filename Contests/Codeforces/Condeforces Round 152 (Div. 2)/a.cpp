/*
Author: jubair7
Date: 27 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool isSorted(vector<int> &arr){
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

void solve(){
    int t;
    cin >> t;
    while(t--){
       int b, c, h;
       cin >> b >> c >> h;
        b--;
        int ans = 1;
        int total = h+c;
       if(b <= total) ans += (b*2);
       else ans += (total * 2); 
        cout << ans << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}