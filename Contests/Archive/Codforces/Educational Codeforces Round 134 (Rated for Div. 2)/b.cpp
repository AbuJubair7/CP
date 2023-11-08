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
		
		int n, m, sX, sY, d;
		cin>>n>>m>>sX>>sY>>d;

		int ok = 0;

		// check left move
		if((abs(1-sY)) > d){
			if(abs(n-sX) > d){
				ok = 1;
			}
		}
		// check right move
		if(abs(1-sX) > d && !ok){
			if(abs(m - sY) > d){
				ok = 1;
			}
		}

		if(ok) cout<<n+m - 2<<endl;
		else cout<<-1<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

