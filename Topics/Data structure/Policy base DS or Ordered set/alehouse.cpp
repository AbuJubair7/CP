/*
Author: jubair7
Date: 14/2/24
*/
/*
* link: https://vjudge.net/problem/Kattis-alehouse
* In short: Find a point where most of the segment meets.
* Approach: Sort according to start of each segment.
* Insert ends of sorted segment one by one and check 
* how may ends are greater or equal than the current begining, because if
* already inserted end which are < current begining. (set and array is sorted)
* Then they cannot meet at this point.
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i<n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  ordered_set st;
  for (int i = 0; i<n; i++) {
    st.insert(a[i].second);
    ans = max((int)(st.size()-st.order_of_key(a[i].first-k)), ans);
  }
  cout << ans << '\n';
}