/*
Author: Jubair_7
Date: 16 July 2022
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



void solveTwo(){
	ll t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n];
		FOR(i,n)cin>>arr[i];
		int ok = 1;
		for(int i = 1; i<n; i++){
			if(arr[i] % arr[0] !=0){
				ok = 0;
				break;
			}
		}

		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
