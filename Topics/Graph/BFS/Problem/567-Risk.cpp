#include<bits/stdc++.h>

using namespace std;

int bfs(int source, int destination, vector<int> listOfEdges[]){
	int dis[50];
	
	memset(dis, -1, sizeof(dis));

	queue<int> queue;
	queue.push(source);

	dis[source] = 0;

	while(!queue.empty()){
		int u = queue.front();
		queue.pop();

		for(int i = 0; i<listOfEdges[u].size(); i++){
			int v = listOfEdges[u][i];

			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				if(v == destination)
					return dis[v];
				queue.push(v);
			}
		}
	}


	return 0;
}

int main(){

	int n;
	int adjacent;
	int test = 1;
	int putFirst = 0;


	while(cin>>n){

		
	
		vector<int> listOfEdges[50];

		for(int i = 1; i<=n ;i++){
			 
			cin>>adjacent;
			listOfEdges[1].push_back(adjacent);
			listOfEdges[adjacent].push_back(1);
		}
		for(int i = 2; i<=19; i++){
			cin>>n;
			for(int j = 1; j<=n; j++){
				
				cin>>adjacent;
				listOfEdges[i].push_back(adjacent);
				listOfEdges[adjacent].push_back(i);
			}
			

		}

		int q;
		cin>>q;
		cout<<"Test Set #"<<test++<<endl;
		while(q--){
			int u, v;
			cin>>u>>v;
			u < 10? cout<<" "<<u<<" to" : cout<<u<<" to";

			v < 10 ? cout<<"  "<<v<<": "<<bfs(u,v,listOfEdges)<<endl 
			: 
			cout<<" "<<v<<": "<<bfs(u,v,listOfEdges)<<endl;
		// printf("%2d to %2d: %d\n",u,v,bfs(u,v,listOfEdges));
		
		}
		cout<<endl;
	}

	return 0;
}