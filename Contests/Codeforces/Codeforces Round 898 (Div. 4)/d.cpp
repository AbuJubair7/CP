/*
Author: jubair7
Date: 21 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i<n; i++) {
            if (s[i] == 'B') {
                ans++;
                int j = i;
                int start = i;
                while (j < s.length() and j < start+k) {
                    i = j;
                    j++;
                }
            }
        }
        cout << ans << '\n';
    }
  return 0;
}