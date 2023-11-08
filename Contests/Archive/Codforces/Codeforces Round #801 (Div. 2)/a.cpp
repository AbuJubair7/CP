/*
Author: Jubair_7
Date: 18 June 2022
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
		ll n, m, r, c;
		ll mx = INT_MIN;
		cin>>n>>m;

		ll arr[n][m];

		for(ll row= 0; row<n; row++){

			for(ll col = 0; col<m; col++){
				cin>>arr[row][col];
				
				if(arr[row][col] > mx){
					r = row+1;
					c = col+1;
					mx = arr[row][col];
				}

			}
	
		}
		r = max(r, n-r+1);
		c = max(c, m-c+1);

		cout<<r*c<<endl;
		
		
	
	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
