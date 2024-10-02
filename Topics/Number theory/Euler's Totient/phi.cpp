vector<long long> phi(mx + 1);
for (int i = 0; i <= mx; i++) {
  phi[i] = i;
}
for (int i = 2; i <= mx; i++) {
  if (phi[i] == i) {
    for (int j = i; j <= mx; j += i) {
      phi[j] -= phi[j] / i;
    }
  }
}

int phi(int n) {
  int result = n;
  for (int i = 2; 1ll * i * i <= n; i += (i == 2 ? 1 : 2)) {
    if (n % i == 0) {
      while (n % i == 0)
          n /= i;
      result -= result / i;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}