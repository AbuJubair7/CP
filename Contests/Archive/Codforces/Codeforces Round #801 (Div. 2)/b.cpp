/*
Author: Jubair_7
Date: 19 June 2022
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
		int n, p1, p2;
		cin>>n;
		

		ll arr[n];
		for(int i = 0;i<n; i++) cin>>arr[i];

		if(n % 2 != 0)cout<<"Mike"<<endl;
		else{
			ll mikeMin = INT_MAX;
			ll joeMin = INT_MAX;

			for(int i = 0;i<n; i++){
			
				if((i+1) % 2 == 0){
					if(arr[i] < joeMin){
						joeMin = arr[i];
					 	p2 = i+1;
					}
						
				}else{
					if(arr[i] < mikeMin){
							mikeMin = arr[i];	
						p1 = i+1;
					}
					

					
				}
			}
			if(mikeMin == joeMin) p1 < p2 ? cout<<"Joe"<<endl : cout<<"Mike"<<endl;
			else if(joeMin > mikeMin) cout<<"Joe"<<endl;
			else cout<<"Mike"<<endl;

			
			
			
			
		}

		




	
	}
}

int main(){
	BOOST;
	solve();
	return 0;
}
