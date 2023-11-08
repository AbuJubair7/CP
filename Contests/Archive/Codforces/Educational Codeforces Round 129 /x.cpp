/*
Author: Jubs
Date: 23 May 2022
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef long long ll;



int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
		ll cards[n];

		for(ll i =0; i<n ;i++){
			cin>>cards[i];
		}

		ll m;
		cin>>m;
		ll arr[m];
		ll sum = 0;

		for(ll i = 0; i<m; i++){
			cin>>arr[i];
		}

		for(ll i = 0; i<m ; i++){
			sum += arr[i];
		}

		sum %= n;

		cout<<cards[sum]<<endl;
		


	}
	return 0;
}

