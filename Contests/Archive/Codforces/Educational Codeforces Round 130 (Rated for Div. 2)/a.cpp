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
	ll t;
	cin>>t;

	while(t--){
		
		ll n, m;
		cin>>n>>m;
		ll totalDis = 0;
		FOR(i, n){
			ll dis;
			cin>>dis;
			totalDis+=dis;
		}

		if(totalDis <= m) cout<<0<<endl;
		else cout<<(totalDis-m)<<endl;
     }
}

int main(){
	BOOST;
	solve();

	return 0;
}
