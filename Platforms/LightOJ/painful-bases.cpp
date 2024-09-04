/**
 *    author:  jubair7
 *    created: 05.09.2024 01:13:08
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
  map<char, int> mp;
  for (char i = '1'; i <= '9'; i++) {
    mp[i] = i - '0';
  }
  for (char i = 'A', j = '0'; i <= 'F'; i++, j++) {
    mp[i] = (j - '0') + 10;
  }
  while (tt--) {
    int base, k;
    string s;
    cin >> base >> k >> s;
    int n = s.size();
    vector<vector<int>> f(1 << n, vector<int>(k));
    f[0][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int j = 0; j < n; j++) {
        if (!(mask & (1 << j))) {
          for (int mod = 0; mod < k; mod++) {
            f[mask | (1 << j)][(mod * base + mp[s[j]]) % k] += f[mask][mod];
          }
        }
      }
    }
    cout << "Case " << ++tCase << ": " << f[(1 << n) - 1][0] << '\n';
  }
  return 0;
}
