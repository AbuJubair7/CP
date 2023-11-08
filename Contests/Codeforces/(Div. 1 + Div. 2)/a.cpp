/*
Author: jubair7
Date: 26 Aug 2023
*/

#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
      int x, y, n;
      cin >> x >> y >> n;
      vector<int> arr;
      int ok = 1;
      int tmp = y;
      for(int i = 2; i<n and ok; i++){
        y -= (i-1);
        if(y <= x) ok = 0;
        arr.push_back(y);
      }
      arr.push_back(x);
      reverse(arr.begin(), arr.end());
      arr.push_back(tmp);
      if(!ok or (arr[1]-arr[0] <= arr[2]-arr[1])) cout << -1 << '\n';
      else{
        for(auto i : arr)
          cout << i << ' ';
        cout << '\n';
      }
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}