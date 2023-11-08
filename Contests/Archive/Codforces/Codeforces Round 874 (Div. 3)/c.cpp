/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 19 May 2023
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

		vector<int> even;
		vector<int> odd;

		for(int i = 0; i<n; i++){
			int x;
			cin>>x;

			if(x % 2) odd.pb(x);
			else even.pb(x);
		}

		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());

		if(even.size() == 0 || odd.size() == 0) cout<<"YES"<<endl;
		else{

			int e = even[0];
			int o = odd[0];

			if(e > o) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			
			

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




