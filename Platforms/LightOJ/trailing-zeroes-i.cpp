/**
 *    author:  jubair7
 *    created: 23.11.2024 09:07:44
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int N = sqrtl(1e12);
  bitset<N + 1> is_prime;
  vector<int> primes;
  for (int i = 3; i <= N; i += 2) {
    is_prime[i] = true;
  }
  primes.push_back(2);
  for (int i = 3; 1ll * i * i <= N; i += 2) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += (i + i)) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 3; i <= N; i += 2) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    long long n;
    cin >> n;
    int ans = 1;
    for (auto p : primes) {
      if (1ll * p * p > n) break;
      int e = 0;
      while (n % p == 0) {
        n /= p;
        e++;
      }
      ans *= (e + 1);
    }
    if (n > 1) {
      ans *= 2;
    }
    cout << "Case " << ++tCase << ": " << ans - 1 << '\n';
  }
  return 0;
}
