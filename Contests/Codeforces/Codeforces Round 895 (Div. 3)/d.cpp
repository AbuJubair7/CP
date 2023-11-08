/*
Author: jubair7
Date: 17 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool isSorted(vector<int> arr,  int n) {
    for (int i = 1; i<n; i++) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;
        int ans = 0;
        for (int i = 1; i<n; i++) {
            if (arr[i] < arr[i-1]) {
                int l = arr[i]+1;
                int r = arr[i-1];
                while (l <= r) {
                    int mid = (l+r)>>1;
                    if (abs(arr[i]-mid) < abs(arr[i-1]-mid))
                        l = mid+1;
                    else r = mid-1;
                }
                ans = max(ans, l);
            }
        }
        for (int i = 0; i<n; i++) arr[i] = abs(arr[i]-ans);
        if (isSorted(arr, n)) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
