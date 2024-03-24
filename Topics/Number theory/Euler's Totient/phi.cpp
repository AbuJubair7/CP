int mx = 2e5 + 7;
vector<int> ph(mx);

void seive_phi (int n) {
  for (int i = 1; i<=n; i++) ph[i] = i;
  for (int i = 2; i<=n; i += 2) ph[i] -= ph[i] / 2;
  for (int i = 3; i <= n; i += 2) {
    if (ph[i] == i) {
      for (int j = i; j <= n; j += i) {
        ph[j] -= ph[j] / i;
      }
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