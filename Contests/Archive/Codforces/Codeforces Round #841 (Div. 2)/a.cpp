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

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<ll> v(n);

		FOR(i, n) cin>>v[i];

		sort(v.begin(), v.end(), greater<>());

		for(int i = 1; i<n; i++){
			v[0] *= v[i];
		}

		cout<<(v[0]+(n-1))*2022<<endl;

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

