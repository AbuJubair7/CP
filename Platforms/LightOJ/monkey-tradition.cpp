/**
 *    author:  jubair7
 *    created: 09.10.2024 11:11:02
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

using T = __int128;
// ax + by = __gcd(a, b)
// returns __gcd(a, b)
T extended_euclid(T a, T b, T &x, T &y) {
  T xx = y = 0;
  T yy = x = 1;
  while (b) {
    T q = a / b;
    T t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}
// finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime
// here, x is unique modulo m = lcm(m1, m2). returns (x, m). on failure, m = -1.
pair<T, T> CRT(T a1, T m1, T a2, T m2) {
  T p, q;
  T g = extended_euclid(m1, m2, p, q);
  if (a1 % g != a2 % g) return make_pair(0, -1);
  T m = m1 / g * m2;
  p = (p % m + m) % m;
  q = (q % m + m) % m;
  return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m, m);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), m(n);
    for (int i = 0; i < n; i++) {
      cin >> m[i] >> a[i];
    }
    T a1, m1, a2, m2;
    a1 = a[0], m1 = m[0];
    bool fail = 0;
    for (int i = 1; i < n; i++) {
      a2 = a[i], m2 = m[i];
      pair<T, T> p = CRT(a1, m1, a2, m2);
      if (p.second == -1) {
        fail = 1;
        break;
      }
      a1 = p.first;
      m1 = p.second;
    }
    cout << "Case " << ++tCase << ": ";
    if (fail) cout << "Impossible" << '\n';
    else cout << (long long)a1 << '\n'; 
  }
  return 0;
}
