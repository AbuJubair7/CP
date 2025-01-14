int n;
cin >> n;
vector<int> a(n + 1);
for (int i = 1; i <= n; i++) {
  cin >> a[i];
}
vector<int> f(n + 1);
for (int i = 1; i <= n; i++) {
  f[i] = 1;
  for (int j = 1; j < i; j++) {
    if (a[j] < a[i]) {
      f[i] = max(f[i], f[j] + 1);
    }
  }
}
int ans = 0;
for (int i = 1; i <= n; i++) {
  ans = max(ans, f[i]);
}
cout << ans << '\n';