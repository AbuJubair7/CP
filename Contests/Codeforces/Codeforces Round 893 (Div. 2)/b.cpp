/*
Author: jubair7
Date: 15 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> arr(n+1);
        map<int, int> map;
        vector<int> ind(m);
        for(int i = 0; i<=m-1; i++){
            cin >> ind[i];
            map[ind[i]]++;
        }
        int time = d;
        int eated = 0;
        for(int i = 1; i<=n; i++){
            if(time == d or map[i]){
                time = 1;
                eated++;
            }
        }
        int find = 0;
        for(int i = 0; i<n-3; i++){
            if(arr[i+3]-arr[i] <= 3){
                find = 1;
                break;
            }
        }
        if(find) cout << eated-1 << " " << 1 << "\n";
        else cout << eated << " " << m << '\n';
    }   
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}