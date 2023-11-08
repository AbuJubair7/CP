/*
Author: jubs
Date: 21 July 2022
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
		int x,a,b,c;
		cin>>x>>a>>b>>c;
		int arr[3] = {a,b,c};

		if(arr[x-1] == 0) cout<<"NO"<<endl;
		else {
			x = arr[x-1];
			
			if(arr[x-1] == 0) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
			
		}
		

	}
}

int main(){
	BOOST;
	solve();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
