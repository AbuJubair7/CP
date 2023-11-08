
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    
    int matrix[100][100];
    int node, edge;
    cin>>node>>edge;

   for(int i = 0; i<edge; i++){
    int a, b, c;
    cin>>a>>b>>c;
    matrix[a][b] = c;
    matrix[b][a] = c;

   }

   for(int i = 0; i<node; i++){
    for(int j = 0; j<node; j++){
        cout<<matrix[i+1][j+1]<<" ";
    }
    cout<<endl;
   }
    
    return 0;
}