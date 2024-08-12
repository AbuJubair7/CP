/**
 *    author:  jubair7
 *    created: 12.08.2024 13:02:53
**/
// how many N length numbers are there which has every digit at least once?
// No leading zero are allowed 
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
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<long long>> f(n + 1, vector<long long>((1 << 10) + 7, -1));
    auto check = [&](int mask) -> bool {
      int need = (1 << 10) - 1;
      return ((mask & need) == need);
    };
    auto count_numbers = [&](auto&& self, int pos, int mask) -> long long {
      if (pos >= n) return check(mask) ? 1 : 0;
      if (f[pos][mask] != -1) return f[pos][mask];
      f[pos][mask] = 0ll;  
      for (int i = (pos == 0 ? 1 : 0); i < 10; i++) {
        f[pos][mask] += self(self, pos + 1, mask | (1 << i));
      }
      return f[pos][mask];
    };
    count_numbers(count_numbers, 0, 0);
    cout << f[0][0] << '\n';
  }
  return 0;
}
