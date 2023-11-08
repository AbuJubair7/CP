/*
Author: jubs
Date: 23 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

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
		ll n, a, b, c;
		cin>>n;
		vector<ll> arr(n);
		FOR(i, n) cin>>arr[i];

		sort(arr.begin(), arr.end());

		int ans = INT_MAX;

		for(int i = 0; i<n-2; i++){
			//cout<<arr[i]<<" "<<arr[i+1]<<" "<<arr[i+2]<<endl;

			int sum = abs(arr[i]-arr[i+1]);
			sum += abs(arr[i+1]-arr[i+2]);
			ans = min(sum, ans);
			
		}

		cout<<ans<<endl;
		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

