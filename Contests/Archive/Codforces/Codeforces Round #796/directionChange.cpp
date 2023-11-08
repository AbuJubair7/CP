/*
Author: Jubair_7
Date: 7 June 2022
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
		ll n, m;
		cin>>n>>m;

		if(n == 1 && m > 2 || m == 1 && n > 2) cout<<-1<<endl;
		else if(n == 1 && m == 1) cout<<0<<endl;
		else if(n == m) cout<<(n-1)*2<<endl;
		else if(n > m) 
			(n-m)%2 == 0 ? cout<<((m-1)*2) + ((n-m)*2)<<endl:cout<< ((m-1)*2) + (((n-m)*2)-1)<<endl;
		else 
			(m-n)%2 == 0 ? cout<<((n-1)*2) + ((m-n)*2)<<endl:cout<< ((n-1)*2) + (((m-n)*2)-1)<<endl;


	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
