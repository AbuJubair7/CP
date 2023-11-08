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



void solveTwo(){
	ll n, m;
		cin>>n>>m;

		int arr[n];
		FOR(i, n) cin>>arr[i];

		vector<ll> frontDamage(n);
		vector<ll> reverseDamage(n);

		for(ll i = 1 ; i<n; i++){
			if(arr[i-1] > arr[i]){
				frontDamage[i] += (frontDamage[i-1] + abs(arr[i-1]-arr[i]));

			}else{
				frontDamage[i] += frontDamage[i-1];
			}
			

			if(arr[i-1] < arr[i]){
				reverseDamage[i] += (reverseDamage[i-1]+ abs(arr[i-1]-arr[i]));
			}else reverseDamage[i] += reverseDamage[i-1];
		}


		for(ll i = 0; i<m; i++){
			ll p,q;
			cin>>p>>q;
			ll damage = 0;
			if(p == q) cout<<damage<<endl;
			else{
				p--;
				q--;
				if(p<q){
					//cout<<frontDamage[q]<<" "<<frontDamage[p]<<endl;
					damage = abs(frontDamage[p]-frontDamage[q]);

					
				}else{
					damage = abs(reverseDamage[p]-reverseDamage[q]);
				}
				cout<<damage<<endl;
			}

		}
}

int main(){
	BOOST;
	solveTwo();
	
	//cout<<(10 ^ 10 ^ 7 ^ 6)<<endl;
	
	return 0;
}
