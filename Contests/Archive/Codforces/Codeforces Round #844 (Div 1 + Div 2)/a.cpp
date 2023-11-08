/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 15 Jan 2022
*/

#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs
typedef long long ll;

const int mx = 1e5 + 5;

void solve(){

	int t;
	cin>>t;

	while(t--){
		
		int w, d, h, a, b, f, g;
		cin>>w>>d>>h>>a>>b>>f>>g;

		int ans = abs(a-f) + abs(b-g);

		int minDis = abs(a-w);
		minDis = min(minDis, abs(b-d));

		minDis = min(minDis, abs(f-w));
		minDis = min(minDis, abs(g-d));

		minDis = min(minDis, min(a,b));
		minDis = min(minDis, min(f, g));
		

		ans += (2 * minDis);
		ans += h;
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