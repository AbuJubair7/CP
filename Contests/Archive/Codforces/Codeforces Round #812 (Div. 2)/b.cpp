/*
Author: jubs
Date: 6 Aug 2022
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
		vector<ll> vc(n);
		map<ll, vector<ll>> map;

		FOR(i, n){
			cin>>vc[i];
			map[vc[i]].pb(i);
		}

		ll maxEle = *max_element(vc.begin(), vc.end());
		


		

		int yes = 1;
		for(ll i = 0; i<map[maxEle].size()-1; ++i){
			if(abs(map[maxEle][i] - map[maxEle][i+1]) > 1){
				yes = 0;
				break;
			}
		}

		if(yes){
			int maxElInd = map[maxEle][0];
			

			// check left
			int leftOk = 1;
			int rightOk = 1;

			for(ll i = 0; i<maxElInd-1; i++){
				if(vc[i+1] < vc[i]){
					leftOk = 0;
					break;
				}
			}
			maxElInd = map[maxEle][map[maxEle].size()-1];
		
			
			//check right
			for(ll i = maxElInd+1; i<n-1; i++){
				
				if(vc[i+1] > vc[i]){
					rightOk = 0;
					break;
				}
			}	

			if(leftOk && rightOk) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;

		}else{
			cout<<"NO"<<endl;
		}
			
		
		

	}
	
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
