/*
Author: Jubair_7
Date: 3 June 2022
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
        if(n%2 != 0) {
            if(n > 1) {
                cout<<"1"<<endl;;
            }
            else {
                cout<<"3"<<endl;
            }
        }
        else {
            for(int i = 0; i<31; i++){

            	if(((int)pow(2, i) & n) > 0){
            		if(pow(2, i) == n){
            			int ans = pow(2, i) + 1;
            			cout<<ans<<endl;
            			break;
            		}else {
            			int ans = pow(2, i);
            			cout<<ans<<endl;
            			break;
            		}
            	}
            }
        }
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
