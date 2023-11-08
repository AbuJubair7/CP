/*
Author: jubs
Date: 24 July 2022
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
		ll n, m;
		cin>>n>>m;
		ll arr[n];
		FOR(i, n) cin>>arr[i];

		vector<pair<ll, ll>> vc;
		set<ll> pStart;
		map<ll, ll> mp;

		for(int i = 0; i<m; i++){
			ll x , y;
			cin>>x>>y;
			vc.pb({x-1,y-1});
			pStart.insert(x-1);
			mp[x-1]++;
		}

		if(m % 2 == 0) cout<<0<<endl;
		else{
			ll min = INT_MAX;
			ll p = INT_MAX;
			for(auto i : vc){
				// cout<<i.first<<" "<<i.second<<endl;
				if(i.first < min){
					min = i.first;
					p = i.second;
				}else if(i.second < min){
					min = i.second;
					p = i.first;
				}
			}

			// cout<<min<<"---- "<<p<<endl;  
			// cout<<arr[min]<<endl;
			if(pStart.find(min) != pStart.end()){
				cout<<arr[min]+arr[p]<<endl;
			}else{
				cout<<arr[min]<<endl;
			}
		}
		
	

	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
