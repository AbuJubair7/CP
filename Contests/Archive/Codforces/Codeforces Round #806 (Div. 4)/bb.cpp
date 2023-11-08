/*
Codeforces Round #807 (Div. 2) - B
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

int findUpperBound(int arr[], int n, int key){
	int left = 0;
	int right = n-1;

	while(left <= right){
		int mid = (right + left)/2;

		if(arr[mid] == key || arr[mid] < key){
			left = mid+1;
		}else{
			
			right = mid-1;
		}
	}

	return right;
}

/*........................start.............................*/



void solveTwo(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);

		for(auto &i : v)
			cin>>i;

		ll ans = 0;
		int start = 0;
		for(ll i = 0; i<n-1; i++){
			if(v[i] > 0)start = 1;
			if(start){
				if(v[i] > 0) ans += v[i];
				else ans++;
			}
			
		}

		cout<<ans<<endl;
	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
