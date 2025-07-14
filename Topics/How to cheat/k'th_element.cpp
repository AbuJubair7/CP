// https://atcoder.jp/contests/abc155/tasks/abc155_d

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
  long long n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ranges::sort(a.begin() + 1, a.end());
  long long lo = -1e18;
  long long hi = 1e18;
  long long ans = 0;
  while (lo <= hi) {
    long long tmp_k = (lo + hi) / 2;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      int l = i;
      int r = n;
      int idx = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (1LL * a[i] * a[mid] <= tmp_k) {
          idx = mid;
          if (a[i] < 0) r = mid - 1;
          else l = mid + 1;
        } else {
          if (a[i] < 0) l = mid + 1;
          else r = mid - 1;
        }
      }
      if (idx == -1) continue;
      if (a[i] < 0) {
        cnt += n - idx;
        if (idx != i) cnt++;
      } else {
        cnt += idx - i;
      }
    }
    if (cnt >= k) {
      hi = tmp_k - 1;
      ans = tmp_k;
    } else {
      lo = tmp_k + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}