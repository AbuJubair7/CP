/*
Author: jubs
Date: 25 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"
#define pb push_back

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
		int n,c;
		cin>>n>>c;
		map<int, int> map;
		int ans = 0;

		for(int i = 1; i<=n; i++){
			int orbit;
			cin>>orbit;
			map[orbit]++;
			//cout<<map[orbit]<<endl;
		}

		for(auto i: map){
			if(i.second < c){
				ans += i.second;
			}else{
				ans += c;
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

