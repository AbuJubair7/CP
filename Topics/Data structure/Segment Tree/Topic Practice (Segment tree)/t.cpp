/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 1 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5 + 5;

struct treeNode{
	ll sum;
	ll prop;
	treeNode(){}
	treeNode(ll s, ll p):sum(s), prop(p){}
};


static int* arr;
static treeNode* segTree;

void build(int node, int l, int r){

	if(l == r){
		segTree[node] = treeNode(0, -1);
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum;
}

ll query(int node, int L, int R, int l, int r){

	if(L > r || R < l) return 0;
	else if(L >= l and R <=r){
		return segTree[node].sum;
	}
	int mid = (L+R) /2;

	if(segTree[node].prop != -1){
		//cout<<"Find: "<<segTree[node].prop<<endl;
		segTree[node * 2].prop = segTree[node].prop;
		segTree[node * 2].sum = segTree[node].prop * (mid-L+1);
		segTree[node * 2+1].prop = segTree[node].prop;
		segTree[node * 2 +1].sum = segTree[node].prop * (R-mid);
		
 	}

	ll left = query(node * 2, L, mid, l, r);
	ll right = query(node * 2 +1, mid+1, R, l, r);

	return left+right;
}

void update(int node, int L, int R, int l, int r, int val){
	if(L > r  || R < l) return;
	else if(L >= l and  R <= r){
		segTree[node].sum = val * (R - L + 1);
		segTree[node].prop = val;
		return;
	}
	int mid = (L+R)/2;

	if(segTree[node].prop != -1){
		segTree[node * 2].prop = segTree[node].prop;
		segTree[node * 2].sum = segTree[node].prop * (mid-L+1);

		segTree[node * 2+1].prop = segTree[node].prop;
		segTree[node * 2 +1].sum = segTree[node].prop * (R-mid);
		segTree[node].prop = -1;
 	}

	update(node*2, L, mid, l, r, val);
	update(node*2+1, mid+1, R, l, r, val);
	
	segTree[node].sum = segTree[node*2].sum + segTree[node*2+1].sum;
}


/*........................start.............................*/
void solve(){


	int t;
	cin>>t;
	int tCase = 1;

	while(t--){
		cout<<"Case "<<tCase++<<":\n";
		int n, q;
		cin>>n>>q;

		segTree = new treeNode[mx*4];

		for(int i = 0; i<q; i++){
			int type, l, r, v;
			cin>>type;

			if(type == 1){
				cin>>l>>r>>v;
				 l++;
				 r++;
				update(1, 1, n, l, r, v);
			}else{
				cin>>l>>r;
				l++; r++;
				ll sum = query(1, 1, n, l, r);

				if(sum % (r-l+1) != 0) {
					int gcd = __gcd(sum, (ll)(r-l+1));
					cout<<sum/gcd<<"/"<<(r-l+1)/gcd<<endl;
				}
				else cout<<sum/(r-l+1)<<endl;
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

