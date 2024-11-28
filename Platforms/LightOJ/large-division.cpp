/**
 *    author:  jubair7
 *    created: 29.11.2024 00:21:49
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
    string a;
    int b;
    cin >> a >> b;
    long long  ans = 0;
    b = abs(b);
    for (int i = (a[0] == '-' ? 1 : 0 ); i < a.size(); i++) {
      ans = (ans * 10 % b + (a[i] - '0')) % b;
      debug(ans);
    }
    cout << "Case " << ++tCase << ": " << (ans == 0 ? "divisible" : "not divisible") << '\n';
  }
  return 0;
}
