/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 20 Nov 2022
*/
#include <bits/stdc++.h>
using namespace std;


/*........................start.............................*/
struct SegmentTree{
	void init(int node, int arr[], int tree[], int b, int e){
		if(b == e){
			tree[node] = arr[b];
			return;
		}

		init(node*2, arr, tree, b, (b+e)/2);
		init(node*2+1, arr, tree, ((b+e)/2)+1, e);

		tree[node] = tree[node*2] <= tree[node*2+1] ? tree[node*2] : tree[node*2+1];
	}

	int findMinQuery(int node, int tree[], int b, int e, int i, int j){
		if(i > e || j < b){
			return INT_MAX;
		}

		if(b >= i && e <= j){
			return tree[node];
		}

		int n1= findMinQuery(node * 2, tree, b, (b+e)/2, i, j);
		int n2 = findMinQuery(node*2+1, tree, ((b+e)/2)+1, e, i, j);

		return n1 <= n2 ? n1 : n2;
	}
};



int main(){
	
	int t;
	cin>>t;
	int tCase = 1;
	while(t--){
		int n, q, i, j;
		cin>>n>>q;

		int arr[n] = {0};
		for(int in = 0; in<n ; in++){
			cin>>arr[in];
		}
		int tree[3 * n] = {0};

		SegmentTree st;
		st.init(1, arr, tree, 0, n-1);
		
		cout<<"Case "<<tCase++<<":\n";
		for(int k = 0; k<q; k++){
			cin>>i>>j;
			cout<<st.findMinQuery(1, tree, 0, n-1, i-1, j-1)<<endl;
		}

	
	}


	
	return 0;
}
