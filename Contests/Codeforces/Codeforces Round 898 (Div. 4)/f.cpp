/*
Author: jubair7
Date: 22 Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int work (vector<int> v, long long got, int k) {
    vector<long long> preSum;
    long long sum = 0;
    int ans = 0;
    for (int i = 0; i<v.size(); i++) {
        sum += v[i];
        preSum.push_back(sum);
    }
    int l = 1;
    int r = v.size();
    while (l <= r) {
        int mid = (l+r)>>1;
        int i = 0;
        int j = mid-1;
        int ok = 0;
        while (j < v.size()) {
            long long tot = preSum[j]- preSum[i]+v[i];
            if (tot <= k) {
                ok = 1;
                break;
            }
            i++;
            j++;
        }
        if (ok) {
            ans = mid;
            l = mid+1;
        } else r = mid-1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        int height[n], fruits[n];
        vector<long long> tot(n);
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i<n; i++) {
            cin >> fruits[i];
            sum += fruits[i];
            tot[i] = sum;
            if (fruits[i] <= k) ans = 1;
        }
        for (int i = 0; i<n; i++) cin >> height[i];
        for (int i = 0; i<n-1; i++) {
            if (height[i]%height[i+1] == 0 and fruits[i]+fruits[i+1] <= k) {
                vector<int> inner;
                inner.push_back(fruits[i]);
                inner.push_back(fruits[i+1]);
                long long got = (long long)fruits[i]+fruits[i+1];
                int j = i+1;
                while (j < n-1) {
                    if (height[j]%height[j+1] != 0) {
                        break;
                    }
                    inner.push_back(fruits[j+1]);
                    got += fruits[j+1];
                    j++;
                }
                if (got <= k)
                    ans = max(ans, (int)inner.size());
                else {
                    //sort(inner.begin(), inner.end());
                    int cnt = work(inner, got, k);
                    ans = max(ans, cnt);
                }
                inner.clear();
                i = j;
            }
        }
        cout << ans << '\n';
    }
  return 0;
}