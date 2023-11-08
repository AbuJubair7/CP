/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 3 Jan 2022
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
		int n;
		cin>>n;

		if(n % 2){
			if(n == 3) cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				int counter = n/2;
				for(int i = 1; i<=n; i++){
					if(i % 2) cout<<counter-1<<" ";
					else cout<<(counter)*(-1)<<" "; 
				}
				cout<<endl;
			}
		}else{
			cout<<"YES"<<endl;
			for(int i = 1; i<=n; i++){
				if(i%2) cout<<1<<" ";
				else cout<<1*(-1)<<" ";
			}
			cout<<endl;
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