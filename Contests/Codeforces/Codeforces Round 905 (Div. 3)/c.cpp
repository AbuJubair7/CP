/*
Author: jubair7
Date: 22/10/23
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        int evens = 0;
        int minDis = INT_MAX;
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            if (arr[i]%2 == 0) evens++;
            if (arr[i] < k) minDis = min(k-arr[i], minDis);
            else if (arr[i] % k == 0) minDis = 0;
            else {
                int val = arr[i];
                int inc = 0;
                while (val % k != 0) {
                    val++;
                    inc++;
                }
                minDis = min(inc, minDis);
            }
        }
        if (minDis == 0) cout << 0 << '\n';
        else if (k == 4 and n > 1) {
            if (evens >= 2) cout << 0 << '\n';
            else cout <<  min(2 - evens, minDis) << '\n';
        } else cout << minDis << '\n';
    }  
    return 0;   
}