/*
Author: jubs
Date: 6 sep 2022
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
		
		ll n,m ;
		cin>>n>>m;

		if(m >= n){
			if(n == 1) {
				cout<<"Yes"<<endl;
				cout<<m<<endl;

			}
			else if(n == m){
				cout<<"Yes"<<endl;
				for(int i = 1; i<=n; i++)
					cout<<1<<" ";
				cout<<endl;
			}else{
				if(m % n == 0){
					cout<<"Yes"<<endl;
					for(int i = 1; i<=n ;i++){
						cout<<m/n<<" ";
					}
					cout<<endl;
				}else if(n % 2 != 0){
					cout<<"Yes"<<endl;
					for(int i = 1; i<n; i++){
						cout<<1<<" ";
					}
					cout<<m-n+1<<endl;

				}else{
					if(m % 2 == 0){
						cout<<"Yes"<<endl;
						for(int i = 1; i<n-1; i++){
							cout<<1<<" ";
						}
						int x = (m - (n-2))/2;
						cout<<x<<" "<<x<<endl;
					}else cout<<"No"<<endl;
				}
			}
			
		}else cout<<"No"<<endl;
			
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

