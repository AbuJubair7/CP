/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 2 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5 + 50000 + 5;

struct treeNode{
	ll sum;
	ll prop;
	treeNode(){}
	treeNode(ll s, ll p):sum(s), prop(p){}
};


static treeNode segTree[mx * 4];

void build(int node, int l, int r){

	if(l == r){
		segTree[node] = treeNode(0, 0);
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum;
}

ll query(int node, int L, int R, int l, int r, ll carry = 0){

	if(L > r || R < l) return 0;
	else if(L >= l and R <=r){
		return segTree[node].sum + carry * (R-L+1);
	}

	int mid = (L+R) /2;

	ll left = query(node * 2,L, mid, l, r, carry + segTree[node].prop);
	ll right = query(node * 2 +1, mid+1, R, l , r, carry + segTree[node].prop);

	return left+right;
}

void update(int node, int L, int R, int l, int r, int val){
	if(L > r  || R < l) return;
	else if(L >= l and  R <= r){
		segTree[node].prop++;

		if(segTree[node].prop % 3 == 0) segTree[node].sum = (R-L+1);
		else segTree[node].sum = 0;
		return;
	}
	int mid = (L+R)/2;

	

	update(node*2, L, mid, l, r);
	update(node*2+1, mid+1, R, l, r);
	
	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum + segTree[node].prop * (R- L +1);
}


/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;

	while(t--){
		int n, q;
		cin>>n>>q;
		build(1, 1, n);
		for(int i = 0; i<q; i++){
			int type, l, r;
			cin>>type>>l>>r;
			l++; r++;

			if(type == 0){
				update(1, 1, n, l, r);
			}else{

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

