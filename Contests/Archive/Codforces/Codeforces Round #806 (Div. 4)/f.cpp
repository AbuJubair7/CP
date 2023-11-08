/*
Author: Jubair_7
Date: 15 July 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;

ll findUpperBound(ll arr[], ll n, ll key){
	ll left = 0;
	ll right = n-1;

	while(left <= right){
		ll mid = (right + left)/2;

		if(arr[mid] == key || arr[mid] < key){
			left = mid+1;
		}else{
			
			right = mid-1;
		}
	}

	return left;
}

/*........................start.............................*/



void solveTwo(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		ll arr2[n];

		map<ll, vector<ll>> map;
		FOR(i, n) {
			cin>>arr[i];
			map[arr[i]].pb(i+1);
		//	arr2[i] = arr[i];
		}

		ll ans = 0;
		sort(arr, arr+n);

		for(ll i = 0; i<n-1; i++){
			if(arr[i] < map[arr[i]]){
				cout<<arr[i]<<" <"<<map[arr[i]]<<endl;
				ll upper = findUpperBound(arr, n, i+1);
				//cout<<"upper: "<<upper<<endl;

				if(upper < n){
					for(ll j = upper; j <n; j++){
						if(arr[j] < map[arr[j]]) ans++;
					}
				}
			}
		}

		// brute force wont work.
		// FOR(i, n){
		// 	if(arr[i] < (i+1)){
				
		// 		for(ll j = i+1; j<n; j++){
		// 			if(arr[j] < (j+1) && (i+1) < arr[j] && arr[i] < arr[j] ){
		// 				ans++;
						
		// 			}
		// 		}
		// 	}

		// }
		cout<<ans<<endl;
	}
}

int main(){
	BOOST;
	solveTwo();
	// ll arr[] = {1,2,3,4,4,5,6};
	// cout<<findUpperBound(arr, 7, 4);
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
