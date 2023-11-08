
/*
Author: jubair7
Date: 21 June 2023
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const ll mx = 1e6 + 123;

int level[mx+1];


int bfs(int source, int des, vector<int> edges[], int nodes){
    int currentNode = source;
    queue<int> queue;
    
    memset(level, -1, sizeof level);

    queue.push(currentNode);
    level[currentNode] = 0;

    while(!queue.empty()){
        currentNode = queue.front();
        queue.pop();
        
        for(int i = 0; i<edges[currentNode].size(); i++){
            if(level[edges[currentNode][i]] < 0){
                queue.push(edges[currentNode][i]);
                level[edges[currentNode][i]] = level[currentNode] + 1;

                if(edges[currentNode][i] == des)
                	return level[edges[currentNode][i]];
               
            }
        }

    }


    // printing levels or cost
    // cout<<"For source: "<<source<<endl;
    // for(int i = 1; i<=nodes; i++){
    //     cout<<source<<"-->"<<i<<" __cost = "<<level[i]<<endl;
    // }

    return level[des];
}

/*........................start.............................*/
void solve(){

	int n, m;
	cin>>n>>m;

	vector<int> edges[m+1];
	for(int i = 0; i<m; i++){
		int u, v;
		cin>>u>>v;

		edges[u].pb(v);

		//cout<<u<<"--->"<<v<<endl;
	}

	//bfs(1, edges, n);

	int q;
	cin>>q;

	vector<int> alice;
	vector<int> bob;

	int a = 0;
	int b = 0;

	for(int i = 0; i<q; i++){
		int x;
		cin>>x;

		if(i % 2)
			alice.pb(x);
		else bob.pb(x);
	}

	int s = 1;

	for(auto i : alice){
		if(i != s){
			a += bfs(s, i, edges, n);
			s = i;
		}
	}

	s = 1;

	for(auto i : bob){
		if(i != s){
			b += bfs(s, i, edges, n);
			s = i;
		}
	}

	cout<<max(a, b)<<endl;




	

	
	
	
}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
        //cout<<"fsf";
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}




