/*
Author: jubair7
Date: 31 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       map<int, int> mp;
       vector<int> arr(n+1);
       int ans = 0;
       for(int i = 1; i<=n; i++){
        cin >> arr[i];;
        mp[arr[i]] = i;
       }
       for(int i = n; i>=2; i--){
        if(mp[i] < mp[i-1])
            ans++;
       }
       cout << ans << '\n';
    }
  return 0;
}