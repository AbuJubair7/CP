/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 15 June 2023
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



/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	

	while(t--){
		int n, m;
		cin>>n>>m;

		vector<vector<int>> seg(m);
		vector<ll> sum(m);

		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				int x;
				cin>>x;
				seg[j].pb(x);
				sum[j] += x;
			}
		}

		for(int i = 0; i<m; i++)
			sort(seg[i].begin(), seg[i].end());

		for(int i = 0; i<m; i++){
			ll dec = 0;

			ll prefSum = 0;
			ll total = 0;
			ll tmp = 0;
			//cout<<"......for: ........"<<i<<endl;
			for(int j = 0; j<n-1; j++){

				tmp += seg[i][j];
				dec = ((ll)seg[i][j] * (ll)(n-j-1));

				prefSum = abs((sum[i]-tmp) - dec);

				//cout<<"prefSum: "<<prefSum<<endl;
				total += prefSum;

				//cout<<"seg: "<<seg[i][j]<<"---"<<n-j-1<<endl;

			}
			//cout<<"dec "<<i<<": "<<dec<<endl;
			sum[i] = total;
		}

		ll ans = 0;
		for(int i = 0; i<m; i++)
			ans += sum[i];

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




