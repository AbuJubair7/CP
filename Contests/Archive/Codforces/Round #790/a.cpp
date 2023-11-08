/*
Author: Jubair_7
Date: 10 May 2022
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
		string s;
		cin>>s;

		if((stoi(to_string(s[0])) + stoi(to_string(s[1])) + stoi(to_string(s[2])) ==
			stoi(to_string(s[3])) + stoi(to_string(s[4])) + stoi(to_string(s[5]))))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
