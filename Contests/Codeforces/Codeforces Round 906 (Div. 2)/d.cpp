/*
Author: jubair7
Date: 4/11/23
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<long long> sum(n);
    long long tot = 0;
    long long r = 0;
    long long ans = 0;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
        tot += arr[i];
        sum[i] = tot;
        if (arr[i] > 0) r += arr[i];
    }
    int mxPos = 0;
    for (int i = 0; i<n; i++)
    if (r == 0) ans = *max_element(arr.begin(), arr.end());
    else {
        r += 1000;
        long long l = 1;
        while (l <= r) {
            long long mid = (l+r)>>1;
            int i = 0;
            int j = n-1;
            int ok = 0;
            while (i < j) {
                long long tmp = sum[j];
                tmp -= sum[i];
                tmp += arr[i];
                if (tmp >= mid) {
                    if (tmp > mid)
                        mid = tmp;
                    ok = 1;
                    break;
                }
                if (arr[i] <= arr[j]) i++;
                else j--;
            }
            if (ok) {
                l = mid+1;
                ans = mid;
            } else r = mid-1;
        }
    }
    cout << ans << '\n';
    return 0;   
}