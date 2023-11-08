/*........... বিসমিল্লাহির রাহমানির রাহীম .................

Author: jubs
Date: 26 Jan 2022
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
		int a, b, c, d;
		int B,C;
		cin>>a>>b>>c>>d;
		B = b;
		C = c;

		// for max of (b,c) >= a
		// b-a
		// b >= c min happiness 0
		// b < c min happiness c-a
		// b > c remain joke b-c
		// c >= b remain joke 0

		// if max of(b,c) < a
		// min happiness a - abs(b-c)
		// remain joke  = 0
		
		if(b < c) swap(b, c);

		int happiness = a;
		int remainJoke = b+c+d;
		int ans = a;

		if(max(b, c) >= a){
			b -= a;
			if(b >= c) happiness = 0;
			else happiness = c-b;

			if(b > c) remainJoke = b-c;
			else remainJoke = 0;
		}else{
			happiness = a - abs(b-c);
			remainJoke = 0;
		}
		ans += (B+C-(remainJoke));


		int canTake = happiness+1;

		int extra = max(remainJoke, d);

		if(canTake <= remainJoke || canTake <= d) ans += canTake;
		else{
			int totalRemain = d+remainJoke;

			if(totalRemain <= canTake) ans += totalRemain;
			else ans += canTake;
		}

		if(ans and !a) cout<<1<<endl;
		else cout<<ans<<endl;

		

		

		


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




