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

		string s;
		cin>>s;


		int ok = 0;
		int ind = 0;

		vector<int> right;
		vector<int> left;

		for(int i = 0; i<n; i++){
			if(s[i] == 'R') right.pb(i);
			else left.pb(i);
		}

		if(right.size() > 0 and left.size() > 0){
			if(right[0] < left [0]) ok = 1;
			else{
				for(int i = 0; i<n-1; i++){
					if(s[i] == 'L' and s[i+1] == 'R'){
						ind = i+1;
						ok = 1;
						break;
					}
				}
			}

		}else ok = 0;
		

		if(ok){
			if(ind) cout<<ind<<endl;
			else cout<<0<<endl;
		}else cout<<-1<<endl;

		
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