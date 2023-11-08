/*
Author: Jubair_7
Date: 31 May 2022
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
	
	long long t, n, a[57], res;
	 cin>>n;
        for(int i = 1; i <= n; i++) cin>>a[i];
        res = 0;
        for(int i = 1; i <= n; i++) res += a[i]-1;
        if(res%2) cout<<"errorgorn"<<endl;
        else cout<<"maomao90"<<endl;
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
