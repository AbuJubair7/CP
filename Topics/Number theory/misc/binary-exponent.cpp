// a ^ b mod m
long long binpow (long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (1 & b) res = (res*a)%m;
    a = (a*a)%m;
    b >>= 1;
  }
  return res;
};