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
        int n;
        cin >> n;
        int ans = INT_MAX;
        for (int i = 0; i<n; i++) {
            int d, s;
            cin >> d >> s;
            int k = (d+s) - d;
            if (k%2 == 0) k = (k/2)-1;
            else k /= 2;
            ans = min(ans, d+k);
        }
        cout << ans << '\n';
    }
    return 0;
}
