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
       int n, a, q;
       cin >> n >> a >> q;
       string s;
       cin >> s;
       if(n == a) cout << "YES" << '\n';
       else{
        int tot = a;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '+'){
                a++;
                tot++;
            }else a--;
            if(a == n) break;
        }
        if(a == n) cout << "YES" << '\n';
        else if(tot >= n) cout << "MAYBE" << '\n';
        else cout << "NO" << '\n';
       }
    }
  return 0;
}