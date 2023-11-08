/*
Author: jubair7
Date: 13 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int> a(n);
      vector<int> b(n);
      int ok = 1;
      for(auto &i : a) cin >> i;
      for(int i = 0; i<n; i++){
        cin >> b[i];
        if(a[i] > b[i]) ok = 0;
      }
      if(ok){
        if(a[n-1] != b[n-1] and b[0] < b[n-1] and b[n-1]-b[0] > 1) ok  = 0;
        for(int i = 0; i<n-1 and ok; i++){
          if(a[i] != b[i]){
            if(b[i] > b[i+1] and b[i]-b[i+1] > 1)
              ok = 0;
          }
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
      }else cout << "NO" << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}