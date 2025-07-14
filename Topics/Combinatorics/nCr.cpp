#include<bits/stdc++.h>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int C[N][N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  C[0][0] = 1;
  for (int n = 1; n < N; n++) {
    C[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
    }
  }
  cout << C[6][2] << '\n';
  return 0;
}