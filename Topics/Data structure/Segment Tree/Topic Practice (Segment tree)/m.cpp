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
	int change;
	treeNode(){}
};


static char arr[mx];
static treeNode segTree[mx * 4];

void build(int node, int l, int r){

	if(l == r){
		treeNode n;
		n.change = 0;
		segTree[node] = n;
		return;
	}

	int mid = (l+r)/2;

	build(node * 2, l, mid);
	build(node * 2 +1, mid+1, r);

	segTree[node].change = 0;
}

ll query(int node, int L, int R, int l, int r, int carry = 0){

	if(L > r || R < l) return 0;
	else if(L >= l and R <=r){
		return segTree[node].change+carry;
	}

	int mid = (L+R) /2;

	ll left = query(node * 2,L, mid, l, r, carry + segTree[node].change);
	ll right = query(node * 2 +1, mid+1, R, l , r, carry + segTree[node].change);

	return left+right;
}

void update(int node, int L, int R, int l, int r){
	

	if(L > r  || R < l) return;
	else if(L >= l and  R <= r){
		
		segTree[node].change += 1;
		return;
	}
	int mid = (L+R)/2;

	update(node*2, L, mid, l, r);
	update(node*2+1, mid+1, R, l, r);


}


/*........................start.............................*/
void solve(){


	int t;
	cin>>t;
	int tCase = 1;

	while(t--){
		cout<<"Case "<<tCase++<<": "<<endl;
		string s;
		int q;
		cin>>s>>q;

		for(int I = 1; I<=s.length(); I++) arr[I] = s[I-1];

		build(1, 1, s.length());

		for(int I = 0; I<q; I++){
			char cmd;
			int i, j;
			cin>>cmd;
			
			if(cmd == 'I'){
				cin>>i>>j;
				update(1, 1, s.length(), i, j); 
			}else{
				cin>>i;
				int val = query(1, 1, s.length(), i, i, 0);
				if(val % 2 == 1){
					if(arr[i] == '0') cout<<"1"<<endl;
					else cout<<"0"<<endl;
				}else cout<<arr[i]<<endl;
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

