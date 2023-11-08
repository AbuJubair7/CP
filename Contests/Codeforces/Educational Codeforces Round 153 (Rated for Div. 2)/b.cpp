/*
Author: jubair7
Date: 24 Aug 2023
*/

#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            arr[i] = {x, i+1};
        }
        sort(arr.begin(), arr.end());
        int k = arr[0].first+1;
        cout << n-1 << '\n';
        for(int i = 0; i<n-1; i++){
            arr[i+1].first = arr[i].first+1;
            cout << arr[i].second << " " << arr[i+1].second << " ";
            cout << arr[i].first << " " << arr[i].first+1 << '\n';
        }
        // vector<int> reset(n);
        // for(auto i : arr)
        //     reset[i.second-1] = i.first;
        // for(auto i : reset) cout << i << " ";
        // cout << '\n';
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}