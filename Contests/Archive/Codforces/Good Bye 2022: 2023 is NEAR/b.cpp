/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 30 Dec 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;
const int mx = 1e5  + 1;



/*........................start.............................*/
void solve(){

	int t;
	cin>>t;
	int tCase = 1;
	

	while(t--){
		
		int n,k;
		cin>>n>>k;

		int i = 1;
		int j = n;
		
		if(n % 2 == 1){
			
			while(i < j){
				 cout<<j--<<" "<<i++<<" ";
			}
			cout<<(n/2)+1<<" ";
		}else{
			while(i <= j) cout<<j--<<" "<<i++<<" ";
		}
		cout<<endl;
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




