/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 27 Aprl 2023
*/



#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;



/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	

	while(t--){
		int n, k;
		cin>>n>>k;

		int pos = 0;
		int neg = 0;

		int total = 0;

		if(k == 0){
			if(n == 2) {
				cout<<"YES"<<endl;
				cout<<"1 - 1"<<endl;
			}
			else cout<<"NO"<<endl; 

		}else{
			int i = 1;
			pos = 1;
			total = 0;
			while(total <= k and pos+neg <= n){
				
				pos++;
				int tmp = (i*(i-1)) / 2;
				total += tmp;
				i++;
			}

			if(pos + neg == n){
				cout<<
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




