// summation off (mx - min) of all subarray
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e6 + 7, inf = 1e7;
int n, a[N];
long long ans;

void get(int c) {
  vector<int> lt(n + 1), rt(n + 1);
  stack<int> st;
  a[0] = (c ? inf : -inf);
  st.push(0);
  for (int i = 1; i <= n; i++) {
    lt[i] = i;
    while (!st.empty() and (c ? a[st.top()] <=  a[i] : a[st.top()] >=  a[i])) {
      st.pop();
    }
    lt[i] = st.top() + 1;
    st.push(i);
  }
  while (!st.empty()) st.pop();
  a[n + 1] = (c ? inf : -inf);
  st.push(n + 1);
  for (int i = n; i >= 1; i--) {
    while (!st.empty() and (c ? a[st.top()] <  a[i] : a[st.top()] > a[i])) {
      st.pop();
    }
    rt[i] = st.top() - 1;
    st.push(i);
  }
  for (int i = 1; i <= n; i++) {
    int l = lt[i];
    int r = rt[i];
    long long cnt = (i - l) + 1LL * (i - l + 1) * (r - i);
    if (c) {
      ans += cnt * a[i];
    } else {
      ans -= cnt * a[i];
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  get(1);
  get(0);
  cout << ans << '\n';
  return 0;
}