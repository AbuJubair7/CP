/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 20 Nov 2022
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*........................start.............................*/
void build(ll node, ll arr[], ll sgTree[], ll b, ll e){
	if(b == e){
		sgTree[node] = arr[b];
		return;
	}

	ll mid = (b+e)/2;

	build(node*2, arr, sgTree, b, mid); // left
	build(node*2+1, arr, sgTree, mid+1, e ); // right

	sgTree[node] = sgTree[node*2] + sgTree[node*2+1];
}

void update(ll node, ll sgTree[], ll b, ll e, ll i, ll newVal){

	if(i > e || i < b )
		return;
	if(b == i && e == i){
		sgTree[node] = newVal;
		return;
	}
	
	ll mid = (b+e)/2;

	update(node*2, sgTree, b, mid, i, newVal);
	update(node*2+1, sgTree, mid+1, e, i, newVal);

	sgTree[node] = sgTree[node*2] + sgTree[node*2+1];

}


ll rangeSum(ll node, ll sgTree[], ll b, ll e, ll i, ll j){
	if(i > e || j < b){
		return 0;
	}
	if(b >= i && e <= j){
		return sgTree[node];
	}
		

	ll mid = (b+e)/2;
	
	return rangeSum(node*2, sgTree, b, mid, i, j) + rangeSum(node*2+1, sgTree, mid+1, e, i, j);
}





int main(){
	
	ll t;
	cin>>t;
	ll tCase = 1;
	while(t--){
		cout<<"Case "<<tCase++<<":"<<endl;
		ll n, q;
		cin>>n>>q;

		ll arr[n];
		ll sgTree[n*4] = {0};

		for(ll i = 0; i<n; i++)
			cin>>arr[i];

		ll b = 0;
		ll e = n-1;

		build(1, arr, sgTree, b, e);

		for(ll i = 1; i<=q; i++){
			ll x;
			cin>>x;

			if(x == 1){
				ll ind;
				cin>>ind;
				cout<<arr[ind]<<endl;
				arr[ind] = 0;
				update(1, sgTree, b, e, ind, 0);
				
			}else if(x == 2){
				ll ind, val;
				cin>>ind>>val;
				arr[ind] += val;
				val = arr[ind];
				update(1, sgTree, b, e, ind, val);
				
				

			}else{
				ll ind1, ind2;
				cin>>ind1>>ind2;
				cout<<rangeSum(1,sgTree, b, e, ind1, ind2)<<endl;				
			}
		}

	}


	
	return 0;
}
