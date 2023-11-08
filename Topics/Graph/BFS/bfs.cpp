
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf INT_MAX

void bfs(int source, vector<int> edges[], int nodes){
    int currentNode = source;
    queue<int> queue;
    int level[nodes+1];
    memset(level, -1, sizeof level);

    //int visited[nodes+1];
   // memset(visited, 0 ,sizeof(visited));


    queue.push(currentNode);
    level[currentNode] = 0;

    while(!queue.empty()){
        currentNode = queue.front();
        queue.pop();
        
        for(int i = 0; i<edges[currentNode].size(); i++){
            if(level[edges[currentNode][i]] < 0){
                queue.push(edges[currentNode][i]);
                level[edges[currentNode][i]] = level[currentNode] + 1;
               // visited[edges[currentNode][i]] = 1;
               
            }
        }

    }

    // printing levels or cost
    cout<<"For source: "<<source<<endl;
    for(int i = 1; i<=nodes; i++){
        cout<<source<<"-->"<<i<<" __cost = "<<level[i]<<endl;
    }
}

int main(){

/* sample input: 
    5 6
    1 2 4
    3 1 1
    1 4 5
    4 5 2
    4 3 1
    5 2 1
*/
    int node, edge;
    cin>>node>>edge;
    vector<int> edges[node+1];
    vector<int> cost[node+1];

   for(int i = 0; i<edge; i++){
    int a, b, c;
    cin>>a>>b>>c;
    edges[a].push_back(b);
    edges[b].push_back(a);
    cost[a].push_back(c);
    cost[b].push_back(c);
   
   }

   bfs(2, edges, node);

   //printing all edges
   // for(int i = 1; i<=node; i++){
   //  cout<<"From: "<<i<<": "<<endl;
   //  for(int j = 0; j<edges[i].size(); j++){
   //      cout<<i<<"-->"<<edges[i][j]<<" ";
   //  }
   //  cout<<endl;
   // }

  
    
    return 0;
}