/*
Author: jubs
Date: 20 Sep 2022
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
		
		int n, k;
		cin>>n>>k;

		ll arr[n+1];

		for(int i = 1; i<=n; i++){
			cin>>arr[i];
		}
		

		ll sum = 0;
		
		for(int i = 1; i<=k; i++){
			ll m = 0;

			for(int j = i; j<=n; j += k){
				m = max(m, arr[j]);
			}
			sum += m;
		}

		cout<<sum<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

