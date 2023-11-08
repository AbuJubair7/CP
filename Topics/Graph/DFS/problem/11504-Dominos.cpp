/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 25 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;
static map<int, vector<int>> nodes;
static int visited[100000+5];
static vector<pair<int, int>> finish;
static int T = 0;


void dfs(int s){

	if(visited[s] == 1) return;
	visited[s] = 1;
	T++;

	for(auto i : nodes[s]) dfs(i);

	T++;
	pair<int, int> p;

	p.first = s;
	p.second = T;
	finish.pb(p);
	
}

void dfs2(int s){
	if(visited[s] == 1) return;
	visited[s] = 1;

	for(auto i : nodes[s])
		dfs2(i);
}

bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.second > p2.second;
}
/*........................start.............................*/
void solve(){
	int t;
	cin>>t;
	while(t--){
		nodes.clear();
		finish.clear();
		memset(visited, 0, sizeof visited);
		T = 0;

		int n, m;
		cin>>n>>m;

		for(int i = 0; i<m; i++){
			int a, b;
			cin>>a>>b;
			nodes[a].pb(b);
		}

		for(int i = 1; i<=n; i++) dfs(i);

		sort(finish.begin(), finish.end(), cmp);
		memset(visited, 0, sizeof visited);
		int push = 0;

		for(auto i : finish){
			if(visited[i.first] == 0){
				dfs2(i.first);
				push++;
			}
		}

		cout<<push<<endl;
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




