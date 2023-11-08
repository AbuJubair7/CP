/*
Author: jubs
Date: 21 Sep 2022
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
		
		ll n,x,y;
		cin>>n>>x>>y;

		if(x and y) cout<<-1<<endl;
		else{
			if(x > 0){
				if((n-1) % x == 0){
					
					int count = 1;
					int ans = 2;

					while(count <= n-1){
						for(int j = 1; j<=x; j++){
							cout<<ans<<" ";
							count++;
						}
						ans = count+1;;
					}
					cout<<endl;
					
				}else{
					cout<<-1<<endl;
				}
			}else{
				if( y > 0 and (n-1) % y == 0){
					

					int count = 1;
					int ans = 2;

					while(count <= n-1){
						for(int j = 1; j<=y; j++){
							cout<<ans<<" ";
							count++;
						}
						ans = count+1;;

					}
					
					cout<<endl;
				}else{
					cout<<-1<<endl;
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

