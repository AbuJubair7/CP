/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 19 May 2023
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


bool cmp(pair<ll, ll> p1, pair<ll, ll> p2){
	return p1.second < p2.second;
}

/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	

	while(t--){
		ll n, k;
		cin>>n>>k;

		vector<pair<ll, ll>> arr;
		vector<ll> v(n);

		vector<ll> final(n);

		for(int i = 0; i<n; i++){
			ll x;
			cin>>x;

			arr.push_back({i, x});
		}

		for(int i = 0; i<n; i++) cin>>v[i];

		sort(arr.begin(), arr.end(), cmp);

		sort(v.begin(), v.end());

		for(int i = 0; i<n; i++){
			final[arr[i].first] = v[i];
		}

		for(auto i : final)
			cout<<i<<" ";
		cout<<endl;


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




