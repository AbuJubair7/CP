// largest rectangle in a histogram
// https://vjudge.net/problem/SPOJ-HISTOGRA
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif


// a monotonic stack only stores in non decreasing order
// so i only pop all the value untill till the top is greater that a[i]
// after poping each value, the current top is lesser that popped one
// and all the values between current top idx and the popped idx has to be greater
// than the current popped value.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n) {
    vector<int> a(n + 2);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[n + 1] = -1;
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
      while (!st.empty() and a[i] < a[st.top()]) { 
        int h = a[st.top()];
        int idx = st.top();
        st.pop();
        int l = st.empty() ? 1 : st.top() + 1;
        int w = i - l;
        ans = max(ans, 1LL * h * w);
      }
      st.push(i);
    }
    cout << ans << '\n';
    cin >> n;
  } 
  return 0;
}