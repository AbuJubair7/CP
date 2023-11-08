/*
Author: jubair7
Date: 9 Oct Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n, q;
        cin >> n >> q;
        map <int, pair<int, int>> win;
        vector<int> arr(n+1);
        for (int i = 1; i<=n; i++) {
            cin >> arr[i];
        }
        int mx = *max_element(arr.begin(), arr.end());
        int fight [n+1];
        int last = arr[1];
        for (int i = 2; i<=n; i++) {
            last = max(last, arr[i]);
            if (win[last].first == 0) win[last].first = i-1;
            win[last].second = i-1; 
        }
        while (q--) {
            int i, k;
            cin >> i >> k;
            if (win[arr[i]].first == 0) cout << 0 << '\n';
            else if (win[arr[i]].first > k) cout << 0 << '\n';
            else if (arr[i] == mx) {
                k -= (win[arr[i]].first-1);
                cout << k << '\n';
            } else {
                if (win[arr[i]].second <= k) cout << win[arr[i]].second - win[arr[i]].first + 1 << '\n';
                else cout << k -  win[arr[i]].first + 1 << '\n';
            }
        }

    }
  return 0;
}