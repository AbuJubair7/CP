string a, b;
cin >> a >> b;
int n = a.length();
int m = b.length();
vector<vector<int>> f(n + 1, vector<int>(m+1));
for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++) {
    if (a[i-1] == b[j-1]) {
      f[i][j] = 1 + f[i-1][j-1];
      continue;
    }
    f[i][j] = max(f[i-1][j], f[i][j-1]);
  }
}
string ans;
int i = n;
int j = m;
while (i > 0 and j > 0) {
  if (a[i-1] == b[j-1]) {
    ans.push_back(a[i-1]);
    i--;
    j--;
  } else if (f[i-1][j] > f[i][j-1]) {
    i--;
  } else {
    j--;
  }
}
debug(f[n][m]);
reverse(ans.begin(), ans.end());
debug(ans);