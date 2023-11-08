/*
Author: jubair7
Date: 31 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool is_Prime(int n){
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        string s;
        cin >> s;
        string tmp = "";
        for(int i = 0; i<s.length()-1; i++){
            for(int j = i+1; j<s.length(); j++){
                tmp += s[i];
                tmp += s[j];
                if(is_Prime(stoi(tmp))){
                    ans = stoi(tmp);
                    break;
                }
                tmp = "";
            }
            if(ans) break;
        }
        if(ans) cout << ans << '\n';
        else cout << -1 << '\n';
    }
  return 0;
}