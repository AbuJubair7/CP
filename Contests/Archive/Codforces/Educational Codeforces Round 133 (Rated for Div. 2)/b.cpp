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
		int n;
		cin>>n;
		vector<int> vc(n,0);
		vector<vector<int>> pArr;

		for(int i = 0; i<n; i++)
			vc[i] = i+1;

		pArr.pb(vc);
		for(int i = 0; i<n-1; i++){
			int temp = vc[n-1];
			vc[n-1] = vc[i];
			vc[i] = temp;
			pArr.pb(vc);
		}

		cout<<pArr.size()<<endl;

		for(auto p : pArr){
			for(auto i : p)
				cout<<i<<" ";
			cout<<endl;
		}


	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
