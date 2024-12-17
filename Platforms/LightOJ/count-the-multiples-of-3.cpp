#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
const int N = 1e5;

struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  int t[4 * N + 1][3], lazy[4 * N + 1];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    int x = t[n][0];
    int y = t[n][1];
    int z = t[n][2];
    t[n][0] = t[n][1] = t[n][2] = 0;
    if (x) {
      t[n][lazy[n] % 3] = x;
    }
    if (y) {
      t[n][(lazy[n] + 1) % 3] = y;
    }
    if (z) {
      t[n][(lazy[n] + 2) % 3] = z;
    }
    if (t[n][0] == 0 and t[n][1] == 0 and t[n][2] == 0) {
      t[n][lazy[n] % 3] = e - b + 1;
    }
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline void pull(int n) {
    t[n][0] = t[lc][0] + t[rc][0];
    t[n][1] = t[lc][1] + t[rc][1];
    t[n][2] = t[lc][2] + t[rc][2];
  }
  inline long long combine(long long a, long long b) {
    return a + b;
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n][0] = 1;
      t[n][1] = 0;
      t[n][2] = 0;
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, int v) {
    push(n, b, e);
    if (b > j or e < i) return;
    if (b >= i and e <= j) {
      lazy[n] = v;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j or e < i) return 0;
    if (b >= i and e <= j) {
      return t[n][0];
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  int cs = 0;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    ST t;
    t.build(1, 1, n);
    cout << "Case " << ++cs << ":\n";
    while (q--) {
      int c, i, j;
      cin >> c >> i >> j;
      i++;
      j++;
      if (c == 0) {
        t.upd(1, 1, n, i, j, 1);
      } else {
        cout << t.query(1, 1, n, i, j) << '\n';
      }
    }
  }
  return 0;
}