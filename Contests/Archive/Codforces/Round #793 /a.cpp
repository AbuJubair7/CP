/*
Author: Jubair_7
Date: 22 May 2022
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
		string s;
		cin>>s;
		
		if(n == 3){
			if(s[0] == s[1]){
				cout<<3<<endl;
			}else{
				cout<<1<<endl;
			}
		}else if(n == 2){
			cout<<2<<endl;
		}else{
			ll mid = 0;
			
			if(n%2 == 0){
				mid = n / 2;
			}else{
				mid = n / 2 + 1;
			}
			char m = s[mid-1];
			ll similar = 1;
			for(ll i = mid-1; i>=1; i--){
				if(m == s[i-1]){
					similar++;
				}else{
					break;
				}
			}
			for(ll i = mid-1; i<n-1; i++){
			
				if(m == s[i+1]){
					similar++;
				}else{
					break;
				}
			}

			cout<<similar<<endl;

			
		}
	}
}

int main(){

	solve();
	return 0;
}
