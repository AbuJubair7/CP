/*
Author: jubs
Date: 12 sep 2022
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
		ll a, b, c;
		cin>>a>>b>>c;

		int add = abs(b-c) + c;

		if(add < a) cout<<2<<endl;
		else if(add  == a) cout<<3<<endl;
		else cout<<1<<endl;
		

		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

