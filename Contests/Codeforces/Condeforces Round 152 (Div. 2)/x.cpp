/*
Author: jubair7
Date: 29 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

const int mx = 1e7;

bool f(int n, int key){
    if(n == key) return true;
    else if(n%3 || n < key) return false;
    int ok = f(n/3, key);
    if(ok) return ok;
    return f((n/3)*2, key);
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ok = f(n, k);
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}