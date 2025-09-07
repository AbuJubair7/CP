// bit lobon
// https://codeforces.com/gym/106045/problem/J
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

long long and_range(long long l, long long r) {
  int shift = 0;
  while (l < r) {
    l >>= 1;
    r >>= 1;
    shift++;
  }
  return (l << shift);
}

long long or_range(long long l, long long r) {
  int shift = 0;
  while (l < r) {
    l >>= 1;
    r >>= 1;
    shift++;
  }
  return (l << shift) | ((1LL << shift) - 1);
}

long long xor_to_n(long long n) {
  if (n < 0) return 0;
  if (n % 4 == 0) return n;
  else if (n % 4 == 1) return 1;
  else if (n % 4 == 2) return n + 1;
  else return 0;
}

long long xor_range(long long l, long long r) {
  return xor_to_n(l - 1) ^ xor_to_n(r);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    long long l, r;
    cin >> l >> r;
    cout << and_range(l, r) << ' ' << or_range(l, r) << ' ' << xor_range(l, r) << '\n';
  }
  return 0;
}