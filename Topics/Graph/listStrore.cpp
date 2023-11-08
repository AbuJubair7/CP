
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    
    int node, edge;
    cin>>node>>edge;
    vector<int> edges[node+1];
    vector<int> cost[node+1];
    vector<int> inDegree(node+1,0);
    vector<int> outDegree(node+1,0);

   for(int i = 0; i<edge; i++){
    int a, b, c;
    cin>>a>>b>>c;
    edges[a].push_back(b);
    cost[a].push_back(c);
    outDegree[a]++;
    inDegree[b]++;
    
   }


   // printing all edges
   for(int i = 1; i<=node; i++){
    cout<<"From: "<<i<<": "<<endl;
    for(int j = 0; j<edges[i].size(); j++){
        cout<<i<<"-->"<<edges[i][j]<<" ";
        cout<<" cost: "<<cost[i][j]<<endl;
    }
    cout<<endl;
   }

   for(int i = 1; i<outDegree.size(); i++){
    cout<<"outDegree for: "<<i<<" = "<<outDegree[i]<<endl;
   }
   cout<<endl;
   for(int i = 1; i<inDegree.size(); i++){
    cout<<"inDegree for: "<<i<<" = "<<inDegree[i]<<endl;
   }
   
    
    return 0;
}