/**
 *    author:  jubair7
 *    created: 15.09.2024 10:51:35
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int inf = 1e9;
  vector<int> f(n + 1, inf);
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k and i - j >= 1; j++) {
      f[i] = min(f[i], f[i - j] + abs(a[i] - a[i - j]));
    }
  }
  cout << f[n] << '\n';
  return 0;
}
