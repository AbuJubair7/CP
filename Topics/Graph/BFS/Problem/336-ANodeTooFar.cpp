#include<bits/stdc++.h>

using namespace std;

void bfs(int n, map<int, vector<int>> edges, int source, int ttl, int tCase){
	map<int, int> level;

	for(auto i : edges){
		level[i.first] = -1;
	}
	
	int ans = 0;
	queue<int> queue;
	queue.push(source);
	level[source] = 0;

	while(!queue.empty()){
		int node = queue.front();
		queue.pop();

		for(int i = 0; i<edges[node].size(); i++){

			if(level[edges[node][i]] == -1){
				level[edges[node][i]] = level[node] + 1;
				queue.push(edges[node][i]);

			}
		}
	}


	for(auto i : level){
		if(i.second <= ttl and i.second != -1){
			ans++;
		}
	
	}
	
	cout<<"Case "<<tCase<<": "<<edges.size()-ans<<" nodes not reachable from node "<<source<<" with TTL = "<<ttl<<"."<<endl;

}

int main(){
	int n, u, v, q, ttl;
	int tCase = 1;
	cin>>n;
	while(n){

		map<int, vector<int>> edges;
		for(int i = 1; i<=n; i++){
			cin>>u>>v;

			edges[u].push_back(v);
			edges[v].push_back(u);
			
		}
		cin>>q>>ttl;
		while(q || ttl){
			bfs(n, edges, q, ttl, tCase);
			tCase++;
			cin>>q>>ttl;
		}
		cin>>n;
	}

	return 0;
}