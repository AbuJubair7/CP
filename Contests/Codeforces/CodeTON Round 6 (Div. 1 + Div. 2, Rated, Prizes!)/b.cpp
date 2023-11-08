/*
Author: jubair7
Date: 18 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        vector<long long> forMin(n);
        vector<long long> forMx(n);
        vector<long long> b(m);
        long long noOp = 0;
        long long mn = 0;
        long long mx = 0;
        long long orMx = 0;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
            forMx[i] = a[i];
            forMin[i] = a[i];
        }
        for (int i = 0; i<m; i++) {
            cin >> b[i];
            orMx |= b[i];
        }
        
        for (int i = 0; i<n; i++)  noOp ^= a[i];
        sort (b.begin(), b.end());
        for (int i = 0; i<n; i++) forMin[i] |= b[0];
        for (int i = 0; i<n; i++)  mn ^= forMin[i];
        for (int i = 0; i<n; i++) forMx[i] |= orMx;
        for (int i = 0; i<n; i++)  mx ^= forMx[i];
        cout << min(noOp, min(mn, mx)) << ' ' << max(noOp, max(mn, mx)) << '\n';
    }
  return 0;
}