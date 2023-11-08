/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 21 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;
const int mod = 1e9+7;


/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	

	while(t--){
		ll n;
		cin>>n;

		ll ans = (n-1) * n;

		for(int i = 1; i<=n; i++){
			ans = ((ans%mod)*i)%mod;
		}
	
		cout<<ans<<endl;
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




