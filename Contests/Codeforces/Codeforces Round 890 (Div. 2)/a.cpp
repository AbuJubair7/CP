/*
Author: jubair7
Date: 5 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> arr2(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        int ok = 1;
        for(int i = 1; i<n ; i++){
            if(arr[i] < arr[i-1]){
                ok = 0;
                break;
            }
        }
        if(!ok){
            sort(arr2.begin(), arr2.end());
            for(int i = n-1; i>=0; i--){
                if(arr[i] != arr2[i]){
                    cout << arr2[i] << '\n';
                    break;
                }
            }
        }else cout << 0 << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}