/**
 *    author:  jubair7
 *    created: 26.11.2024 14:03:54
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
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    string start_m, end_m;
    char comma;
    long long start_y, end_y, start_d, end_d;
    cin >> start_m >> start_d >> comma >> start_y;
    cin >> end_m >> end_d >> comma >> end_y;
    int start = (start_y - 1) / 4 - (start_y - 1) / 100 + (start_y - 1) / 400;
    int end = end_y / 4 - end_y / 100 + end_y / 400;
    auto is_leap = [] (int n) -> bool {
      return ((n % 4 == 0 and n % 100 != 0) or n % 400 == 0);
    };
    if (is_leap(start_y) and (start_m != "January" and start_m != "February")) {
      start++;
    }
    if (is_leap(end_y) and (end_m == "January" or (end_m == "February" and end_d < 29))) {
      end--;
    }
    cout << "Case " << ++tCase << ": " << end - start << '\n';
  }
  return 0;
}
