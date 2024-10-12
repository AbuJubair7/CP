/**
 *    author:  jubair7
 *    created: 09.10.2024 13:08:08
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
  int n, W;
  cin >> n >> W;
  vector<int> a(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> a[i];
  }
  long long inf = 1e18;
  long long tot = accumulate(a.begin(), a.end(), 0ll);
  vector<long long> f(tot + 1, inf);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    vector<long long> ff = f;
    for (int j = a[i]; j <= tot; j++) {
      ff[j] = min(ff[j], f[j - a[i]] + w[i]);
    }
    f = ff;
  }
  for (int i = tot; i >= 0; i--) {
    if (f[i] <= W) {
      cout << i << '\n';
      break;
    }
  }
  return 0;
}
