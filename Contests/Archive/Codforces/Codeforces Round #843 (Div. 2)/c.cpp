/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 10 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5*2 + 5;
static 	vector<vector<int>> v(mx);

void solve(){

	int t;
	int tCase = 1;

	cin>>t;

	while(t--){
		int n, k, x;
		cin>>n;
		
		map<int, int> cnt;

		for(int i = 0; i<n ; i++){
			ll k;
			cin>>k;

			while(k--){
				cin>>x;
				v[i].pb(x);
				cnt[x]++;
			}
		}
		int ok = 1;
		for(int i = 0; i<n; i++){
			int find = 1;

			for(auto val : v[i]){
				if(cnt[val] == 1){
					find = 0;
					ok = 0;
					break;
				}
			}
			if(find){
				ok = 1;
				break;
			}
		}

		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

		for(int i = 0; i<n; i++)
			v[i].clear();

		
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