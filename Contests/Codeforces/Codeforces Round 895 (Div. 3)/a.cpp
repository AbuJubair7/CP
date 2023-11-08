/*
Author: jubair7
Date: 7 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) cout << 0 << '\n';
        else {
            int ans = 0;
            if (a > b) swap(a, b);
            while ( a < b) {
                ans++;
                b -= c;
                a += c;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
