/*
Author: jubs
Date: 14 sep 2022
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
		
		ll n;
		cin>>n;

		vector<ll> v1(n);
		vector<ll> v2(n);

		vector<ll> remain(n);

		for(int i = 0; i<n; i++) cin>>v1[i];

		for(int i = 0; i<n; i++) cin>>v2[i];

		for(int i = 0; i<n; i++) remain[i] = v2[i]-v1[i];

		sort(remain.begin(), remain.end(), greater<ll>());
		

		if(remain[0] < 0) cout<<0<<endl;
		else{
			ll i = 0;
			ll j = n-1;
			int ans = 0;
			while(i < j){
				if(remain[i] + remain[j] >= 0){
					ans++;
					i++;
					j--;
				}else{
					j--;
				}
			}

			cout<<ans<<endl;

		}
	}
}

int main(){
	BOOST;
	solve();



	return 0;
}

