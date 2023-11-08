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
		ll n;
		cin>>n;

		ll arr[n], arr2[n];

		for(int i = 0; i<n ;i++){
			cin>>arr[i];
		}
		for(int i = 0; i<n ;i++){
			cin>>arr2[i];
		}
		ll c = 0;

		for(int i = 0; i<n-1; i++){
			ll x = arr[i] , y = arr2[i]; 
			for(int j = i+1; j<n ;j++){
				if(x == arr2[j] && arr[j] == y)
					c++;
			}
		}

		cout<<c<<endl;
		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
