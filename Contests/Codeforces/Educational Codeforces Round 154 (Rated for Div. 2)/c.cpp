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
        string s;
        cin >> s;
        int sorted = 0;
        int notSorted = 0;
        if(s[0] == '0') cout << "NO" << '\n';
        else{
            int cnt = 0;
            int ok = 1;
            for(int i = 0; i<s.length(); i++){
                if(s[i] == '+'){
                    cnt++;
                }else if(s[i] == '-'){
                    cnt--;
                    if(notSorted)
                        cnt--;
                }
                if(s[i] == '0'){
                    notSorted = cnt;
                    if(cnt == 1){
                        ok = 0;
                        break;
                    }
                }else {
                    if(notSorted and cnt >= notSorted){
                        ok = 0;
                        break;
                    }
                }
            }
            if(ok)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
  return 0;
}