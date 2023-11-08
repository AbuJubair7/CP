/*
Author: jubs
Date: 4 Aug 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;



/*........................start.............................*/



void solve(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

		if(n == 1) cout<<2<<endl;
		else if(n == 2) cout<<1<<endl;
		else if(n == 3) cout<<1<<endl;
		else if(n == 4) cout<<2<<endl;
		else{
			if(n % 3 == 0){
				cout<<n/3<<endl;
			}
			else{
				// todo
				if(n % 3 == 2) cout<<n/3 + 1<<endl;
				else{
					// remainder 1
					n -= 4;
					cout<<n/3+2<<endl;
				}
			}
		}


	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
