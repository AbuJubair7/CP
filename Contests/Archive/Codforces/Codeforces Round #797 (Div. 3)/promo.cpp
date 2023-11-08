/*
Author: Jubair_7
Date: 12 June 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

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
	ll n, q, x, y;
		cin>>n>>q;
		vector<ll> p;

		FOR(i, n){
			ll k;
			cin>>k;
			p.pb(k);
		}

		sort(p.begin(), p.end(), greater<>());

		vector<ll> indexPrice;
		ll total = 0;
		FOR(i, n){
			total += p[i];
			indexPrice.pb(total);
		}

		

		for(ll i =0; i<q; i++){
			
			cin>>x>>y;
			ll leastMax = indexPrice[x-1] - indexPrice[x-y];
			leastMax += p[x-y];

			// for(ll j = x-y; j <x; j++){
			// 	leastMax += p[j];
			// }
			cout<<leastMax<<endl;

		}
}

int main(){
	BOOST;
	solve();

	return 0;
}
