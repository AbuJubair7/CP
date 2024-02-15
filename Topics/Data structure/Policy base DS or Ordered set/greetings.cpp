/*
Author: jubair7
Date: 15/2/24
*/
/*
* Problem link: https://codeforces.com/contest/1915/problem/F
* In short: Find number of points greater than i'th end point
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    ordered_set os;
    long long ans = 0;
    for (int i = 0; i<n; i++) {
      ans += (1ll*os.size()-os.order_of_key(a[i].second));
      os.insert(a[i].second);
    }
    cout << ans << '\n';
  }
}