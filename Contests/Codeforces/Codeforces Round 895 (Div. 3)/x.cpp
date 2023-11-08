/*
Author: jubair7
Date: 18 Sep 2023
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
        int ch[n+1][n+1];
        int adj[n+1] = {0};
        vector<int> set[n+1];
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) {
                char c;
                cin >> c;
                ch[i][j] = c-'0';
            }
        }
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) {
                if (ch[i][j] == 1) {
                    adj[i] == 0 ? adj[i] = j : adj[i] = min(adj[i], j);
                }
            }
        }
        int val = 1;
        for (int i = 1; i<=n; i++) {
            if (set[i].size() == 0) {
                if (adj[i] != 0 and adj[i] < i) {
                    set[i].clear();
                    set[adj[i]].clear();
                    for (int k = 1; k<=adj[i]; k++)
                        set[i].push_back(k);
                    for (int k = 1; k<=i; k++)
                        set[adj[i]].push_back(k);
                } else {
                    if (adj[i] == 0) {
                        set[i].push_back(n-1);
                        set[i].push_back(n);
                    } else {
                        for (int k = 1; k<=i; k++)
                            set[i].push_back(k);
                        for (int k = 1; k<=adj[i]; k++)
                            set[adj[i]].push_back(k);
                    }
                }
            }
        }
        for (int i = 1; i<=n; i++) {
            cout << set[i].size() << ' ';
            for (auto k : set[i])
                cout << k << ' ';
            cout << '\n';
        }
    }
    return 0;
}
