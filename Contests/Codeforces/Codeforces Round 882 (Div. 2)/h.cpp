/*
Author: jubair7
Date: 22 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}
//14658664233326
//7329332116664
void solve(){
    //cout << (1000+14658664233326) * (1000+14658664233326) << '\n';
    int t;
    cin >> t;
    while(t--){
        int n;
        long long c;
        cin >> n >> c;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;
        sort(arr.begin(), arr.end(), greater<>());
        long long left = 2;
        long long right = (c/2);
        if(right % 2) right++;
        long long result = 0;
        while(left <= right){
            long long mid = (right+left)/2;
            if(mid % 2) mid++;
            __int128 sum = 0;
            for(auto i : arr){
                sum += ((__int128)(i+mid) * (i+mid));
                if(sum > c){
                    break;
                }
            }
            if(sum > c){
                right = mid-2;
            }else if(sum < c) left = mid+2;
            else{
                result = mid/2;
                break;
            }
        }
        cout << result << '\n';
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}