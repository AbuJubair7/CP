/*............................
Author: Jubair_7
Date: 7 Oct 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back
//#define jubs

typedef long long ll;

const ll value = 1e8;

bool status[value];
vector<ll> primes;

void seive(ll n){
	ll sq = sqrt(n);
	primes.pb(2);

	for(ll i = 4; i<=n; i += 2)
		status[i] = 1;

	for(ll i = 3; i<=sq; i+=2){

		if(!status[i]){
			primes.pb(i);
			for(ll j = i*i; j<=n; j += i)
				status[j] = 1;
		}
	}

	for(ll i = sq+1; i<=n ;i++){
		if(!status[i]){
			primes.pb(i);
		}
	}
}
/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;
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

