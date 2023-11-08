/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 6 May 2023
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
		int n;
		cin>>n;

		int one = INT_MAX;
		int two = INT_MAX;
		int all = INT_MAX;

		for(int i = 0; i<n; i++){
			int m, x;
			cin>>m>>x;
			
			if(x == 1){
				two = min(two, m);
			}else if(x == 10){
				one = min(one, m);
			}else if(x == 11){
				all = min(all, m);
			}
		}

		if((one == INT_MAX || two == INT_MAX) && all == INT_MAX)
			cout<<-1<<endl;
		else{

			int total = INT_MAX;

			if(one != INT_MAX and two != INT_MAX)
				total = one + two;

			total = min(all, total);
			cout<<total<<endl;
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




