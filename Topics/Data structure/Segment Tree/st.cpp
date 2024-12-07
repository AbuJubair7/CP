const int N = 100000;
int a[N + 1];

struct ST {
  long long t[4 * N + 1];
  ST () {
    memset(t, 0, sizeof t);
  }
  void build (int n, int b, int e) {
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    int l = (n << 1);
    int r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] + t[r];
  }
  void upd (int n, int b, int e, int i, int x) {
    if (b > i or e < i) {
      return;
    }
    if (b == i and b == e) {
      t[n] = x;
      return;
    }
    int mid = (b + e) >> 1;
    int l = (n << 1);
    int r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = t[l] + t[r];
  }
  long long query (int n, int b, int e, int i, int j) {
    if (b > j or e < i) return 0;
    if (b >= i and e <= j) return t[n];
    int mid = (b + e) >> 1;
    int l = (n << 1);
    int r = l | 1;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
  }
};