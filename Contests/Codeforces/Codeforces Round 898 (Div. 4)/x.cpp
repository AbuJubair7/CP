/*
Author: jubair7
Date: 11 Oct Sep 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        char arr[n+1];
        map<char, int> front;
        map<char, vector<int>> ind;
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            ind[arr[i]].push_back(i);
            front[arr[i]]++;
        }
        long long ans = (n*(n+1))/2ll;
        cout << "ans: " << ans << '\n';
        for (auto k : front) {
            int f = k.second;
            cout << "got: " << f << '\n';
            for (int i = 0; i+f-1<n and f > 1; i++) {
                int l = i;
                int r = i+f-1;
                cout << l << " " << r << '\n';
                map<char, int> frq;
                int mx = 0;
                while (l <= r) {
                    frq[arr[i]]++;
                    mx = max(frq[arr[i]], mx);
                    l++;
                }
                cout << mx << " -- " << frq.size() << '\n';
                if (mx > frq.size()) {
                    cout << "Decreasing" << '\n';
                    ans--;
                }
                frq.size();
            }
        }
        cout << ans << '\n';
    }
  return 0;
}