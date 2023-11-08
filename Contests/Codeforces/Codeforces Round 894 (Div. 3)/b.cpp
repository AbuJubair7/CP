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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;
        vector<int> res;
        res.push_back(arr[0]);
        for(int i = 1; i<n; i++){
            if(arr[i] >= arr[i-1]){
                res.push_back(arr[i]);
            }else{
                res.push_back(arr[i]-1);
                res.push_back(arr[i]);
            }
        }
        cout << res.size() << '\n';
        for(auto i : res){
            if(i == 0) i++;
            cout << i << " ";
        }
        cout << '\n';
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}