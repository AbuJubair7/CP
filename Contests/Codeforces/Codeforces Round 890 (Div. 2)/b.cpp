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
        int n;
        cin >> n;
        vector<int> arr(n);
        int one = 0;
        long long sum = 0;
        for(auto &i : arr){
            cin >> i;
            if(i == 1) one++;
            else sum += (i-1);
        }
        if(n == 1 or sum < one) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}