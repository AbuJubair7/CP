/*
Author: jubair7
Date: 17 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s == "()") cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            string s1 = ""; string s2 = "";
            for(int i = 1; i<=s.length()*2; i++){
                if(i <= s.length()) s2 += '(';
                else s2 += ')';
                if(i%2 == 1)
                    s1 += '(';
                else s1 += ')';
            }
            if(s1.find(s) == string::npos) cout << s1 << '\n';
            else cout << s2 << '\n';
        }
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}