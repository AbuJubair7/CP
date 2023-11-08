/*
Author: Jubair_7
Date: 12 July 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;

int findLowerBound(int arr[], int n, int key){
	int left = 0;
	int right = n-1;

	while(left <= right){
		int mid = (right + left)/2;

		if(arr[mid] == key || arr[mid] > key){
			right = mid-1;
		}else{
			left = mid+1;
		}
	}

	return left;
}

/*........................start.............................*/



void solve(){
	ll t;
	cin>>t;
	while(t--){
		ll n = 0, k = 0, a = 0, b = 0;
		cin>>n>>k;

		ll arr[n];

		map<ll, vector<ll>> map;

		for(ll i = 0; i<n ; i++){
			ll x;
			cin>>x;
			map[x].pb(i);
		}

		for(ll q = 1; q<=k; q++){
			cin>>a>>b;

			if(map.count(a) && map.count(b)){
				if(a == b) cout<<"YES"<<endl;
				else{
			
					if(map[a][0] < map[b][map[b].size()-1])
						cout<<"YES"<<endl;
					else cout<<"NO"<<endl;

				}
			}else cout<<"NO"<<endl;
		}
	

	}
}

int main(){
	BOOST;
	solve();
		

	
	return 0;
}
