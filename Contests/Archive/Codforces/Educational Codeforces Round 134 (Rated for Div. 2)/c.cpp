/*
Author: jubs
Date: 27 Aug 2022
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

		ll arr[n];
		ll arr2[n];

		ll first = 0;
		ll last = 0;
		

		for(ll i = 0; i<n; i++){
			cin>>arr[i];
		}
		for(ll i = 0; i<n; i++){
			cin>>arr2[i];
			
		}
		first = arr2[0];
		last = arr2[n-2];
		// find min
		for(ll i =0; i<n; i++){
			
		}
			

		cout<<endl;

		for(ll i =0; i<n; i++){
			
		}
			

		cout<<endl;
		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

