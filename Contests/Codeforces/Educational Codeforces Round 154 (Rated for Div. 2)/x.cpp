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
        vector<int> arr(n);
        for (auto &i : arr) cin >> i;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int l = 0;
        int r = arr[n-1];
        int start = 0;
        int end = 0;
        while (l <= r) {
            int mid = (l+r)>>1;
            //cout << "time: " << mid << '\n';
            int pos = 1;
            int worker = 1;
            start = 0, end = 0;
            for (int i = 0; i<arr.size(); i++) {
                int innerMid = (arr[start]+arr[i])>>1;
                if (arr[start]- innerMid > mid or arr[i]-innerMid > mid) {
                    // cout << arr[start] << " " << arr[i] << ": " << (arr[start]+arr[i])/2 <<'\n';
                    start = i;
                    worker++;
                } 
            }
            // cout << "worker: " << worker << '\n';
            if(worker > 3) l = mid+1;
            else r = mid-1;
        }
        cout << l << '\n';
    }
    return 0;
}
