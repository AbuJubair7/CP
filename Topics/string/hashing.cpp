const int N = 2e5 + 7;

const int b1 = 137, b2 = 277, mod1 = 1000000007, mod2 = 987654319;
pair<int, int> P[N], IP[N];

int binpow (long long a, long long b, int m) {
  int res = 1;
  while (b) {
    if (1 & b) res = (1LL * res * a) % m;
    a = (1LL * a * a) % m;
    b >>= 1;
  }
  return res;
};

void preCal(){
  int ib1 = binpow(b1, mod1-2, mod1); // using fermat's little theorem a^(p-2)=a^-1 (mod p)
  int ib2 = binpow(b2, mod2-2, mod2);
  P[0] = {1, 1};
  IP[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    P[i] = {(1LL * b1 * P[i-1].first)%mod1, (1LL * b2 * P[i-1].second)%mod2};
    IP[i] = {(1LL * ib1 * IP[i-1].first)%mod1, (1LL * ib2 * IP[i-1].second)%mod2};
  }
}

struct Hash{
  pair<int, int> val[N];
  int n;
  Hash (){}
  void build(string s) {
    val[0] = {0, 0};
    n = s.length();
    for (int i = 0; i < n; i++) {
      int k = s[i];
      int h1 = ((1LL * k * P[i].first + val[i].first) % mod1) % mod1;
      int h2 = ((1LL * k * P[i].second + val[i].second) % mod2) % mod2;
      val[i + 1] = {h1, h2};
    }
  }
  pair<int, int> get_hash(int l, int r) {
    pair<int, int> curr;
    curr.first = (1LL * (val[r].first - val[l-1].first + mod1) * IP[l-1].first) % mod1;
    curr.second = (1LL * (val[r].second - val[l-1].second + mod2) * IP[l-1].second) % mod2;
    return curr;
  } 
} h, reverse_hash;