/*
Author: jubair7
Date: 21 Sep 2023
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
        vector<int> arr(n);
        for (int i = 0; i<n; i++) cin >> arr[i];
        sort (arr.begin(), arr.end());
        arr[0]++;
        int sum = 1;
        for (auto i : arr) sum *= i;
        cout << sum << '\n';
      }
  return 0;
}