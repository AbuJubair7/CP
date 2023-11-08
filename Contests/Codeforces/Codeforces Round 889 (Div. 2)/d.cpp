/*
Author: jubair7
Date: 31 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        char arr[n][m];
        int one = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '1')
                    one++;
            }
        }
        if(arr[0][0] == '1') cout << -1 << '\n';
        else{
            cout << one << '\n';
            for(int i = 0; i<n; i++){
                for(int j = m-1; j>0; j--){
                    if(arr[i][j] == '1'){
                        cout << i+1 << " " << j << " " << i+1 << " " << j+1 << '\n';
                    }
                }
            }
            for(int i = n-1; i>0; i--){
                if(arr[i][0] == '1')
                    cout << i << " " << 1 << " " << i+1 << " " << 1 << '\n';
            }
        }
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}