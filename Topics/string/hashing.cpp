const int N = 2e5 + 7;

const int b1 = 37, b2 = 177, mod1 = 1000000007, mod2 = 987654319;
pair<long long, long long> P[N], IP[N];

long long binpow (long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (1 & b) res = (res*a)%m;
    a = (a*a)%m;
    b >>= 1;
  }
  return res;
};

void preCal(){
  long long ib1 = binpow(b1, mod1-2, mod1); // using fermat's little theorem a^(p-2)=a^-1 (mod p)
  long long ib2 = binpow(b2, mod2-2, mod2);
  P[0] = {1, 1};
  IP[0] = {1, 1};
  for (int i = 1; i<N; i++) {
    P[i] = {(b1 * P[i-1].first)%mod1, (b2 * P[i-1].second)%mod2};
    IP[i] = {(ib1 * IP[i-1].first)%mod1, (ib2 * IP[i-1].second)%mod2};
  }
}

struct Hash{
  vector<pair<int, int>> val;
  int n;
  Hash (){}
  Hash(string s) {
    val.emplace_back(0, 0);
    n = s.length();
    for (int i = 0; i<n; i++) {
      int k = s[i]-'a'+1;
      int h1 = ((val[i].first + k * P[i].first) % mod1) % mod1;
      int h2 = ((val[i].second + k * P[i].second) % mod2) % mod2;
      val.push_back({h1, h2});
    }
  }
  pair<int, int> get(int l, int r) {
    pair<int, int> curr;
    curr.first = ((val[r].first - val[l-1].first + mod1) * IP[l-1].first) % mod1;
    curr.second = ((val[r].second - val[l-1].second + mod2) * IP[l-1].second) % mod2;
    return curr;
  }
  pair<int, int> get() {
    return get(1, n);
  } 
};