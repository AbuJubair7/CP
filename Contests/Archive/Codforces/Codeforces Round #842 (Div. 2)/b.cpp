/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 5 Jan 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5*2 + 5;


void solve(){

	int t;
	int tCase = 1;

	cin>>t;

	while(t--){
		int n, k;
		cin>>n>>k;
		int sortedMin = 0;
		int counter = 1;
		for(int i = 1; i<=n; i++){
			int x;
			cin>>x;
			if(x == counter){
				counter++;
				sortedMin++;
			}
		}
		
		int remain = n - sortedMin;

		if(remain % k == 0) cout<< remain/ k<<endl;
		else cout<<remain/k + 1<<endl;

		
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