/*
Author: jubair7
Date: 22/10/23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while (tt--) {
        string s;
        cin >> s;
        int arr[4];
        for (int i = 0; i<s.length(); i++) {
            if (s[i] == '0')
                arr[i] = 10;
            else arr[i] = s[i] - '0';
        }
        int last = 1;
        int ans = 0;
        for (int i = 0; i<4; i++) {
            if (arr[i] == last)
                ans++;
            else {
                ans += (abs(arr[i]-last));
                ans++;
                last = arr[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;   
}