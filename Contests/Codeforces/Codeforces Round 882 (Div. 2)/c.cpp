/*
Author: jubair7
Date: 18 Jul 2023
*/
#include <bits/stdc++.h>
 
using namespace std;

const int mx = 1e5 * 2 + 123;
int leaf[mx];

void dfs(int s, int p, vector<int> adj[]){
	leaf[s] = 0;
	if(adj[s].size() == 1 and s != 1){
		leaf[s] = 1;
		return;
	}
	for(auto v : adj[s]){
		if(v != p){
			dfs(v, s, adj);
			leaf[s] += leaf[v];
		}
	}
}

void solve(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin >> n;
		vector<int> adj[n+1];
		for(int i = 1; i<=n-1; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int q;
		cin >> q;
		dfs(1, -1, adj);
		while(q--){
			int x, y;
			cin >> x >> y;
			cout << (long long)leaf[x] * leaf[y] << '\n';
		}
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();	
  return 0;
}