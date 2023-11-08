/*
Author: jubs
Date: 23 Sep 2022
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
		
		int n;
		cin>>n;

		for(int i = 1; i<=n; i++){

			
			if(i == 1) cout<<1;
			else if(i == 2) cout<<1<<" "<<1;
			else{
				int j = 1;
				while(j <= i){
					if(j == 1 || j == i) cout<<1<<" ";
					else cout<<0<<" ";
					j++;
				}
			}

			
			cout<<endl;
		}
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

