/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 30 Nov 2022
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

static ll arr[mx];
static ll segTree[mx * 4];

void build(int node, int l, int r){

	if(l == r){
		segTree[node] = arr[l];
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll query(int node, int L, int R, int l, int r){

	if(L > r || R < l) return 0;
	else if(L >= l and R <=r){
		return segTree[node];
	}

	int mid = (L+R) /2;

	ll left = query(node * 2,L, mid, l, r);
	ll right = query(node * 2 +1, mid+1, R, l , r);

	return left+right;
}

void update(int node, int l, int r, int key, ll val){
	if(key > r  || key < l) return;
	else if(l >= key and r <= key){
		segTree[node] = val;
		return;
	}
	int mid = (l+r)/2;
	if(key <= mid){
		update(node*2, l, mid, key, val);
	}else{
		update(node*2+1, mid+1, r, key, val);
	}
	
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}


/*........................start.............................*/
void solve(){

	int n, q, newN;
	cin>>n;
	newN = n;
	vector<ll> v(n+1);

	for(int i = 1; i<=n; i++) cin>>v[i];
	int j = 1;
	for(int i = n; i>=1; i--) arr[j++] = v[i];	

	build(1, 1, mx);
	cin>>q;

	for(int i =0; i<q; i++){
		int type;

		cin>>type;

		if(type == 1){
			int l, r;
			cin>>r>>l;
			l = n-l+1;
			r = n-r+1;
			cout<<query(1, 1, mx, l, r)<<endl;
		}else{
			ll val;
			cin>>val;
			n++;
			update(1, 1, mx, n, val);
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

