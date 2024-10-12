/**
 *    author:  jubair7
 *    created: 10.10.2024 20:44:00
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using T = unsigned long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int tCase = 0;
  int mx = 5e6;
  vector<T> phi(mx + 1);
  for (int i = 0; i <= mx; i++) {
    phi[i] = i;
  }
  for (int i = 2; i <= mx; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= mx; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
  for (T &i : phi) {
    i *= i;
  }
  partial_sum(phi.begin(), phi.end(), phi.begin());
  while (tt--) {
    int a, b;
    cin >> a >> b;
    T ans = phi[b] - phi[a - 1];
    cout << "Case " << ++tCase << ": " << ans << '\n';
  }
  return 0;
}
