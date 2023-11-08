/*
Author: jubair7
Date: 25 Jul 2023
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
        int n;
        cin >> n;
         vector<int> arr(n);
         for(auto &i : arr) cin >> i;
         if(isSorted(arr)){
            int dis = INT_MAX;
            for(int i = 1; i<n; i++){
                dis = min(dis, arr[i]-arr[i-1]);
            }
            cout << (dis/2)+1 << '\n';
         }else cout << 0 << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}