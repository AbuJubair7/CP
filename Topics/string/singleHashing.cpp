const int N = 1e6 + 7;

const int b1 = 37, b2 = 177, mod1 = 1000000007, mod2 = 987654319;
long long P[N], IP[N];

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
  P[0] = 1;
  IP[0] = 1;
  for (int i = 1; i<N; i++) {
    P[i] = (b1 * P[i-1])%mod1;
    IP[i] = (ib1 * IP[i-1])%mod1;
  }
}

struct Hash{
  vector<int> val;
  int n;
  Hash (){}
  Hash(string s) {
    val.emplace_back(0);
    n = s.length();
    for (int i = 0; i<n; i++) {
      int k = s[i]-'a'+1;
      int h1 = ((val[i] + k * P[i]) % mod1) % mod1;
      val.push_back(h1);
    }
  }
  int get(int l, int r) {
    int curr;
    curr = ((val[r] - val[l-1] + mod1) * IP[l-1]) % mod1;
    return curr;
  }
  int get() {
    return get(1, n);
  } 
};