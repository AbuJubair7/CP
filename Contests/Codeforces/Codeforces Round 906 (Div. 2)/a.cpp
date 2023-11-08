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
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i<n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        if (mp.size() > 2) cout << "NO" << '\n';
        else if (mp.size() == 1) cout << "YES" << '\n';
        else {
            vector<int> sz;
            for (auto i : mp)
                sz.push_back(i.second);
            if (abs(sz[0] - sz[1]) <= 1) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;   
}