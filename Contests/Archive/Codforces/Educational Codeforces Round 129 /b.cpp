/*
Author: Jubair_7
Date: 23 May 2022
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
		ll  n;
		cin>>n;
		ll arr[n];

		FOR(i, n)cin>>arr[i];

		ll m;
		cin>>m;
		ll sum = 0;
		for(ll i = 0; i<m; i++){
			ll c;
			cin>>c;
			sum += c;
		}
		sum %= n;
		cout<<arr[sum]<<endl;
	}
}

int main(){
	BOOST;
	 solve();
	//cout<<3 % 2<<endl;
	return 0;
}
