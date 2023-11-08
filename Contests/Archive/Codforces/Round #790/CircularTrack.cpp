/*
Author: Jubair_7
Date: 11 May 2022
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
		ll a, b, m;

		cin>>a>>b>>m;

		ll n1 = abs(a - b);
		ll n2 = 0;
		if(b > a) n2 = (m - b) + a;
		else n2 = (m - a) + b;

		n1 < n2? cout<<n1<<endl:cout<<n2<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
