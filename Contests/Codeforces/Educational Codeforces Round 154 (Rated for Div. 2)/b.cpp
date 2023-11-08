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
        string a, b;
        cin >> a >> b;
        if((a[1] == '1' and b[1] == '1') or (a[a.length()-1] == '0' and b[b.length()-1] == '0')
            or a == b)
            cout << "YES" << '\n';
        else{
            int ok = 0;
            for(int i = 1; i<a.length()-1; i++){
                if((a[i] == '0' and a[i+1] == '1')
                    and (b[i] == '0' and b[i+1] == '1')){
                    ok = 1;
                    break;
                }
            }
            if(ok) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
  return 0;
}