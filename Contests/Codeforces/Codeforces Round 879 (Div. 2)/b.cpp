/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 18 June 2023
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
		string l, r;
		cin>>l>>r;

		ll ans = 0;

		if(l.length() == r.length()){
			ll diff = 0;

			for(int i = 0; i<l.length(); i++){
				if(l[i] != r[i]){
					diff = i+1;
					break;
				}
			}

			if(diff){
				ll need = l.length() - diff;
				need *= 9;

				need += abs(l[diff-1]-r[diff-1]);
				ans += need;
			}

		}else{
			ll extra = r.length()-l.length();
			ans += (9 * l.length());

			ans += (9 * (extra-1));

			ans += (r[0] - '0');
		}

		cout<<ans<<endl;
		
			
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




