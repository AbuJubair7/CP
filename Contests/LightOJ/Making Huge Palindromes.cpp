/*
Author: jubair7
Date: 8/3/24
*/
#include<bits/stdc++.h>
 
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 1e6 + 7;

const int b1 = 37, b2 = 177, mod1 = 1000000007, mod2 = 987654319;
pair<long long, long long> P[N], IP[N];

long long binpow (long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (1 & b) res = (res*a)%m;
    a = (a*a)%m;
    b >>= 1;
  }
  return res;
};

void preCal(){
  long long ib1 = binpow(b1, mod1-2, mod1); // using fermat's little theorem a^(p-2)=a^-1 (mod p)
  long long ib2 = binpow(b2, mod2-2, mod2);
  P[0] = {1, 1};
  IP[0] = {1, 1};
  for (int i = 1; i<N; i++) {
    P[i] = {(b1 * P[i-1].first)%mod1, (b2 * P[i-1].second)%mod2};
    IP[i] = {(ib1 * IP[i-1].first)%mod1, (ib2 * IP[i-1].second)%mod2};
  }
}

struct Hash{
  vector<pair<int, int>> val;
  vector<pair<int, int>> rev_val;
  int n;
  Hash (){}
  Hash(string s) {
    val.emplace_back(0, 0);
    rev_val.emplace_back(0, 0);
    n = s.length();
    for (int i = 0, j = n-1; i<n; i++, j--) {
      int k = s[i]-'a'+1;
      int h1 = ((val[i].first + k * P[i].first) % mod1) % mod1;
      int h2 = ((val[i].second + k * P[i].second) % mod2) % mod2;
      val.push_back({h1, h2});
      k = s[j]-'a'+1;
      h1 = ((rev_val[i].first + k * P[i].first) % mod1) % mod1;
      h2 = ((rev_val[i].second + k * P[i].second) % mod2) % mod2;
      rev_val.push_back({h1, h2});

    }
  }
  pair<int, int> get(int l, int r, vector<pair<int, int>> &v) {
    pair<int, int> curr;
    curr.first = ((v[r].first - v[l-1].first + mod1) * IP[l-1].first) % mod1;
    curr.second = ((v[r].second - v[l-1].second + mod2) * IP[l-1].second) % mod2;
    return curr;
  }
  pair<int, int> get(vector<pair<int, int>> val) {
    return get(1, n, val);
  } 
  bool is_palindrome(int l, int r) {
    pair<int, int> p1 = this->get(l, r, this->val);
    pair<int, int> p2 = this->get(1, n-l+1, this->rev_val);
    return p1 == p2;
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  int tCase = 1;
  preCal();
  while (tt--) {
    string s;
    cin >> s;
    Hash h(s);
    int ans = s.length()+s.length()-1;
    for (int i = 1; i<=s.length(); i++) {
      if (h.is_palindrome(i, s.length())) {
        ans = s.length()+(i-1);
        break;
      }
    }
    cout << "Case " << tCase++ << ": " << ans << '\n'; 
  }
}