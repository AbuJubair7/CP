/**
 *    author:  jubair7
 *    created: 30.08.2024 20:09:49
**/
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
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (i < n / 2) {
        a.push_back(x);
        continue;
      }
      b.push_back(x);
    }
    auto get_subset = [&](auto&& self, int i, vector<int> &v, set<long long> &subset, long long sum) -> void {
      if (i == v.size()) {
        subset.insert(sum);
        return;
      }
      self(self, i + 1, v, subset, sum);
      self(self, i + 1, v, subset, sum + v[i] * 2ll);
      self(self, i + 1, v, subset, v[i] + sum);
    };
    set<long long> sub_left, sub_right;
    get_subset(get_subset, 0, a, sub_left, 0);
    get_subset(get_subset, 0, b, sub_right, 0);
    debug(sub_right);
    bool ok = false;
    for (auto x : sub_right) {
      long long need = m - x;
      auto it = sub_left.lower_bound(need);
      if (it != sub_left.end() and *it == need) {
        ok = true;
        break;
      }
    }
    cout << "Case " << ++tCase << ": " << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}
