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
bool isPerfectSquare(ll n){
	if (ceil((double)sqrt(n)) == floor((double)sqrt(n)))
		return true;
	return false;
}


void solve(){
	ll t;
	cin>>t;
	while(t--){
		
		ll n;
		cin>>n;

		ll arr[n];
		for(ll i = 0; i<n ; i++) arr[i] = i;

		for(ll i = 0; i<n; i++){
			if(!isPerfectSquare(arr[i])){
				for(ll j = 0; j<n; j++){
					if(isPerfectSquare(arr[i]+arr[j])){
						swap(arr[i], arr[j]);
						break;
					}
				}
			}
		}

		for(ll i = 0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}
}

int main(){
	BOOST;
	solve();
	
	
	return 0;
}
