/*
Author: jubair7
Date: 28/10/23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        map<char, int> mp;
        int same = 0;
        vector<pair<int, int>> indx;
        for (int i = 0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                same++;
                indx.push_back({i, i+1});
            }
        }
        if (same == 0) cout << "YES" << '\n';
        else {
            int ok = 1;
            for (int i = 0; i<m-1 and ok; i++) {
                if (t[i] == t[i+1]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (auto p : indx) {
                    if (s[p.first] == t[0] or s[p.second] == t[m-1]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            } else cout << "NO" << '\n';
        }
    }
    return 0;   
}