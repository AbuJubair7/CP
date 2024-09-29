long long SumOfDivisors(long long num) {
  long long total = 1;
  for (int i = 2; 1ll * i * i <= num; i++) {
    if (num % i == 0) {
      int e = 0;
      while (num % i == 0) {
        e++;
        num /= i;
      }
      // Calculate the sum using the formula
      long long sum = (1ll * pow(i, e + 1) - 1) / (i - 1);
      total *= sum;
    }
  }
  if (num > 1) {
    // Handle the case where num is a prime number
    total *= (1 + num);
  }

  return total;
}

// seive to pre calculate
vector<long long> sumOfDivisorsUpToN(long long n) { 
  vector<long long> divisors(n + 1);
  // For each i, update all multiples of i
  for (long long i = 1; i <= n; i++) {
    for (long long j = i; j <= n; j += i) {
        divisors[j] += i;
    }
  }
  return divisors;
}