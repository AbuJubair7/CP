/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 3 Jan 2022
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
const int mxLog = log2(mx) + 1;
static vector<vector<int>> adj(mx);
static int dp[mx][mxLog];
static int level[mx], start[mx], finish[mx], n;
static int ft[mx*2], timer;
static ll value[mx * 2], segArr[mx] ,arr[mx];

void dfs(int s, int p){
	dp[s][0] = p;
	start[s] = timer;
	ft[timer] = s;
	value[timer] = arr[s];
	timer++;

	if(p != -1) level[s] = level[p] + 1;
	else level[s] = 0;

	for(auto i : adj[s]){
		if(i != p)
			dfs(i, s);
	}

	finish[s] = timer;
	ft[timer] = s;
	value[timer] = arr[s] * (-1);
	timer++;
}

void build(){
	memset(dp, -1, sizeof(dp));
	memset(segArr, 0, sizeof segArr);
	memset(value, 0, sizeof value);
	dfs(1, -1);

	int segment = 0;
	int sqr = sqrt(n * 2);

	for(int i = 1; i<=n*2; i++){

		if(i % sqr == 0) segment++;
		segArr[segment] += value[i];
	}


	int lgN = log2(n);

	for(int j = 1; j<=lgN; j++){

		for(int i = 1; i<=n; i++){
			if(dp[i][j-1] != -1)
				dp[i][j] = dp [dp[i][j-1]][j-1];
		}
	}
}

int lca(int a, int b){

	if(level[a] < level[b]) swap(a, b);
	int d = level[a] - level[b];

	while(d > 0){
		int lg = log2(d);

		a = dp[a][lg];
		d -= (1 << lg);
	}
	if(a == b) return a;

	for(int i = log2(n) + 1; i>=0; i--){

		if(dp[a][i] != -1 and (dp[a][i] != dp[b][i])){
			a = dp[a][i];
			b = dp[b][i];
		}
	}

	return dp[a][0];

}

ll query(int l, int r){
	int segment = sqrt(n*2);
	ll sum = 0;


	while(l < r and l % segment != 0){
		sum += value[l];
		l++;
	}
	

	while(l+segment <= r){
		sum += segArr[l/segment];
		l += segment;
	}


	while(l<=r){
		sum += value[l];
		l++;
	}

	return sum;
}



void update(int i, ll val){
	int sqr = sqrt(n*2);
	int ind = start[i];
	int ind2 = finish[i];

	int segment = ind/sqr;

	segArr[segment] -= value[ind];
	segArr[segment] += val;

	segment= ind2/sqr;

	segArr[segment] -= value[ind2];
	segArr[segment] += (-val);



	value[ind] = val;
	value[ind2] = val * (-1);
	arr[i] = val;
}

void solve(){

	int q;
	cin>>n>>q;

	for(int i = 1; i<=n; i++) cin>>arr[i];
	for(int i = 1; i<n; i++){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	timer = 1;
	build();

	for(int i = 0; i<q; i++){
		int cmd, s;
		ll x;
		cin>>cmd;

		if(cmd == 1){
			cin>>s>>x;
			update(s, x);
		
			
		}else{
			cin>>s;
			int l, r;
			l = start[1];
			r = start[s];
			cout<<query(l, r)<<endl;

		}
	}

}

int main(){
	BOOST;

	solve();
	

	return 0;
}