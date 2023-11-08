/*
Author: jubair7
Date: 24/10/23
*/

#include <bits/stdc++.h>
using namespace std;

int last_bit(long long n) {
    bitset<32> bit(n);
    for (int i = 31; i>=0; i--) {
        if (bit[i] == 1) {
            return i;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        long long ans = 0;
        for (int i = 0; i<n; i++) cin >> arr[i];
        int lastOne = last_bit(arr[0]);
        for (int i = 1; i<n; i++) {
            int currOne = last_bit(arr[i]);
            if (currOne > lastOne) {
                lastOne = currOne;
            } else {
                int dis = abs(last_bit(arr[i]) - last_bit(arr[i-1]));
                ans += (lastOne - currOne);
                if (last_bit(arr[i]) > last_bit(arr[i-1]))
                    arr[i-1] <<= dis;
                else if (last_bit(arr[i-1]) > last_bit(arr[i]))
                    arr[i] <<= dis;
                if (arr[i-1] > arr[i]) {
                    ans++;
                    lastOne++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;   
}