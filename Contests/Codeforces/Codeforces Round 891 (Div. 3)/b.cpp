/*
Author: jubair7
Date: 12 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
  if(p1.second == p2.second)
    return p1.first < p2.first;
  return p1.second < p2.second;
}

void solve(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<pair<int, int>> minimums;
    map<int, int> minCnt;
    for(int i = 0; i<n; i++){
      int m;
      cin >> m;
      vector<int> v;
      int f = INT_MAX;
      int s = INT_MAX;
      while(m--){
        int x;
        cin >> x;
        f = min(f, x);
        if(s == INT_MAX) s = f;
        else if(s == f and x > f) s = f;
        else if(x > f) s = min(s, x);
        v.push_back(x);
        minCnt[x]++;
      }
      if(minCnt[f] > 1) s = f;
      sort(v.begin(), v.end());
      minimums.push_back({v[0], v[1]});
    }
    sort(minimums.begin(), minimums.end(), cmp);
    int low = minimums[0].first;
    long long sum = 0;
    for(int i = 1; i<n; i++){
      low = min(minimums[i].first, low);
      sum += minimums[i].second;
    }
    sum += low;
    cout << sum << '\n';
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}