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
       int n, k;
       cin >> n >> k;
       vector<int> arr(n+1);
       map<int, int> mp;
       map<int, pair<int, int>> height;
       map<int, pair<int, int>> width;
       for (int i = 1; i<=n; i++) {
        cin >> arr[i];
       }
        int mat[n+1][n+1];
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j<=n; j++) {
                mat[i][j] = min(arr[i], arr[j]);
                int x = mat[i][j];
                if (height[x].first == 0) {
                    height[x].first = i;
                }
                height[x].second = max(i, height[x].second);
                if (width[x].first == 0) {
                    width[x].first = j;
                } else {
                    width[x].first = min(j, width[x].first);
                }
                width[x].second = max(j, width[x].second);
                int totHeight = height[x].second - height[x].first + 1;
                int totWidth = width[x].second - width[x].first + 1;
                mp[x] = max(mp[x], totWidth+totHeight);
            }
        }
        for (int i = 1; i<=k; i++) cout << mp[i] << ' ';
        cout << '\n';
    }
  return 0;
}