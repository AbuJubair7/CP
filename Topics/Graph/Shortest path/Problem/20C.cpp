/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 4 Jan 2022
*/

#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const ll inf = 9000000000000000000;
const int mx = 1e5 + 123;
static vector<vector<pair<int, int>>> adj(mx);
static ll dist[mx];
static int path[mx];

void dijkstra(int n){

	for(int i = 1; i<=n; i++) dist[i] = inf;
	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
	
	pq.push({0, 1});
	dist[1] = 0;

	path[1] = -1;

	while(!pq.empty()){
		
		int curNode = pq.top().second;
		ll curDist = pq.top().first;
		pq.pop();

		for(auto i : adj[curNode]){

			if(curDist+i.second < dist[i.first]){

				dist[i.first] = curDist + i.second;
				pq.push({dist[i.first], i.first});

				path[i.first] = curNode;
			}
		}
	}


}

void printPath(int n){
	if(n == 1) {
		cout<<1<<" ";
		return;
	}

	else printPath(path[n]);

	cout<<n<<" ";
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

	dijkstra(n);
	
	
	if(dist[n] == inf)
		cout<<"-1"<<endl;
	else
		printPath(n); 
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