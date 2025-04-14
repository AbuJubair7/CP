const int N = 2e5 + 1;

int a[N + 1], n, q;

struct ST {
  #define lc (node << 1)
  #define rc ((node << 1) | 1)
  long long t[4 * N + 1];
  long long lazy_add[4 * N + 1];
  long long lazy_assign[4 * N + 1];
  bool assigned[4 * N + 1];
  ST() {
    memset(t, 0, sizeof(t));
    memset(lazy_add, 0, sizeof(lazy_add));
    memset(lazy_assign, 0, sizeof(lazy_assign));
    memset(assigned, 0, sizeof(assigned));
  }
  inline void push(int node, int l, int r) {
    if(l > r) return;
    if(assigned[node]) {
      t[node] = lazy_assign[node] * (r - l + 1);
      if(l != r) {
        assigned[lc] = true;
        lazy_assign[lc] = lazy_assign[node];
        lazy_add[lc] = 0;
        assigned[rc] = true;
        lazy_assign[rc] = lazy_assign[node];
        lazy_add[rc] = 0;
      }
      assigned[node] = false; 
    }
    if(lazy_add[node] != 0) {
      t[node] += lazy_add[node] * (r - l + 1);
      if(l != r) {
        if(assigned[lc]) {
          lazy_assign[lc] += lazy_add[node];
        } else {
          lazy_add[lc] += lazy_add[node];
        }
        if(assigned[rc]) {
          lazy_assign[rc] += lazy_add[node];
        } else {
          lazy_add[rc] += lazy_add[node];
        }
      }
      lazy_add[node] = 0;
    }
  }
  inline long long combine(long long leftVal, long long rightVal) {
    return leftVal + rightVal;
  }
  inline void pull(int node) {
    t[node] = t[lc] + t[rc];
  }
  void build(int node, int l, int r) {
    lazy_add[node] = 0;
    assigned[node] = false;
    if(l == r) {
      t[node] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pull(node);
  }
  void update_assign(int node, int l, int r, int i, int j, long long v) {
    push(node, l, r);
    if(r < i || l > j) return;
    if(i <= l && r <= j) {
      assigned[node] = true;
      lazy_assign[node] = v;
      lazy_add[node] = 0;
      push(node, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update_assign(lc, l, mid, i, j, v);
    update_assign(rc, mid + 1, r, i, j, v);
    pull(node);
  }
  void update_add(int node, int l, int r, int i, int j, long long v) {
    push(node, l, r);
    if(r < i || l > j) return;
    if(i <= l && r <= j) {
      if(assigned[node]) {
          lazy_assign[node] += v;
      } else {
          lazy_add[node] += v;
      }
      push(node, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update_add(lc, l, mid, i, j, v);
    update_add(rc, mid + 1, r, i, j, v);
    pull(node);
  }
  long long query(int node, int l, int r, int i, int j) {
    push(node, l, r);
    if(r < i || l > j) return 0;
    if(i <= l && r <= j) return t[node];
    int mid = (l + r) >> 1;
    return combine(query(lc, l, mid, i, j), query(rc, mid + 1, r, i, j));
  }
} t;