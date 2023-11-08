/*
Author: jubs
Date: 30 Aug 2022
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
		char arr[2][n];

		for(int i = 0; i<2; i++){
			for(int j = 0; j<n; j++){
				char x;
				cin>>x;
				if(x == 'R'){
					arr[i][j] = x;
					
				}else arr[i][j] = 'X';

			}
			
		}

		int ok = 1;
		for(int i = 0; i<n; i++){
			if(arr[0][i] != arr[1][i]){
				ok = 0;
				break;
			}
		}


		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

