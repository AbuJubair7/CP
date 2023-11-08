/*
Author: jubair7
Date: 30 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool isSorted(vector<int> &arr){
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> pos;
        vector<pair<int, int>> neg;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            if(arr[i] > 0) {
                pos.push_back({arr[i], i+1});
            }else neg.push_back({arr[i], i+1});
        }
        if(isSorted(arr)) cout << 0 << '\n';
        else{
            if(neg.size() == 0){
                cout << n-1 << '\n';
                for(int i = 2; i<=n; i++){
                    cout << i << " " << i-1 << '\n'; 
                }
            }else if(pos.size() == 0){
                cout << n-1 << '\n';
                for(int i = n-1; i>=1; i--){
                    cout << i << " " << i+1 << '\n';
                }
            }else{
                sort(pos.begin(), pos.end(), cmp);
                sort(neg.begin(), neg.end(), cmp);
                int mx1 = pos[pos.size()-1].first;
                int mx2 = neg[0].first;
                int ind = 0;
                if(abs(mx1) >= abs(mx2)){
                    ind =  pos[pos.size()-1].second;
                    cout << neg.size() + (n-1) << '\n';
                    for(int i = 0; i<neg.size(); i++){
                        cout << neg[i].second << " " << ind << '\n';
                    }
                    for(int i = 2; i<=n; i++){
                        cout << i << " " << i-1 << '\n'; 
                    }
                }else{  
                    ind =  neg[0].second;
                    cout << pos.size() + (n-1) << '\n';
                    for(int i = 0; i<pos.size(); i++){
                        cout << pos[i].second << " " << ind << '\n';
                    }
                    for(int i = n-1; i>=1; i--){
                        cout << i << " " << i+1 << '\n';
                    }
                }
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