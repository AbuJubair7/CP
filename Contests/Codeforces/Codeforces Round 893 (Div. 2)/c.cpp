/*
Author: jubair7
Date: 17 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> map;
        vector<int> arr(n+1);
        for(int i = 1; i<=n; i++){
            int x;
            cin >> x;
            map[x] = i;
        }
        for(int i = 1; i<=n; i++)
            cin >> arr[i];
        int last = 0;
        for(int i = 1; i<=n-1; i++){
            if(map[arr[i]] > map[arr[i+1]]){
                last = i;
            }
        }
        if(last) cout << last << '\n';
        else cout << 0 << '\n';   
    }   

}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}