#include<bits/stdc++.h>
using namespace std;
 
#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;
 
const int mx = 1e5 * 2 + 5;
static ll arr[mx];
static ll segArr[mx];
 
void build(ll arr[], int n){
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
 
 
void update(int n, int i, ll val){
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
		int cmd, k, a, b;
		ll u;
		cin>>cmd;
 
		if(cmd == 1){
			cin>>k>>u;
			k--;
			update(n, k, u);
		}else{
			cin>>a>>b;
			a--; b--;
			cout<<query(a, b, n)<<endl;;
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