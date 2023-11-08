/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 20 Nov 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const int mx = 1e5 * 2 + 1;
static ll segTree[mx * 4];

static ll arr[mx];

void build(int node, int l, int r){

	if(l == r){
		segTree[node] = arr[l];
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node] = max(segTree[node*2], segTree[node*2+1]);
}

ll query(int node, int L, int R, ll need){

	if(segTree[node] < need) return 0;
	if(L == R){
		if(segTree[node] >= need) return L;
		return 0;
	}

	int mid = (L+R) /2;

	ll left = query(node * 2,L, mid, need);

	if(left != 0) return left;

	ll right = query(node * 2 +1, mid+1, R, need);

	return right;
}

void update(int node, int l, int r, int key, ll val){
	if(key < l || key > r) return;
	else if(l == r){
		segTree[node] -= val;
		return;
	}
	int mid = (l+r)/2;
	if(key <= mid){
		update(node*2, l, mid, key, val);
	}else{
		update(node*2+1, mid+1, r, key, val);
	}

	segTree[node] = max(segTree[node*2], segTree[node*2+1]);
}


/*........................start.............................*/
void solve(){

	ll n, m;
	cin>>n>>m;

	ll g[m+1];
	for(int i = 1; i<=n; i++) cin>>arr[i];

	build(1, 1, n);
	
	for(int i = 1; i<=m; i++) cin>>g[i];

	for(int i = 1; i<=m; i++){
		ll ind = query(1, 1, n, g[i]);
		if(ind != 0){
			cout<<ind<<" ";
			update(1, 1, n, ind, g[i]);
		}else cout<<0<<" ";
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

