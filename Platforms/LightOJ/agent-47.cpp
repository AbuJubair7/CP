/**
 *    author:  jubair7
 *    created: 15.08.2024 15:12:58
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
    int n;
    cin >> n;
    vector<int> life(n);
    for (int i = 0; i < n; i++) {
      cin >> life[i];
    }
    vector<string> players(n);
    for (int i = 0; i < n; i++) {
      cin >> players[i];
      players[i][i] = '0';
    }
    int inf = 1e9;
    vector<int> f((1 << n) + 7, inf);
    for (int i = 0; i < n; i++) {
      f[1 << i] = life[i]; 
    }
    for (int mask = 1; mask  < (1 << n); mask++) {
      for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0) {
          continue;
        }
        for (int i = 0; i < n; i++) {
          if ((mask & (1 << i)) == 0 or i == j) {
            continue;
          }
          int op = life[j];
          if (players[i][j] != '0') {
            op = life[j] / (players[i][j] - '0');
            op += (life[j] % (players[i][j] - '0') != 0 ? 1 : 0);
          }
          f[mask] = min(f[mask], f[mask ^ (1 << j)] + op);
        }
      }
    }
    cout << "Case " << ++tCase << ": " << f[(1 << n) - 1] << '\n';
  }
  return 0;
}
