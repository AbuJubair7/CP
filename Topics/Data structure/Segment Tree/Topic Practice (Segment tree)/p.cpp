/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 25 Nov 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

struct tNode{
	int mx;
	int mn;
};

const int mxSize = 1e8+1;

int arr[mxSize];
tNode segTree[mxSize];

void build(int node, int l, int r){
	//cout<<node<<endl;
	if(l == r) {
		segTree[node].mx = arr[l];
		segTree[node].mn = arr[l];
		return;
	}

	 int mid = (l+r)/2;

	 build(node*2, l, mid);
	 build(node*2+1, mid+1, r);

	 segTree[node].mx = max(segTree[node*2].mx, segTree[node*2+1].mx);
	 segTree[node].mn = min(segTree[node*2].mn, segTree[node*2+1].mn);
}

tNode query(int node, int L, int R, int l, int r){

	if(L > r || R < l){
		tNode n;
		n.mx = INT_MIN;
		n.mn = INT_MAX;
		return n;
	}
	else if(L >= l and R <= r){
		return segTree[node];
	}

	int mid = (L+R)/2;

	tNode lNode = query(node * 2, L, mid, l, r);
	tNode rNode = query(node * 2 +1, mid+1, R, l, r);

	tNode n;
	n.mx = max(lNode.mx, rNode.mx);
	n.mn = min(lNode.mn, rNode.mn);

	return n;
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;
	int tCase = 1;

	while(t--){
		int n, d;
		cin>>n>>d;

		for(int i = 1; i<=n; i++){
			cin>>arr[i];
		}
		int ans = 0;

		build(1, 1, n);


		for(int i = 1; i<=(n-d+1); i++){
			tNode node = query(1, 1, n, i, i+d-1);

			// cout<<i<<" "<<i+d-1<<": "<<node.mx-node.mn<<endl;;
			ans = max(ans, node.mx-node.mn);

		}
		
		cout<<"Case "<<tCase++<<": "<<ans<<endl;
		


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

