#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<math.h>
#include<climits>
using namespace std;

struct node{
	string city; int weight;

	node(string c, int w): city(c), weight(w){}
};

struct compare{
	bool operator ()(node c1, node c2){
		return c1.weight < c2.weight;
	}
};

int mst(string source, string destination, map<string, vector<string>> listOfEdges, map<string, vector<int>> costOfEdges){
	map<string, bool> visited;
	for(auto i : listOfEdges)
		visited[i.first] = false;

	priority_queue<node, vector<node>, compare> queue;
	queue.push(node(source, 0));

	int ans = INT_MAX;



	while(!queue.empty()){

		node u= queue.top();
		queue.pop();
		
		if(!visited[u.city]){
			visited[u.city] = true;

			if(u.city != source) ans = min(ans, u.weight);

			if(u.city == destination) return ans;

			for(int i = 0; i<listOfEdges[u.city].size(); i++){
				string v = listOfEdges[u.city][i];
				int c = costOfEdges[u.city][i];

				if(!visited[v]) queue.push(node(v,c));
			}
		}
	}

	return ans;
}

int main(){

	int n, r, c, tCases = 1;;
	string u, v;

	cin>>n>>r;

	while(n || r){

		map<string, vector<string>> listOfEdges;
		map<string, vector<int>> costOfEdges;

		for(int i = 1; i<=r; i++){
			
			cin>>u>>v>>c;

			listOfEdges[u].push_back(v);
			listOfEdges[v].push_back(u);

			costOfEdges[u].push_back(c);
			costOfEdges[v].push_back(c);
		}

		cin>>u>>v;

		cout<<"Scenario #"<<(tCases++)<<endl;
		cout<<mst(u, v ,listOfEdges, costOfEdges)<<" tons\n"<<endl;

		cin>>n>>r;
	}


}