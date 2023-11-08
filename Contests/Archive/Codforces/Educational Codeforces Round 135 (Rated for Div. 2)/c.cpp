/*
Author: jubs
Date: 10 Sep 2022
*/


#include <bits/stdc++.h>
using namespace std;

#define BOOST   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR(i,n) for(ll i = 0 ; i<n ; i++)
#define endl "\n"

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
		priority_queue<ll> q1;
		priority_queue<ll> q2;

		for(int i = 0; i<n; i++){
			ll x;
			cin>>x;
			q1.push(x);
		}

		for(int i = 0; i<n; i++){
			ll x;
			cin>>x;
			q2.push(x);
		}

		int ans = 0;
		while(!q1.empty()){
			if(q1.top() == q2.top()){
				q1.pop(); q2.pop();
			}else{
				ans++;

				if(q1.top() > q2.top()){
					int x = floor(log10(q1.top())) + 1;
					q1.push(x);
					q1.pop();
					
				}else{
					int x = floor(log10(q2.top())) + 1;
					q2.push(x);
					q2.pop();
					
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

