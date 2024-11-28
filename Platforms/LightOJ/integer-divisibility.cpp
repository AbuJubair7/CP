/**
 *    author:  jubair7
 *    created: 28.11.2024 11:13:24
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
  int tCase = 0;
  int tt;
  cin >> tt;
  while (tt--) {
    int d, n;
    cin >> d >> n;
    int ans = n % d;
    int cnt = 1;
    while (ans) {
      ans = (ans * 10ll % d + n) % d;
      cnt++;
    }
    cout << "Case " << ++tCase << ": " << cnt << '\n';
  }
  return 0;
}
