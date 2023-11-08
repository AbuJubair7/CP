/*
Author: jubair7
Date: 15 Aug 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

void solve(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<long long> preSum(n+1);
    long long sum = 0;
    for(int i = 1; i<=n; i++){
      sum += (i*i);
      preSum[i] = sum;
    }
    int last = n;
    sum = 0;
    long long revTot = ((long long)n*(n+1))/2ll;
    revTot -= 1;
    for(int i = 2; i<=n; i++){
      sum += (last*i);
      last--;
    }
    long long ans = INT_MIN;
    int dec  = 2;
    while(dec <= n){
      int mid = n-dec + 1;
      if(mid % 2 == 1) mid = mid/2+1;
      else mid /= 2;
      int ind = dec + mid-1;
      int mx = (n-mid+1)*ind;
      ans = max(ans, (preSum[dec-1]+sum)-mx);
      revTot -= dec;
      sum -= (n*dec);
      sum += (revTot) ;
      dec++;
    }
    if(n == 2) cout << 2 << '\n';
    else
      cout << ans << '\n';
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}