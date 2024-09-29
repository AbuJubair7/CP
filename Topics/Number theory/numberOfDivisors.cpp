long long numberOfDivisors(long long num) {
  long long total = 1;
  for (int i = 2; 1ll * i * i <= num; i++) {
    if (num % i == 0) {
      int e = 0;
      while (num % i == 0) {
        e++;
        num /= i;
      }
      total *= e + 1;
    }
  }
  if (num > 1) {
    total *= 2;
  }
  return total;
}

// seive to pre calculate
vector<long long> numberOfDivisorsUpToN(long long n) { 
  vector<long long> divisors(n + 1);
  // For each i, update all multiples of i
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + i; j <= n; j += i) {
        divisors[j]++;
    }
  }
  return divisors;
}