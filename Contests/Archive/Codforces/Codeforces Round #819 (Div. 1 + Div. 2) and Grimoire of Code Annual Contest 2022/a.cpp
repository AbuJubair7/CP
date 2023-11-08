/*
Author: jubs
Date: 6 sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
	return (a*b)/gcd(a,b);
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		
		int n;
		cin>>n;
		int arr[n];
		FOR(i, n)cin>>arr[i];

		int minIndex = 0;
		int maxIndex=  0;
		for(int i = 0; i<n; i++){
			if(arr[i] < arr[minIndex]) minIndex = i;
			if(arr[i] > arr[maxIndex]) maxIndex = i;
		}

		if(n == 1) cout<<0<<endl;
		else {
			if(minIndex == 0 || maxIndex == n-1)
				cout<<arr[maxIndex]-  arr[minIndex]<<endl;
			else{
				int ans = 0;
				for(int i = 1; i<n; i++){
					if(arr[i] - arr[0] > ans) ans = arr[i]-arr[0];
				}

				for(int i =  0; i<n-1; i++){
					if(arr[n-1] - arr[i] > ans) ans = arr[n-1] - arr[i];
				}

				for(int i = 0; i<n-1; i++){
					if(arr[i] - arr[i+1] > ans) ans = arr[i]-arr[i+1];
				}
				cout<<ans<<endl;
			}
		}


	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

