/*
Author: jubair7
Date: 26 May 2022
*/

#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e9 + 7;
const int mx = 5e3 + 10;
static vector<pair<int, int>> adj[mx];
static long long dist[mx], backDist[mx];

void dijkstra(int s, int n){
  for(int i = 1; i <= n; i++) dist[i] = inf;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push({0, s});
  dist[s] = 0;
  while(!pq.empty()){
    int curDis = pq.top().first;
    int curNode = pq.top().second;
    pq.pop();
    if( curDis > dist[curNode] ) continue;
    for(auto e : adj[curNode]){
      if(e.second + curDis < dist[e.first]){
        dist[e.first] = curDis + e.second;
        pq.push({dist[e.first], e.first});
      }
    }
  }
}

void back_dijkstra(int s, int n){
  for(int i = 1; i <= n; i++) backDist[i] = inf;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push({0, s});
  backDist[s] = 0;
  while(!pq.empty()){
    int curDis = pq.top().first;
    int curNode = pq.top().second;
    pq.pop();
    if( curDis > backDist[curNode] ) continue;
    for(auto e : adj[curNode]){
      if(e.second + curDis < backDist[e.first]){
        backDist[e.first] = curDis + e.second;
        pq.push({backDist[e.first], e.first});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int tt;
  cin >> tt;
  int tCase = 1;
  while(tt--){
    for( int i = 1; i <= 5e3; i++ ) adj[i].clear();
    int n, r;
    cin>>n>>r;
    vector<pair<pair<int, int>, int>> info;  
    for(int i = 0; i<r; i++){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      info.push_back({{u, v}, w});
    }
    dijkstra(1, n);
    back_dijkstra(n, n);
    long long s = dist[n];
    long long s2 = inf;
    for(auto e : info){
      auto [u, v, w] = tie(e.first.first, e.first.second, e.second);
      long long dis = min(dist[u] + backDist[v], dist[v] + backDist[u]);
      if(dis + w > s) {
        s2 = min(s2, dis + w);
      }
      if ( dis + w == s ) {
        s2 = min ( s2, dis +  w * 3  );
      }
    }
    cout<<"Case "<<tCase++<<": "<<s2<<endl;
  }
  return 0;
}