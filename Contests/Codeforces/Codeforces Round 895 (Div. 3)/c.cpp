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
        int l, r;
        cin >> l >> r;
        int ok = 0;
        if (l == r) {
            for (int i = 2; i<=sqrt(l); i++) {
                if (l%i == 0) {
                    ok = 1;
                    cout << i << " " << l-i << '\n';
                    break;
                }
            }
        } else {
            while (r >= l and r  > 2) {
                if (r%2 == 0) {
                    ok = 1;
                    cout << r/2 << " " << r/2 << '\n';
                    break;
                }
                r--;
            }
        }
        if (!ok) cout << -1 << '\n';
    }
    return 0;
}
