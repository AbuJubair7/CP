/**
 *    author:  jubair7
 *    created: 09.10.2024 12:03:43
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
  int n, w;
  cin >> n >> w;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i] >> a[i];
  }
  vector<long long> f(w + 1);
  for (int i = 0; i < n; i++) {
    vector<long long> ff = f;
    for (int j = 1; j <= w; j++) {
      if (j >= b[i]) {
        ff[j] = max(ff[j], f[j - b[i]] + a[i]);
      }
    }
    f = ff;
  }
  cout << f[w] << '\n';
  return 0;
}
