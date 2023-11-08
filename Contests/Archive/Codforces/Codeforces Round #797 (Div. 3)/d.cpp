/*
Author: Jubair_7
Date: 10 June 2022
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
		
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;

		int need = 0;
		for(int i = 0; i<k ;i++){
			if(s[i] == 'W') need++;
		}

		int tempNeed = need;

	

		for(int i = k; i<n; i++){
			if(s[i] =='W') tempNeed++;
			if(s[i-k] == 'W') tempNeed--;

			need = min(tempNeed, need);

		}

		cout<<need<<endl;


     }
}

int main(){
	BOOST;
	solve();

	return 0;
}
