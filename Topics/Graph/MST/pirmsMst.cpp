#include<bits/stdc++.h>
using namespace std;


struct node{
	int v, cost;
	node(int V, int COST): v(V), cost(COST){}

};

struct compare{
	bool operator()(node n1, node n2){
		return n1.cost > n2.cost;
	}
};


int primsMst(int source,int v, vector<int> listOfEdges[], vector<int> costOfEdges[]){

	int visited[v+1], sum = 0;
	memset(visited, 0, sizeof(visited));

	priority_queue<node, vector<node>, compare> queue;

	queue.push(node(source, 0));

	while(!queue.empty()){
		node n = queue.top();
		queue.pop();

		if(visited[n.v] != 1){
			sum += n.cost;
			int u = n.v;

			visited[u] = 1;

			for(int i = 0; i<listOfEdges[u].size(); i++){

				int to = listOfEdges[u][i];
				int cost = costOfEdges[u][i];
				if(visited[to] != 1){
					queue.push(node(to, cost));
				}
			}
		}
	}

	return sum;
}


int main(){

	int v,e, U, V, C;
	cin>>v>>e;
	vector<int> listOfEdges[v+1];
	vector<int> costOfEdeges[v+1];

	for(int i = 1; i<=e; i++){
		cin>>U>>V>>C;

		listOfEdges[U].push_back(V);
		listOfEdges[V].push_back(U);

		costOfEdeges[U].push_back(C);
		costOfEdeges[V].push_back(C);
	}

	int mst = primsMst(3, v, listOfEdges, costOfEdeges);
	cout<<mst<<endl;



	// node n1(1, 10);
	// node n2(2, 100);

	// priority_queue<node, vector<node>, compare> queue;
	// queue.push(n1);
	// queue.push(n2);
	// queue.push(node(3,1));

	// while(!queue.empty()){
	// 	cout<<queue.top().v<<" "<<queue.top().cost<<endl;
	// 	queue.pop();
	// }

	

	

	


	
	return 0;
}