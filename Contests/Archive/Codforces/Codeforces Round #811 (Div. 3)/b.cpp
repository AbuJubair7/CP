/*
Author: jubs
Date: 1 Aug 2022
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
		vector<ll> arr(n);
		FOR(i, n) cin>>arr[i];

		map<ll, ll> map;
		int got = 0;
		ll key = 0;
		for(ll i = n-1; i>=0 ;i--){
			map[arr[i]]++;
			
			if(map[arr[i]] > 1) {
				got = 1;
				key = i;
				break;
			}
		}


		if(got){
			cout<<key-0+1<<endl;
		}else cout<<0<<endl;
		
	

	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
