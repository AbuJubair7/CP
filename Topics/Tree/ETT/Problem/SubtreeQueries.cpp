/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 31 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
typedef long long ll;
//#define jubs
const int mx = 1e5 * 2 + 5;
static vector<vector<int>> adj(mx);
static int start[mx], finish[mx], timer;
static ll value[mx*2];
static ll arr[mx], segArr[mx];

void dfs(int s, int p){
	value[timer] = arr[s];
	start[s] = timer;
	timer++;

	for(auto i : adj[s]){
		if(i != p) dfs(i, s);
	}

	finish[s] = timer;
	timer++;
}

void build(int n){
	memset(segArr, 0, sizeof segArr);
 	int sqr = sqrt(n);

 	int segment = 0;

 	for(int i = 1; i<=n*2; i++){
 		if(i % sqr == 0) segment++;
 		segArr[segment] += value[i];
 	}

}

ll query(int l, int r, int n){
	int sqr = sqrt(n);
	ll sum =  0;
	while(l < r and l%sqr != 0){
		sum += value[l];
		l++;
	}

	while(l+sqr <= r){
		sum += segArr[l / sqr];
		l += sqr;
	}

	while(l <= r){
		sum += value[l];
		l++;
	}
	return sum;
}

void update(int n, int s, ll x){
	int sqr = sqrt(n);
	int segment = n/sqr;
	int ind = start[s];

	segArr[ind/segment] -= value[start[s]];
	segArr[ind/segment] += x;
	value[ind] = x;
}

int main(){

	int n, q;
	cin>>n>>q;

	for(int i = 1; i<=n; i++) cin>>arr[i];
	timer = 1;
	
	for(int i = 1; i<n; i++){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(1, -1);
	build(n);
	
	for(int i = 0; i<q; i++){
		int cmd, s;
		ll x;
		cin>>cmd;

		if(cmd == 1){
			cin>>s>>x;
			update(n, s, x);
		}else{
			cin>>s;
			int l, r;
			l = start[s];
			r = finish[s];
			cout<<query(l, r, n)<<endl;

		}
	}

	

	
	return 0;
}