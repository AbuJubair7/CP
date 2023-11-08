/*
Author: jubs
Algorithm:  Kruskal MST with disjoint set
*/

#include<bits/stdc++.h>
using namespace std;
#define mx 100000
#define pb push_back

static int par[mx];
static int r[mx];

struct node{
	int u, v, cost;

	node(int U, int V, int COST): u(U), v(V), cost(COST){}
};

bool cmp(node n1, node n2){
	return n1.cost < n2.cost;
}



int find(int x){

	if(par[x] == x) return x;

	par[x] = find(par[x]);

	return par[x];
}

int main(){

	int v, e;
	cin>>v>>e;

	vector<node> paths;
	memset(r, 0, sizeof(r));

	for(int i = 0; i<e; i++){
		int s, d, c;
		cin>>s>>d>>c;
		paths.pb(node(s, d, c));
		paths.pb(node(d, s, c));
		par[s] = s;
		par[d] = d;
	}

	sort(paths.begin(), paths.end(), cmp);

	int ans = 0;

	for(auto i : paths){

		int p1 = find(i.u);
		int p2 = find(i.v);

		if(p1 != p2){

			ans += i.cost;

			if(r[p1] > r[p2]){

				par[p2] = p1;

			}else if(r[p2] > r[p1]){

				par[p1] = p2;

			}else{

				par[p1] = p2;
				r[p2]++;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}