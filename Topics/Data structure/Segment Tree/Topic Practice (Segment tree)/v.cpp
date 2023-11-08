/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 29 Nov 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

static int ans = 0;
const int mx = 1e5 * 2+5;

struct treeNode{
	int c = 0;
};

static treeNode* segTree;
static set<int> s;


void update(int node, int L, int R, int l, int r, int col){

	if(L > r || R < l) return;
	else if(L >= l  and R <= r){
		// if(segTree[node] == 0){
		// 	cout<<"seting: "<<L<<"--"<<R<<": "<<col<<endl;
		// }else cout<<"Already set: "<<L<<"--"<<R<<endl;
		segTree[node].c = col;

		return;
	}

	int mid = (L+R)/2;
	if(segTree[node].c != 0){
		segTree[node*2].c = segTree[node].c;
		segTree[node*2+1].c = segTree[node].c;
		segTree[node].c = 0;
	}

	update(node * 2, L, mid, l, r, col);
	update(node * 2+1, mid+1, R, l, r, col);

}

void query(int node, int L, int R, int l, int r){

	if(L > r || R < l) return;
	
	if(L >= l and R <= r || segTree[node].c != 0){
		
		if(segTree[node].c != 0)
			s.insert(segTree[node].c);
		return;
	}

	int mid = (L+R)/2;

	query(node * 2, L, mid, l, r);
	query(node * 2 + 1, mid+1, R, l , r);
}

/*........................start.............................*/
void solve(){
	int t;
	cin>>t;
	int tCase = 1;

	while(t--){
		//ans = 0;
		segTree = new treeNode[mx * 4];
		s.clear();
		cout<<"Case "<<tCase++<<": ";
		int n;
		cin>>n;
		vector<pair<int, int>> v;
		int mxR = 0;

		for(int i = 0; i<n; i++){
			int a, b;
			cin>>a>>b;
			v.pb({a, b});
			mxR = max(mxR, b);			
		}
		int col = 1;
		for(auto i : v){
			update(1, 1, mxR, i.first, i.second, col++);
		}
		for(int i = 1; i<=2*n; i++){
			query(1, 1, mxR, i, i);
		}

		cout<<s.size()<<endl;


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

