/**
 *    author:  jubair7
 *    created: 11.10.2024 10:38:24
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
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  vector<vector<int>> f(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        f[i][j] = 1 + f[i - 1][j - 1];
        continue;
      }
      f[i][j] = max(f[i-1][j], f[i][j-1]);
    }
  }
  string ans;
  int i = n;
  int j = m;
  while (i > 0 and j > 0) {
    if (a[i - 1] == b[j - 1]) {
      ans.push_back(a[i - 1]);
      i--; j--;
    } else if (f[i - 1][j] > f[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  if (ans.size() != 0) {
    reverse(ans.begin(), ans.end());
  }
  cout << ans << '\n';
  return 0;
}
