/*
Author: Jubair_7
Date: 20 June 2022
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
		int n, m;
		cin>>n>>m;

		if(n == 1 && m ==1){
			cout<<1<<endl;
		}else if(n == 1){
			cout<<(m*(m+1))/2<<endl;
		}else if(m == 1){
			cout<<(n*(2*1+(n-1)))/2<<endl;
		}else{
			
			ll rowSum = (m*(m+1))/2;
			ll colSum = (2*m)+((n-1)*m);
			colSum *= n;
			colSum /= 2;
			cout<<rowSum+colSum-m<<endl;
			
		}
		
	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
