/**
 *    author:  jubair7
 *    created: 27.08.2024 14:14:21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

static int dp[12][2][100][100] = {-1};
int a, b, k, n;
string s;

int f(int i, bool tight, int digit_sum, int val) {
  if (i == n) {
    return (val % k == 0 and digit_sum % k == 0 and digit_sum > 0);
  }
  int mod = val % k;
  int &ans = dp[i][tight][digit_sum][mod];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  int high = tight ? 9 : s[i] - '0';
  for (int digit = 0; digit <= high; digit++) {
    ans += f(i+1, tight | (digit < high), digit_sum + digit, val * 10 + digit);
  }
  return ans;
}

void clear_dp() {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 100; k++) {
        for (int l = 0; l < 100; l++) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    cin >> a >> b >> k;
    a--;
    s = to_string(a);
    n = s.size();
    if (k > 90) {
      cout << "Case " << ++tCase << ": " << 0 << '\n';
    } else if (k == 1) {
      cout << "Case " << ++tCase << ": " << b - a << '\n';
    } else {
      int low = a <= 0 ? 0 : f(0, false, 0, 0);
      clear_dp();
      s = to_string(b);
      n = s.size();
      int high = f(0, false, 0, 0);
      cout << "Case " << ++tCase << ": " << high - low << '\n';
    }
    clear_dp();
  }
  return 0;
}
