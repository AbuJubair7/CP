/*
Author: Jubair_7
Date: 7 June 2022
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
		ll first, remain, second, third;
		if(n%3 == 0){

			cout<<n/3<<" "<<n/3+1<<" "<<n/3-1<<endl;
		}else{
			
			first = n /3 + 1;
			second = n / 3;
			third = n/3-1;

			ll total = (first + second + third);
			ll dis = abs(total - n);
			
			if(dis == 1) first += 1;
			else{
				first += 1;
				second += 1;
			}

			
			cout<<second<<" "<<first<<" "<<third<<endl;

		}

	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
