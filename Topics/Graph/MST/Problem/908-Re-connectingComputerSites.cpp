#include<bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long ll;


int visited[1000+1];

struct node{
	int v, c;
	node(int V,int  C): v(V), c(C){}
};

//.....overloading for priority_queue........
bool operator < (node n1, node n2){
	return n1.c > n2.c;
}

int mst(vector<int> edges[], vector<int> cost[]){
	int ans = 0;
	memset(visited, 0, sizeof(visited));
	priority_queue<node> q;
	q.push({1,0});

	while(!q.empty()){
		node n = q.top();
		q.pop();
		if(visited[n.v] == 0){
			ans += n.c;
			visited[n.v] = 1;

			for(int i = 0; i<edges[n.v].size(); i++){
				int v = edges[n.v][i];
				int c = cost[n.v][i];
				if(visited[v] == 0){
					q.push({v, c});
				}
			}
		}
	}

	return ans;
}

int main(){

	int n, k, m, u, v, c;
	int put = 0;

	while(cin>>n){
		vector<int> edges[1000+1];
		vector<int> cost[1000+1];
		vector<pair<int, int>> kLines;
		vector<int> kCost;

		int prevCost = 0;
		int newCost = 0;

		for(int i = 1; i<n; i++){
			
			cin>>u>>v>>c;
			prevCost += c;
		}


		cin>>k;
		for(int i = 1; i<=k; i++){
			cin>>u>>v>>c;
			kLines.pb({u,v});
			kCost.pb(c);
		}

		cin>>m;

		for(int i = 1; i<=m; i++){
			cin>>u>>v>>c;
			
			edges[u].pb(v);
			edges[v].pb(u);

			cost[u].pb(c);
			cost[v].pb(c);
		}

		prevCost = mst(edges, cost);

		for(int i = 0; i<kLines.size(); i++){
			edges[kLines[i].first].pb(kLines[i].second);
			edges[kLines[i].second].pb(kLines[i].first);

			cost[kLines[i].first].pb(kCost[i]);
			cost[kLines[i].second].pb(kCost[i]);
		}

		newCost = mst(edges, cost);

		if(!put) put = 1;
		else cout<<endl;

		cout<<prevCost<<"\n"<<newCost<<endl;
	}

	return 0;
}