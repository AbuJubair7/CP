/*
Author: jubair7
Date: 1 Oct 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int tCase = 1;
    while(tt--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) cin >> arr[i];
        sort (arr.begin(), arr.end());
        int ans = 0;
        for (int i = 1; i<n; i++) {
            if (arr[i] <= b) {
                int l = 0;
                int r = i-1;
                int leftInd = 0;
                int rightInd = i-1;
                int ok = 0;
                while (l <= r) {
                    int mid = (l+r)>>1;
                    if (arr[i]+arr[mid] <= b) {
                        ok = 1;
                        l = mid+1;
                        rightInd = mid;
                    } else r = mid-1;
                }
                l = 0;
                r = rightInd;
                if (ok) {
                    ok = 0;
                    while (l <= r) {
                        int mid = (l+r)>>1;
                        if (arr[i]+arr[mid] >= a) {
                            ok = 1;
                            leftInd = mid;
                            r = mid-1;
                        } else l = mid+1;
                    }
                }
                if (ok) {
                    ans += (rightInd - leftInd + 1);
                }
            }
        }
        cout << "Case " << tCase++ << ": " << ans << '\n';
    }
  return 0;
}