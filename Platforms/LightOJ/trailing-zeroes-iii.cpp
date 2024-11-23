/**
 *    author:  jubair7
 *    created: 19.11.2024 08:08:02
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
    int q;
    cin >> q;
    long long l = 1;
    long long r = 1e18;
    auto ask = [&](long long x) -> long long{
      long long a = 0, b = 0;
      for (long long i = 2; i <= x; i *= 2) {
        a += x / i;
      }
      for (long long i = 5; i <= x; i *= 5) {
        b += x / i;
      }
      return min(a, b);
    };
    int ans = 0;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      long long z = ask(mid);
      if (z == q) {
        ans = mid;
        r = mid - 1;
      } else if (z > q) {
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    if (ans) {
      cout << "Case " << ++tCase << ": " << ans << '\n';
    } else {
      cout << "Case " << ++tCase << ": " << "impossible" << '\n';
    }
  }
  return 0;
}
