/*
Author: jubs
Date: 29 Sep 2022
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

		int d[n+1];

		int ok = 1;
		for(int i = 0; i<n; i++){
			cin>>d[i];
		}
	
		 for(int i = 0; i<n-1; i++){
				if(d[i+1] <= d[i] and d[i+1] != 0){
					ok = 0;
					break;

				}else{
					d[i+1] = d[i] + d[i+1];
				}
		}
		

		if(ok){
			
			for(int i = 0; i<n; i++){
				cout<<d[i]<<" ";
			}
			cout<<endl;
		}else cout<<-1<<endl;

		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

