#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int mx = 1e5 * 2 + 5;
static int arr[mx];
static ll segArr[(int)sqrt(mx) + (int)sqrt(mx)];
 
void build(int arr[], int n){
	memset(segArr, 0, sizeof segArr);
	int sqr = sqrt(n);
	int segment = -1;
 
	for(int i = 0; i<n; i++){
 
		if(i % sqr == 0)
			segment++;
 
		segArr[segment] += arr[i];
	}
}
 
ll query(int l, int r, int n){
 
	int sqr = sqrt(n);
	ll sum = 0;
 
	while(l < r and l % sqr != 0){
		sum += arr[l];
		l++;
	}
 
	while(l + sqr <= r){
		sum += segArr[l/sqr];
		l += sqr;
	}
 
	while(l<=r){
		sum += arr[l];
		l++;
	}
 
	return sum;
}
 
 
void update(int n, int i, int val){
	int sqr = sqrt(n);
	int segment = i/sqr;
 
	segArr[segment] -= arr[i];
	segArr[segment] += val;
	arr[i] = val;
}
 
void solve(){
	int n, q;
	cin>>n>>q;
 
	for(int i = 0; i<n; i++) cin>>arr[i];
	build(arr, n);
 
	for(int i = 0; i<q; i++){
		int a, b;
		cin>>a>>b;
		a--; b--;
		cout<<query(a, b, n)<<endl;
	}
}
 
 
int main(){
 
	solve();
 
	return 0;
}