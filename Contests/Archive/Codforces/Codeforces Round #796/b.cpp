/*
Author: Jubair_7
Date: 3 June 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
	return (a*b)/gcd(a,b);
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		int n, q, l, r, k, x, y, z, t;
  int sum = 0, cnt = 0, ans = 0;
  cin >> n;
  vector<int> a(n);
  
  x = 0, y = 0;
   for(int i = 0; i<n; i++)
  {
    cin>>a[i];
    
    if(a[i] & 1 ) y++;
    else x++;
  }
  
  if(y > 0)
  {
    cout<<(x)<<endl;;
  }
  else
  {
    int mn = INT_MAX;
    for(int i = 0; i<n; i++)
    {
      if(a[i] % 2 == 0)
      {
        cnt = 0;
        while(a[i] % 2 == 0)
        {
          cnt++;
          a[i] = a[i] / 2;
        }
        
        mn = min(mn, cnt);
      }
    }
    
    cout<<(mn + x-1)<<endl;;
  }
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
