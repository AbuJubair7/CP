/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 5 Jan 2022
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
const int mx = 5e3;
static vector<pair<int, int>> adj[mx];
static ll dist[3][mx];

struct info{
	int u, v, w;
};

void dijkstra(int s, int n, int cmd){
	for(int i = 1; i<=n; i++) dist[cmd][i] = inf;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({0, s});
	dist[cmd][s] = 0;

	while(!pq.empty()){
		int curDis = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if( curDis > dist[cmd][curNode] ) continue;

		for(auto e : adj[curNode]){

			if(e.second + curDis < dist[cmd][e.first]){

				dist[cmd][e.first] = curDis + e.second;
				pq.push({dist[cmd][e.first], e.first});
			}
		}
	}

}


void solve(){
	int t;
	cin>>t;
	int tCase = 1;

	while(t--){
		for( int i = 1; i <= 5e3; i++ ) adj[i].clear();

		int n, r;
		cin>>n>>r;
		vector<info> vc;	

		for(int i = 0; i<r; i++){
			int u, v, w;
			cin>>u>>v>>w;
			adj[u].pb({v, w});
			adj[v].pb({u, w});
			
			vc.pb({ u, v, w });

		}

		dijkstra(1, n, 0);
		dijkstra(n, n, 1);


		ll s = dist[0][n];
		ll s2 = inf;

		for(auto e : vc){
			ll dis = min(dist[0][e.u]+dist[1][e.v], dist[0][e.v]+dist[1][e.u]);

			if(dis+e.w > s) s2 = min(s2, dis+e.w);
			
			if ( dis + e.w == s )
				s2 = min ( s2, dis + ( e.w * 3 ) );
			
			
		}
		cout<<"Case "<<tCase++<<": "<<s2<<endl;


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