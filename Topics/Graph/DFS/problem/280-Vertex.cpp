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

static vector<int> *nodes;
static int visited[10000];
static stack<int> st;
static map<int, int> access;

void dfs(int s){
	
	if(visited[s] == 2) return;
	else if(visited[s] == 1){
		st.push(s);
		return;
	}
	visited[s] = 1;
	for(auto i : nodes[s]){
		if(i == s) st.push(i);
		else dfs(i);
	}
	visited[s] = 2;
	st.push(s);
}

/*........................start.............................*/
void solve(){
	int n;
	int put = 0;

	while(cin>>n and n != 0){
		
		nodes = new vector<int>[1000];
		int i;
		int totalEdge = 0;
		while(cin>> i and i != 0){

			int k;
		
			while(cin>>k and k != 0){
				nodes[i].pb(k);
				totalEdge++;
			}
		}

		cin>>i;
		while(i--){
			memset(visited , 0 , sizeof(visited));
			vector<int> inAcces;
			access.clear();

			int inv;
			cin>>inv;
			dfs(inv);
			int fir = 0;

			while(!st.empty()){
				if(fir)access[st.top()] = 1;

				fir = 1;
				st.pop();
			}
			int put = 0;
			for(int p = 1; p<=n; p++){
				
				if(access[p] == 0) inAcces.pb(p);
			}
			
			if(totalEdge == 0){
				cout<<n;
				for(int q = 1; q<=n; q++){
					cout<<" "<<q;
				}
			}

			else{
				cout<<inAcces.size();
				for(auto inA : inAcces){
					if(inAcces.size() > 0) cout<<" ";
					cout<<inA;
				}
				
			}

			cout<<endl;
			put = 0;
		}
		
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




