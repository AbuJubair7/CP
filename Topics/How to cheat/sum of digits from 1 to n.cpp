long long sumOfDigits( long long n ) {
  if ( n <= 0 ) return 0;
  long long res = 0;
  for ( long long p = 1; p <= n; p *= 10 ) {
    long long pp10 = p * 10;
    long long high = n / pp10;
    long long cur  = (n / p) % 10;
    long long low  = n % p;
    res += high * p * 45 + (cur * (cur - 1) / 2) * p + cur * (low + 1);
  }
  return res;
}