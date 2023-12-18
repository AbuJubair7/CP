#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100]; // adjacency list
int visited[100];
int grey[100];
stack<int> st;

void dfs(int p, int u) {
  if (visited[u]) {
    return;
  } else if (grey[u]) {
    cout << "Cycle at: " << u << '\n';
    return;
  }
  grey[u] = 1;
  for (auto v : adj[u]) {
    if (v != p) {
      dfs(u, v);
    }
  }
  visited[u] = 1;
  st.push(u);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, e;
  cin >> n >> e;
  memset(visited, 0, sizeof visited);
  memset(grey, 0, sizeof grey);
  for (int i = 1; i<=e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(-1, 1);
  while (!st.empty()) {
    cout << st.top() << '\n';
    st.pop();
  }
}