/*
Author: jubair7
Date: 12 Oct 2023
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
        vector<int> arr(3);
        cin >> arr[0] >> arr[1] >> arr[2];
        sort (arr.begin(), arr.end());
        int op = 3;
        while (op--) {
            if (arr[2] != arr[0]) {
                arr[2] -= arr[0];
            } else if (arr[0] != arr[1])
                arr[1] -= arr[0];
        }
        if (arr[0] == arr[1] and arr[1] == arr[2]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
  return 0;
}