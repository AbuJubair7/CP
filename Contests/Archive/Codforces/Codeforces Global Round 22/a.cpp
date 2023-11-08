/*............................
Author: jubs
Date: 30 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

 int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
 int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

typedef long long ll;

ll mod = 1e9+7;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b , a % b);
}

ll lcm(ll a,  ll b){
	return (a*b)/gcd(a,b);
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		
		ll n;
		cin>>n;
		vector<ll> fire;
		vector<ll> frost;

		ll a[n];
		ll b[n];

		FOR(i, n)cin>>a[i];
		FOR(i, n) cin>>b[i];

		FOR(i, n){
			if(a[i] == 0) fire.pb(b[i]);
			else frost.pb(b[i]);
		}

		sort(fire.begin(), fire.end(), greater<ll>());
		sort(frost.begin(), frost.end(), greater<ll>());



		ll ans = 0;
		ll ans2 = 0;

		if(fire.size() == frost.size()){
			for(ll i = 0; i<fire.size(); i++){
				ans += (2 * fire[i]);
				ans += (2 * frost[i]);
			}

			if(fire[fire.size() - 1] < frost[frost.size() - 1]){
				ans -= fire[fire.size()-1];
			}else ans -= frost[frost.size()-1];

		}else if(fire.size() > frost.size()){
			ll i = 0;
			ll j = 0;
			for(i = 0; i<frost.size(); i++){
				ans += (2 * frost[i]);
				ans += (2 * fire[i]);
				j++;
			}

			for(j ; j<fire.size(); j++){
				ans += fire[j];
			}
		}else{

			ll i = 0;
			ll j = 0;
			for(i = 0; i<fire.size(); i++){
		
				ans += (2 * frost[i]);
				ans += (2 * fire[i]);
				j++;
				
			}
		
			for(j ; j<frost.size(); j++){
	
				ans += frost[j];
			}
		}

		cout<<ans<<endl;

	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

