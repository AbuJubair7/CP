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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int inf = 1e9;
  vector<int> f(n + 1, inf);
  f[1] = 0;
  f[2] = abs(a[1] - a[2]);
  for (int i = 3; i <= n; i++) {
    f[i] = min(f[i - 1] + abs(a[i] - a[i-1]), f[i - 2] + abs(a[i] - a[i-2]));
  }
  cout << f[n] << '\n';
  return 0;
}
