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

const int mx = 1e5 * 2 + 5;
static ll segTree[mx * 4];
static ll arr[mx];

void build(int node, int l, int r){

	if(l == r){
		segTree[node] = 1;
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

ll query(int node, int L, int R, int l, int r){

	if(L > r || R < l) return 0;
	else if(L >= l and R <=r) return segTree[node];

	int mid = (L+R) /2;

	ll left = query(node * 2,L, mid, l, r);
	ll right = query(node * 2 +1, mid+1, R, l , r);

	return left+right;
}

void update(int node, int l, int r, int key){
	if(key < l || key > r) return;
	else if(l == r){
		segTree[node] = 0;

		return;
	}
	int mid = (l+r)/2;
	if(key <= mid){
		update(node*2, l, mid, key);
	}else{
		update(node*2+1, mid+1, r, key);
	}

	segTree[node] = segTree[node*2] + segTree[node*2+1];
}


/*........................start.............................*/
void solve(){

	build(1, 1, mx);
	int n;
	cin>>n;

	
	for(int i = 1; i<=n; i++) cin>>arr[i];
	for(int i = 1; i<=n; i++){
		int sum, ind;
		int k;
		cin>>k;
		int left = 1;
		int right = n;

		while(left <= right){
			int mid = (right + left)/2;

			sum = query(1, 1, mx, 1, mid);
			if(sum == k){
				right = mid-1;
				

			}else if(sum < k) left = mid+1;
			else right = mid-1;
			
		}
		ind = left;
		//cout<<"Called: "<<k<<": "<<ind<<endl;
	
		cout<<arr[ind]<<" ";
		update(1, 1, mx, ind);
		

			
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

