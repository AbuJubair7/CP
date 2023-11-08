/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 24 Nov 2022
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

struct treeNode{
	ll sum = 0;
	ll prop = 0;
	treeNode(){}
	treeNode(ll s, ll p):sum(s), prop(p){}
};

static treeNode*  segTree;

ll query(int node, int L, int R, int l, int r, ll carry = 0){

	if(L > r || R < l) return 0;
	else if(L>=l and R<=r){
		return segTree[node].sum + carry * (R-L+1);
	}

	int mid = (L+R) /2;
	ll left = query(node * 2,L, mid, l, r, carry + segTree[node].prop);
	ll right = query(node * 2 +1, mid+1, R, l , r, carry + segTree[node].prop);
	
	return left+right;
}

void update(int node, int L, int R, int l, int r, ll val){
	if(L > r  || R < l) return;
	else if(L >= l and  R <= r){
		segTree[node].sum = segTree[node].sum + val * (R - L + 1);
		segTree[node].prop += val;
		return;
	}
	int mid = (L+R)/2;

	update(node*2, L, mid, l, r, val);
	update(node*2+1, mid+1, R, l, r, val);
	
	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum + segTree[node].prop * (R- L +1);
}

/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	

	while(t--){
		
		cout<<"Case "<<tCase++<<":"<<endl;
		int n,q;
		cin>>n>>q;

		segTree = new treeNode[mx * 4];

	//	for(int i = 1; i<=n*3; i++) cout<<segTree[i].prop<<endl;
		
		for(int i = 0; i<q; i++){
			int cmd, x, y ,v;
			cin>>cmd>>x>>y;
			if(!cmd){
				cin>>v;
				update(1, 1, n, x+1, y+1, v);	
			}else{
				cout<<query(1, 1, n, x+1, y+1, 0)<<endl;
			}
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

