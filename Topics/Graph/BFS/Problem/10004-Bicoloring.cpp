#include<bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<int> edges[]){
	int red = 0;
	int blue = 0;
	char visited[n+1];
	memset(visited, 'N', sizeof(visited));
	queue<int> queue;

	queue.push(0);
	visited[0] = 'R';

	while(!queue.empty()){

		int node = queue.front();
		queue.pop();

		for(int i = 0; i<edges[node].size(); i++){

			if(visited[node] == visited[edges[node][i]])
				return false;
			if(visited[edges[node][i]] == 'N'){
				visited[edges[node][i]] = visited[node] == 'R' ? 'B' : 'R';
				queue.push(edges[node][i]);
				
			
			}
		}
	}
	
	return true;
}


int main(){
	
	int n, e;
	cin>>n;

	while(n){
		cin>>e;


		vector<int> edges[n+1];

		for(int i = 1; i<=e; ++i){
			int u, v;
			cin>>u>>v;

			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		
		if(!bfs(n, edges)){
			cout<<"NOT BICOLORABLE."<<endl;
		}else cout<<"BICOLORABLE."<<endl;

		cin>>n;
	}


	return 0;

}

