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
const int mx = 1e5  + 5;
static vector<vector<int>> adj(mx);
static int FT[mx*2];
static int S[mx], F[mx], timer;


void dfs(int s, int p){

	S[s] = timer;
	FT[timer] = s;
	timer++;

	for(auto i : adj[s]){
		if(i != p){
			dfs(i, s);
		}
			
	}

	F[s] = timer;
	FT[timer] = s;
	timer++;

	
}
/*........................start.............................*/
void solve(){
	
	int n;
	cin>>n;

	for(int i = 1; i<n; i++){
		int u, v;
		cin>>u>>v;
		
		adj[u].pb(v); adj[v].pb(u);
	}

	timer = 1;
	dfs(1, -1);
	
	cout<<"S{ ";
	for(int i = 1; i<=n; i++){
		cout<<S[i]<<", ";
	}
	cout<<"}"<<endl;

	cout<<"F{ ";
	for(int i = 1; i<=n; i++){
		cout<<F[i]<<", ";
	}
	cout<<"}"<<endl;

	cout<<"FT{ ";
	for(int i = 1; i<=n*2; i++){
		cout<<FT[i]<<", ";
	}
	cout<<"}"<<endl;

	for(int i = 1; i<=n; i++){
		cout<<"Subtree Node of "<<i<<": ";
		cout<<(F[i]-S[i] - 1)/2<<endl;
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




