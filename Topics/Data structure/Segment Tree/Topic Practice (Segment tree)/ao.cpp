/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 3 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const int mx = 30000+5;
static vector<vector<int>> tree(mx*4);
static int arr[mx];

void build(int node, int l, int r){

	if(l == r){
		tree[node].pb(arr[l]);
		return;
	}
	int mid = (r+l)/2;
	build(node *2, l, mid);
	build(node*2+1, mid+1, r);

	vector<int> left = tree[node*2];
	vector<int> right = tree[node*2+1];
	int i = 0, j = 0;
	
	while(i < left.size() and j < right.size()){
		if(left[i] <= right[j]){
			tree[node].pb(left[i]);
			i++;
		}else{
			tree[node].pb(right[j]);
			j++;
		}
	}

	while(i < left.size()) tree[node].pb(left[i++]);
	while(j < right.size()) tree[node].pb(right[j++]);
}

int query(int node, int L, int R, int l, int r, int k){
	if(L > r || R < l) return 0;
	else if(L >= l and R <= r){
		vector<int>::iterator it = lower_bound(tree[node].begin(), tree[node].end(), k+1);
		int ans = tree[node].end() - it;
		
		return ans;
	}
	int mid = (L+R)/2;

	int left = query(node*2, L, mid, l, r, k);
	int right = query(node*2+1, mid+1, R, l, r, k);

	return left+right;
}



/*........................start.............................*/
void solve(){

	int n,q;
	cin>>n;

	for(int i = 1; i<=n; i++) cin>>arr[i];

	build(1, 1, n);

 	cin>>q;

 	for(int i = 0; i<q; i++){
 		int l, r, k;
 		cin>>l>>r>>k;

 		cout<<query(1, 1, n, l, r, k)<<endl;
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

