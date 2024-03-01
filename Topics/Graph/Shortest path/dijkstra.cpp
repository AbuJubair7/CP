/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 4 Jan 2022

	6 9
	1 2 4
	1 6 2
	2 3 5
	2 6 1
	6 5 10
	6 3 8
	3 5 3
	3 4 6
	5 4 5
*/

#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5 + 5;
static vector<vector<pair<int, int>>> adj(mx);
static int dist[mx];

void dijkstra(){
	memset(dist, -1, sizeof dist);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({0, 1});
	dist[1] = 0;

	while(!pq.empty()){
		int curNode = pq.top().second;
		int curDist = pq.top().first;

		pq.pop();

		for(auto i : adj[curNode]){

			if(dist[i.first] == -1 or curDist+i.second < dist[i.first]){

				dist[i.first] = curDist + i.second;
				pq.push({dist[i.first], i.first});
			}
		}
	}
}

void solve(){

	int n, e;
	cin>>n>>e;

	for(int i = 0; i<e; i++){
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}

	dijkstra();

	for(int i = 1; i<=n; i++){
		cout<<"from 1 to "<<i<<": "<<dist[i]<<endl;
	}

}

int main(){
	BOOST;
	#ifdef jubs
        double start = clock();
    #endif

	solve();
	
	#ifdef jubs
        double tim = (clock() - start)/CLOCKS_PER_SEC;
        cout<<"Running Time : "<<tim<<" \n";
    #endif
	return 0;
}