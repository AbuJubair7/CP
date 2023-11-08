/*............................
Author: jubs
Date: 2 Oct 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

 int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
 int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

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

bool isSorted(ll arr[], ll n, ll i){

	for(i; i<=n-1; i++){
		
		if(arr[i] > arr[i+1]){
			
			return false;
		}
	}
			

	return true;
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n, k;
		cin>>n>>k;

		ll arr[k+1];
		int ok = 1;

		for(ll i = 0; i<k; i++) cin>>arr[i];

		ll main[n+1];


		if(k == 1 || n == 1) cout<<"YES"<<endl;
		else if(n == k){
	
			ll prefix  = arr[0];
			main[1] = prefix;

			for(ll i = n-k+2, j = 0; i<=n; i++, j++){
				main[i] = arr[j+1] - arr[j];
				
				
			}
			if(isSorted(main, n, 1))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			ll prefix  = arr[0];

			for(ll i = n-k+2, j = 0; i<=n; i++, j++){
				main[i] = abs(abs(arr[j+1])-abs(arr[j]));
				main[i] = arr[j+1] - arr[j];
			}
			
			if(isSorted(main,n, n-k+2)){
				main[n-k+1] = main[n-k+2];

				for(ll i = n-k; i >= 2; i--){
					main[i] = main[i+1];
					prefix -= main[i+1];
				}
				prefix -= main[2];
				main[1] = prefix;

				if(isSorted(main, n, 1)) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;

			}else cout<<"NO"<<endl;
		}
		
		
	}
}

int main(){
	BOOST;
	solve();

	
	return 0;
}

