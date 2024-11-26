/**
 *    author:  jubair7
 *    created: YYYY.MM.DD HH:MM:SS
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e8;
int spf[N + 1];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  spf[2] = 2;
  for (int i = 3; i <= N; i += 2) {
    spf[i - 1] = 2;
    spf[i] = i;
  }
  for (int i = 3; i * i <= N; i += 2) {
    if (spf[i] == i) {
      for (int j = i * i; j <= N; j += (i + i)) {
        spf[j] = min(i, spf[j]);
      }
    }
  }
  auto ok = [] (int n) -> bool {
    for (int i = 2; i < n; i++) {
      if (spf[i] == i and spf[n - i] == n - i) {
        return true;
      }
    }
    return false;
  };
  int n;
  cin >> n;
  for (int i = 4; i <= n; i++) {
    if (!ok(i)) {
      debug(i);
    }
  }
  return 0;
}