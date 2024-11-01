/**
 *    author:  jubair7
 *    created: 01.11.2024 12:40:23
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
  int tCase = 0;
  int cnt = 100;
  int tt;
  cin >> tt;
  while (tt--) {
    cout << "Case " << ++tCase << ": " << '\n';
    stack<string> visit, forward;
    stack<string> empty;
    string d = "http://www.lightoj.com/";
    visit.push(d);
    while (true) {
      string s;
      cin >> s;
      if (s == "VISIT") {
        cin >> s;
        visit.push(s);
        cout << visit.top() << '\n';
        while (!forward.empty()) forward.pop();
      } else if (s == "BACK") {
        if (visit.top() != d) {
          forward.push(visit.top());
        }
        visit.pop();
        cout << (visit.empty() ? "Ignored" : visit.top()) << '\n';
        if (visit.empty()) visit.push(d);
      } else if (s == "FORWARD") {
        if (!forward.empty()) {
          visit.push(forward.top());
          forward.pop();
          cout << visit.top() << '\n';
        } else cout << "Ignored" << '\n'; 
      } else {
        break;
      }
    }
  }
  return 0;
}
