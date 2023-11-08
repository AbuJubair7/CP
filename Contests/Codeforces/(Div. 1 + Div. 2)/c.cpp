/*
Author: jubair7
Date: 28 Aug 2023
*/

#include <bits/stdc++.h>
 
using namespace std;
   
int main() {
int m, s;
cin >> m >> s;
int tot = s;
if(s == 0 and  != 1 or (m*9) < s) cout << "-1 -1" << '\n';
else{
    string mx = "";
    for(int i = 1; i<=m; i++){
        if(s > 9){
            mx += '9';
            s -= 9;
        }
        else if(s > 0){
            mx += ((char)(s + '0'));
            s = 0;
        }else mx += ((char)(s + '0'));
    }
    string mn = "";
    for(int i = m; i>=1; i--){
        if(i == 1) mn += ((char)((tot) + '0'));
        else if(tot > 9){
            mn += '9';
            tot -= 9;
        }else if(tot > 1){
            mn += ((char)((tot-1) + '0'));
            tot = 1;
        }else mn += '0';
    }
    reverse(mn.begin(), mn.end());
    cout << mn << " " << mx << '\n';
}
  return 0;
}