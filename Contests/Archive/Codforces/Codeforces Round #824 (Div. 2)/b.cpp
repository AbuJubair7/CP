/*
Author: jubs
Date: 2 Oct 2022
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

ll steps(ll a, ll sqr){
	cout<<"a: "<<a<<endl;
	ll stp = 0;
	if(a >= sqr){
		cout<<"steps: increase 1"<<endl;
		stp++;
		stp +=steps(a/2, sqr);
		stp +=steps(a - (a/2), sqr);
	}
	return stp;
}

/*........................start.............................*/
void solve(){
	ll t;
	cin>>t;

	while(t--){
		
		ll n;
		cin>>n;
		vector<ll> v(n);

		FOR(i, n) cin>>v[i];

		ll sqr = (v[0] * 2)-1;
		ll ans = 0;
		//cout<<v[0] * 2<<endl;
		if(sqr == 1){
			for(ll i = 1; i<n; i++)
				ans += (v[i]-1);
		}else{
			for(ll i = 1; i<n; i++){
				if(v[i] > sqr){
					
					if(sqr+1 == v[i]) ans++;
					else if(v[i]%sqr == 0) ans += (v[i]/sqr - 1);
					else ans += (v[i] / sqr);
					//cout<<"for: "<<v[i]<<" divided into: "<<v[i]/sqr<<endl;
				}
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

