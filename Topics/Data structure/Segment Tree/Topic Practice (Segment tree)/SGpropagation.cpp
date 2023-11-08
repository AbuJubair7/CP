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

struct treeNode{
	int sum;
	int prop;
	treeNode(){}
	treeNode(int s, int p):sum(s), prop(p){}
};


static int arr[mx];
static treeNode segTree[mx * 4];

void build(int node, int l, int r){

	if(l == r){
		segTree[node] = treeNode(arr[l], 0);
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum;
}

ll query(int node, int L, int R, int l, int r, int carry = 0){

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
		segTree[node].sum = segTree[node].sum + val * (R - L + 1);
		segTree[node].prop += val;
		return;
	}
	int mid = (L+R)/2;

	update(node*2, L, mid, l, r, val);
	update(node*2+1, mid+1, R, l, r, val);
	
	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum + segTree[node].prop * (R- L +1);
	// also can be written in below format
	//segTree[node].sum += (segTree[node*2].sum + segTree[node*2+1].sum);
}


/*........................start.............................*/
void solve(){


	int n, q;
	cin>>n>>q;

	for(int i = 1; i<=n; i++) cin>>arr[i];

	build(1, 1, n);

	cout<<"Total: "<<query(1, 1, n, 1, n, 0)<<endl;
	for(int i = 0; i<q; i++){
		int cmd, a, b;
		cin>>cmd>>a>>b;
		
		if(cmd == 1){
			cout<<"update "<<endl;
			update(1, 1, n, a, b, 1); // adding a to b with 1
		}else{
			cout<<query(1, 1, n, a, b, 0)<<endl;
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

