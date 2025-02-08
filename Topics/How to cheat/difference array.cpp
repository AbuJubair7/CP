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
  vector<long long> a(n + 1), d(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    d[i] = d[i] - d[i - 1];
  } 
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    d[l] += x;
    d[r + 1] -= x;
  }
  partial_sum(d.begin(), d.end(), d.begin());
  for (int i = 1; i <= n; i++) {
    a[i] += d[i];
    cout << a[i] << " \n"[i == n];
  }
  return 0;
}