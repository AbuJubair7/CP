//https://vjudge.net/problem/spoj-dsubseq
// dp[i] = number of subsequence can be made if start from i
// why calculating from each character last appearenc?
// becase taking every index can have same character
// so just by taking which character should start the string 
// can decide the total number of subsequence.
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int mod = 1000000007, N = 100000 + 7;
string s;
int n, dp[N];
vector<vector<int>> nxt(N, vector<int> (26, N));

int f(int i) {
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 1;
  for (int j = 0; j < 26; j++) {
    if (nxt[i][j] != N) {
      ans = (ans + f(nxt[i][j])) % mod;
    }
  }
  return ans % mod;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof dp);
    vector<int> last(26, N);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        nxt[i][j] = last[j];
      }
      last[s[i] - 'A'] = i;
    }
    f(0);
    long long sum = 0;
    for (int i = 0; i < 26; i++) {
      if (last[i] != N) {
        sum = (sum + dp[last[i]]) % mod;
      }
    }
    cout << sum + 1 << '\n';
    for (int i = 0; i < n; i++) {
      fill(nxt[i].begin(), nxt[i].end(), N);
    }
  }
  return 0;
} 