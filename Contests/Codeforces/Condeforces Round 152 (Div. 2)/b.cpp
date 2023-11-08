/*
Author: jubair7
Date: 27 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> below, pair<int, int> above)
    {   
        if(below.first == 0 or above.first == 0){
            if(below.first != 0 and above.first == 0)
                return true;
            else if(below.first == above.first
                and below.second > above.second){
                 return true;
            }
               
        }
        else if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            x %= k;
            pq.push({x, i+1});
        }
         while(!pq.empty()){
           cout << pq.top().second << " ";
           pq.pop(); 
        }
    }      
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}