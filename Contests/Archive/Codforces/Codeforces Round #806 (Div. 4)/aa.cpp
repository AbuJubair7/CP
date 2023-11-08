/*
Codeforces Round #807 (Div. 2) - A
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
		ll n, x;
		cin>>n>>x;
		vector<ll> vc(2*n);
		for(ll i = 0 ; i<2*n; i++) cin>>vc[i];
		sort(vc.begin(), vc.end());

		int possible = 1;
		for(ll i = 0; i<n; i++){
			if(i == 0){
				if(abs(vc[i]-vc[n]) < x){
				//	cout<<vc[i]<<" "<<vc[n]<<endl;
					possible = 0;
					break;
				}
			}else{
				if(abs(vc[i]-vc[n+i]) < x){
					//cout<<vc[i]<<" "<<vc[n+i]<<endl;
					possible = 0;
					break;
				}
			}
			//cout<<vc[i]<<" "<<vc[n+i]<<endl;
		}

		if(possible) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
