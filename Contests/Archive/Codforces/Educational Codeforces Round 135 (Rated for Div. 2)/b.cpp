/*
Author: jubs
Date: 8 Sep 2022
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
		int n;
		cin>>n;

		if(n % 2 == 0){
			
			for(int i = 1; i<=n-2; i++){
				if(i % 2 == 0){
					cout<<i-1<<" ";
				}else{
					cout<<i+1<<" ";
				}
			}
			cout<<n-1<<" "<<n<<endl;
		
		}else{
			if(n > 5){
				cout<<"1 2 3"<<" ";
				for(int i = 4; i<=n-2; i++){
					if(i % 2 == 0){
						cout<<i+1<<" ";
					}else cout<<i-1<<" ";
				}
				cout<<n-1<<" "<<n<<endl;
			}else{
				for(int i = 1; i<=n; i++){
					cout<<i<<" ";
				}
				cout<<endl;
			}
		}


		
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}

