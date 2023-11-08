/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 12 May 2023
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
		string s;
		cin>>s;

		int ok = 0;

		for(int i = 1; i<s.length()/2; i++){
			if(s[i] != s[i-1]){
				ok = 1;
				break;
			}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
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




