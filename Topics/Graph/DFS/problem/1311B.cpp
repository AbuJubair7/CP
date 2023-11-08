/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 25 Dec 2022
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
static map<int, vector<int>> edges;

bool isSorted(vector<int> v){

	for(int i = 0; i<v.size()-1; i++)
		if(v[i] > v[i+1]) return false;
	return true;
}


void dfs(int s, vector<int> &v){
	// cout<<"edge: "<<s<<endl;
	for(auto i : edges[s]){

		if(v[s-1] > v[i-1]){
			// cout<<"swapping: "<<v[s]<<"->"<<v[i]<<endl;
			swap(v[s-1], v[i-1]);
		}

		dfs(i, v);

		if(v[s-1] > v[i-1]) {
			// cout<<"swapping: "<<v[s]<<"->"<<v[i]<<endl;
			swap(v[s-1], v[i-1]);
		}
	}

}
/*........................start.............................*/
void solve(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;

		vector<int> v(n);
		vector<int> p(m);
		edges.clear();

		for(int i = 0; i<n; i++) cin>>v[i];
		for(int i = 0; i<m; i++){
			cin>>p[i];
			edges[p[i]].pb(p[i]+1);
		}

		if(isSorted(v)) cout<<"YES"<<endl;
		else{
			for(int i = 0; i<m; i++)
				dfs(p[i],v);

			if(isSorted(v)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}

		


		

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




