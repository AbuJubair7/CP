/*
Author: Jubair_7
Date: 8 June 2022
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

		vector<ll> a(n);
		vector<ll> b(n);

		int yes = 1;

		FOR(i, n) cin>>a[i];
		FOR(i, n) cin>>b[i];
		
		ll diff = 0;
		int p = 1;
		for(int i = 0; i<n ;i++){
			if(a[i] < b[i]){
				p = 0;
				break;
			}else{
				diff = max(diff, a[i] - b[i]);
			}
		}

		if(p){
			for(int i = 0; i<n ;i++){
				ll temp = a[i] - diff;

				if(temp < 0) temp = 0;
				a[i] = temp;
			}

			for(int i = 0; i<n ; i++){
				if(a[i] != b[i]){
					p = 0;
					break;
				}
			}

		
		}

		if(p) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

		

	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
