/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 19 Nov 2022
*/

#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
typedef long long ll;

static int par[100000+1];
static int r[100000+1];

struct node{
	int u, v; 
	int d;
	node(int U, int V, int D): u(U), v(V), d(D){}
};

bool cmp(node n1, node n2){
	return n1.d < n2.d;
}

int find(int x){

	if(par[x] == x) return x;

	par[x] = find(par[x]);

	return par[x];
}

void setPar(int n){
	for(int i = 1; i<=n; i++){
		par[i] = i;
	}
}
/*........................start.............................*/
void solve(){
	int t;
	cin>>t;
	int tCase = 1;
	
	while(t--){
		int n, m, a; ll  cost = 0;
		cin>>n>>m>>a;

		int totalAirports = n;
		int extraAirport = 0;

		memset(r, 0, sizeof(r));
		setPar(n);

		vector<node> paths;

		for(int i = 0; i<m; i++){
			int x, y, c;
			cin>>x>>y>>c;

			paths.pb(node(x, y, c));
			paths.pb(node(y, x, c));
		}

		sort(paths.begin(), paths.end(), cmp);

		for(int i = 0; i<paths.size(); i++){
			int p1 = find(paths[i].u);
			int p2 = find(paths[i].v);

			if(p1 != p2){
				
				if(paths[i].d < a){
					cost += paths[i].d;
					totalAirports--;

					if(r[p1] > r[p2]){

						par[p2] = p1;

					}else if(r[p2] > r[p1]){
						par[p1] = p2;
					}else{
						par[p1] = p2;
						r[p2]++;
					}
				}
				
					
			}
		}

		cost += (totalAirports * a);
		cout<<"Case "<<tCase++<<": "<<cost<<" "<<totalAirports<<endl;
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

