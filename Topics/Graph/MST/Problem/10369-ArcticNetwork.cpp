/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 17 Nov 2022
*/

#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
typedef long long ll;

static int par[5001];
static int r[5001];

struct node{
	int u, v; 
	double d;
	node(int U, int V, double D): u(U), v(V), d(D){}
};

bool cmp(node n1, node n2){
	return n1.d < n2.d;
}

double distance(int x1, int y1, int x2, int y2){
	double a = x2-x1;
	double b = y2 - y1;
	return (sqrt((a*a) + (b*b)));
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
	int putFirst = 0;

	
	while(t--){
		int s, p;
		cin>>s>>p;
		vector<pair<double, double>> v;
		vector<node> paths;
		vector<double> costs;

		for(int i = 0; i<p; i++){
			double x, y;
			cin>>x>>y;
			v.pb({x, y});
		}

		for(int i = 0; i<v.size(); i++){

			for(int j = i+1; j<v.size(); j++){
				double dis = distance(v[i].first, v[i].second, v[j].first, v[j].second);
				paths.pb(node(i+1, j+1, dis));
				paths.pb(node(j+1, i+1, dis));
			}
		}

		setPar(p);
		memset(r, 0, sizeof(r));

		sort(paths.begin(), paths.end(), cmp);

		double ans = 0;

		int cc = p;

		for(int i =  0; i<paths.size(); i++){
			int p1 = find(paths[i].u);
			int p2 = find(paths[i].v);

			if(p1 != p2){

				if(r[p1] > r[p2]){
					par[p2] = p1;

				}else if(r[p2] > r[p1]){
					par[p1] = p2;
				
				}else{
					par[p1] = p2;
					r[p2]++;

				}

				costs.pb(paths[i].d);
			}
		}

		
		 ans = costs[costs.size()-1-(s-1)];

		 cout<<fixed<<setprecision(2)<<ans<<endl;
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

