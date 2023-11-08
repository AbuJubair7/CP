/*
Author: jubair7
Date: 12 Aug 2023
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
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if(arr[0] == arr[n-1]) cout << -1 << '\n';
    else{
      int i = n-1;
      vector<int> f;
      vector<int> s;
      while(i > 0){
        if(arr[i] > arr[i-1]){
          f.push_back(arr[i]);
          i--;
          break;
        }else f.push_back(arr[i]);
        i--;
      }
      while(i >= 0){
        s.push_back(arr[i]);
        i--;
      }
      cout << s.size() << " " << f.size() << "\n";
      for(auto i : s) cout << i << ' ';
      cout << '\n';
      for(auto i : f) cout << i << ' ';
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