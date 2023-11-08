/*
Author: jubair7
Date: 31 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

int mex(vector<int> arr, int n){
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n; i++){
        if(arr[i] != i){
            return min(i, arr[i]);
        }
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i<n; i++) cin >> arr[i];
        int inv = mex(arr, n);
        if(k >= n) k = k%(n+1);
        if(n == 1){
            if(k % 2 == 0) cout << arr[0] << '\n';
            else cout << inv << '\n';
        }else{
            if(k){
                vector<int> er;
                vector<int> final;
                final.push_back(inv);
                for(int i = 0; i<n-k; i++) final.push_back(arr[i]);
                for(int i = n-k; i<n; i++)  er.push_back(arr[i]);
                for(int i = 1; i<er.size(); i++) cout << er[i] << ' ';
                for(int i = 0; i<final.size(); i++) cout << final[i] << ' ';
                cout << '\n';
            }else{
                for(auto i : arr) cout << i << ' ';
                cout << '\n';
            }
        }
    }
  return 0;
}