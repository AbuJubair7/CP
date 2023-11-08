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
        vector<int> arr(n);
        vector<int> hori;
        map<int, int> map;
        for(auto &i : arr){
            cin >> i;
            map[i]++;
            if(map[i] == 1)
                hori.push_back(i);
        }
        reverse(hori.begin(), hori.end());
        if(n != arr[0]) cout << "NO\n";
        else{
            int i = 0;
            int ok = 1;
            vector<int> res;
            int level = n;
            for(int i = 1; i<= hori[0]; i++)
                res.push_back(level);
            i++;
            while(i < hori.size()){
                level -= (map[hori[i-1]]);
                for(int j = 1; j<=hori[i]-hori[i-1]; j++)
                    res.push_back(level);
                i++;
            }
            if(res.size() == n){
                for(int i = 0; i<n and ok; i++){
                    if(res[i] != arr[i])
                        ok = 0;
                }
            }
            if(ok) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}
     
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}