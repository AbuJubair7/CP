/*
Author: jubair7
Date: 27 Aug 2023
*/

#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string s;
        cin >> n >> k >> s;
        string s1 = "";
        string s2 = "";
        for(int i = 0 ;i<s.length(); i++){
            if(i%2 == 1)
                s1 += s[i];
            else s2 += s[i];
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        string res = "";
        int one = 0;
        int two = 0;
        for(int i = 0; i<s.length(); i++){
            if(i%2 == 1)
                res += s1[one++];
            else res += s2[two++];
        }
        if(k % 2 == 0) sort(res.begin(), res.end());
        cout << res << '\n';
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}