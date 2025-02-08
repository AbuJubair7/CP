#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  multiset<int> se;
  map<int, int> mp;
  vector<vector<int>> add(n + 1), rem(n + 2);
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    add[l].push_back(x);
    rem[r + 1].push_back(x);
  }
  int unique = 0;
  for (int i = 1; i <= n; i++) {
    for (auto i : add[i]) {
      mp[i]++;
      if (mp[i] == 1) unique++;
      se.insert(i);
    }
    for (auto i : rem[i]) {
      mp[i]--;
      if (mp[i] == 0) unique--;
      se.erase(se.find(i));
    }
    cout << unique << " \n"[i == n];
  }
  return 0;
}