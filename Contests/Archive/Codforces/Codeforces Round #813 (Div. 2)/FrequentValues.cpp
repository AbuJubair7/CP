/*
Author: jubair
Date: 16 Aug 2022
*/
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
	return (a*b)/gcd(a,b);
}

void build(int node, pair<int, int> segTree[], int arr[], int b, int e){
	if(b == e){
		segTree[node] = {arr[b], 1};
		return;
	}

	int mid = (b+e)/2;
	build(node*2, segTree, arr, b, mid);
	build(node*2+1, segTree, arr, mid+1, e);

	pair<int, int> left = segTree[node*2];
	pair<int, int> right=  segTree[node*2+1];

	if(left.first == right.first){
		segTree[node] = {left.first, (left.second+right.second)};

	}else if(left.second > right.second){

		segTree[node] = left;

	}else{
		segTree[node] = right;
	}


}

int query(int node, pair<int, int> segTree[], int arr[], int b, int e, int i, int j){
		if(b > j || e < i)
			return 0;
		if(b >= i && e<= j){
			return segTree[node].second;
		}

		int mid = b+e/2;

		int left = query(node*2, segTree, arr, b, mid, i, j);
		int right = query(node*2+1, segTree, arr, mid+1, e, i, j);

		return max(left, right);
	}


/*........................start.............................*/
void solve(){
	
	int n, q;
	cin>>n;
	//cout<<n<<endl;
	while(n){
		cin>>q;
		//cout<<n<<" "<<q<<endl;

		int arr[n];
		for(int i = 0; i<n; ++i){
			cin>>arr[i];
		}
		pair<int, int> segTree[n*3];

		build(1, segTree, arr, 0, n-1);
		cout<<segTree[1].second<<endl;
		cout<<segTree[1].first<<endl;

		for(int i = 1; i<20; i++){
			cout<<"node: "<<i<<"-->"<<segTree[i].first<<": "<<segTree[i].second<<endl;
		}

		for(int i = 1; i<=q; i++){
			int a, b;
			cin>>a>>b;
			//cout<<query(1, segTree, arr, 0, n-1, a-1, b-1)<<endl;
		}
		cin>>n;


	}
}

int main(){
	BOOST;
//	solve();
	map<int, int> map1;
	map1[1] = 1;

	map<int, int> map2;
	map2[1] = 2;

	map1.insert(map2.begin(), map2.end());
	cout<<map1[1]<<endl;
	//cout<<"hi"<<endl;
	return 0;
}
