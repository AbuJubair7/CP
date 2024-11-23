/*
Author: jubair7
Date: 4/7/24
*/
#include<bits/stdc++.h>
 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int tt;
  cin >> tt;
  int tCase = 0;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int ans = -1;
    auto isPrime = [&](int x) -> bool {
      if (x == 2) {
        return true;
      }
      for (int i = 2; i <= sqrt(x); i++) {
        if(x % i == 0) {
          return false;
        }
      }
      return true;
    };
    auto generateFactors = [&](int x) -> vector<int> {
      vector<int> factors;
      if (x % 2 == 0) {
        factors.push_back(2);
      }
      while (x % 2 == 0) {
        x /= 2;
      }
      for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
          factors.push_back(i);
          while (x % i == 0) {
            x /= i;
          }
        }
      }
      if (x > 1) {
        factors.push_back(x);
      }
      return factors;
    };
    auto Bfs = [&](int x) -> void {
      vector<bool> visited(k + 1, false);
      vector<int> level(k + 1, -1);
      queue<int> q;
      if (!isPrime(x)) {
        q.push(x);
      }
      level[x] = 0;
      visited[x] = true;
      while (!q.empty()) {
        int val = q.front();
        q.pop();
        vector<int> factors = generateFactors(val);
        debug(factors);
        for (auto i : factors) {
          if (val + i <= k and !isPrime(val + i) and !visited[val + i]) {
            visited[val + i] = true;
            level[val + i] = level[val] + 1;
            q.push(val + i);
          }
        }
      }
      ans = level[k];
    };
    Bfs(n);
    cout << "Case " << ++tCase << ": " << (ans != -1 ? ans : -1) << '\n';
  }
  return 0;
}
