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
		
		int n, x, y;
		cin>>n;

		vector<pair<int, int>> vc;

		for(int i = 0; i<n; ++i){
			int x, y;
			cin>>x>>y;
			vc.pb({x,y});
		}
		int pX = INT_MIN;
		int pY = INT_MIN;
		int nX = INT_MIN;
		int nY = INT_MIN;

		for(auto v : vc){
			if(v.first >= 0){
				if(v.first > pX) pX = v.first;
			}else{
				if(v.first*(-1) > nX) nX = v.first * (-1);
			}

			if(v.second >= 0){
				if(v.second > pY) pY = v.second;
			}else{
				if(v.second*(-1) > nY) nY = v.second * (-1);
			}

		}
		
		int result = 2*pX + 2*pY + 2*nX + 2*nY;
		cout<<result<<endl;


	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
