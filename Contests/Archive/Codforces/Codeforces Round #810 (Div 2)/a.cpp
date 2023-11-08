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
		ll n;
		cin>>n;
		ll arr[n];
		if(n == 1) cout<<1<<endl;
		else{
			for(ll i = 0; i<n; i++){
				arr[i] = i+1;
			}
			for(ll i = 0; i<n-1; i += 2){
				swap(arr[i], arr[i+1]);
			}
			if(n % 2 != 0){
				swap(arr[n-1], arr[n-2]);
			}
			for(ll i = 0; i<n; i++){
				cout<<arr[i]<<" ";
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
