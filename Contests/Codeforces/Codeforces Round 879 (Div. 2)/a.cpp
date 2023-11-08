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
		int n;
		cin>>n;

		int neg = 0;
		int pos = n;
		int ans = 0;

		for(int i = 0; i<n; i++){
			int x;
			cin>>x;

			if(x < 0){
				neg++;
				pos--;
			}
				
		}

		if(neg > pos){
			int dis = ceil(n/2.0f);
			//cout<<dis<<endl;
			ans += (dis-pos);
			pos = dis;
			neg = n-pos;

		
		}

		if(neg % 2){
			ans++;
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




