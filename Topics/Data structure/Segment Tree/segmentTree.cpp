class SegmentTree {
  public:
    int n;
    vector<long long> segTree;
    vector<int> &a;
    SegmentTree(int n, vector<int> &a) : n(n), segTree(n * 4, 0), a(a) {
      build(1, 1, n);
    }
    void build (int node, int l, int r) {
      if (l == r) {
        segTree[node] = a[l];
        return;
      }
      build(node * 2, l, (l + r) >> 1);
      build(node * 2 + 1, ((l + r) >> 1) + 1, r);
      pull(node);
    }
    long long query(int l, int r) {
      return get(1, 1, n, l, r);
    }
    long long get(int node, int L, int R, int l, int r){
      if(L > r or R < l) return 0;
      else if(L >= l and R <=r) return segTree[node];
      int mid = (L+R)>>1;
      long long left = get(node * 2,L, mid, l, r);
      long long right = get(node * 2+1, mid+1, R, l , r);
      return left+right;
    }
    void update(int key, int val) {
      modify(1, 1, n, key, val);
    }
    void modify(int node, int l, int r, int key, int val){
      if(l == r){
        segTree[node] = val;
        return;
      }
      int mid = (l+r)>>1;
      if(key <= mid){
        modify(node*2, l, mid, key, val);
      }else{
        modify(node*2+1, mid+1, r, key, val);
      }
      pull(node);
    }
    void pull(int node) {
      segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
};