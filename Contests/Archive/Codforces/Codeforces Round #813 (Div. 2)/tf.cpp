/*
Author: jubs
Date: 15 Aug 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

typedef long long ll;

struct edge{
    int to;
    int cost;
};
int n, m;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

vector<edge> G[N];
typedef pair<int, int> P;

int d[N];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + N, INF);
    d[s] = 0;
    que.push({0, s});

    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
    }
    if (d[n] >= INF)	cout << 0;
	else	cout << d[n] - 1;
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        G[i].clear();
    }

    int x, y;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y;
        edge temp1; 
        temp1.to = y;
        temp1.cost = 1;
        G[x].push_back(temp1);
        edge temp2;
        temp2.to = x;
        temp2.cost = 1;
        G[y].push_back(temp2);
    }

    dijkstra(1);
}

int main() {
     BOOST;
     solve();

    

    return 0;
}