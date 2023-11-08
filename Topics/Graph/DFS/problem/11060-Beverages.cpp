/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 24 Dec 2022
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
static map<string, vector<string>> nodes;
static map<string, int> visited;
static stack<string> st;

void dfs(string s){

	if(visited[s] == 1) return;

	for(auto i : nodes[s]){
		dfs(i);
	}

	visited[s] = 1;
	st.push(s);
}

/*........................start.............................*/
void solve(){
	int n;
	int tCase = 1;
	int put = 0;
	while(cin>>n){
		string beverage[n];
		for(int i = 0; i<n; i++){
			cin>>beverage[i];
			visited[beverage[i]] = 0;
		}
	
		int m;
		cin>>m;
		
		for(int i = 0; i<m; i++){
			string a, b;
			cin>>a>>b;
			nodes[a].pb(b);
		}

		for(int i = 0; i<n; i++){

			dfs(beverage[i]);
		}

		cout<<"Case #"<<tCase++<<": Dilbert should drink beverages in this order: ";
		while(!st.empty()){
			if(put) cout<<" ";
			put = 1;
			cout<<st.top();
			st.pop();
		}
		cout<<".\n\n";
		nodes.clear();
		visited.clear();

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




