
#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const int mx = 1e5+5;
static int arr[mx];
int n;

int findMin(int i){

	if(i > n) return INT_MAX;

	return min(arr[i], findMin(i+1));
}

int findMax(int i){

	if(i > n) return INT_MIN;

	return max(arr[i], findMax(i+1));
}

/*........................start.............................*/
void solve(){

	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>arr[i];
	}

	cout<<findMin(1)<<endl;
	cout<<findMax(1)<<endl;
	
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

