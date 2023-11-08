/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 27 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const int mx = 1e8+123;
const ll mod = 1e9+7;

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
		// ll table[n+1][n+1];
		// memset(table, 0, sizeof table);

		ll sum = 0;
		ll tmp = 0;
		n = n % mod;
		sum = ((n-1) * (((n-1) + 1) % mod)) % mod;

		tmp = (((sum % mod) * (( 2 * (n-1) ) % mod)) % mod);
		tmp = (tmp / 6) % mod;
		tmp = (2 * tmp) % mod;

		sum = (sum/2) % mod;

		sum = (( (sum + tmp) % mod ) * (n * n)) % mod;
		sum = (2022 * sum) % mod;

		//sum = ((( (n-1) * ((n-1)+1)))/2) % mod;
		//cout<<"sum1: "<<sum<<endl;

		// tmp = ((((n-1) * ((n-1)+1) % mod) * (2*((n-1)+1) % mod ))/6) % mod;
		// tmp = (tmp * 2) % mod;
		//cout<<"tmp: "<<tmp+sum<<endl;


		//....zone
		// tmp = ((n*(n+1) % mod * (2*n+1) % mod * 2022%mod) * binpow(6, mod -2));
		// sum = ((n-1) * (n) % mod * (n+1) % mod * 2022 % mod * binpow(3, mod - 2));
		// ///
		// sum = (sum + tmp) % mod;
		cout<<sum<<endl;
		// for(int i = 1; i<=n; i++){
		// 	for(int j = 1; j<=n; j++){
		// 		cout<<table[i][j]<<" "; 
		// 	}
		// 	cout<<endl;
		// }

	}
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}

